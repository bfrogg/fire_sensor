#include "driverlib.h"
#include "math.h"

void main_freq_config (void);
void gpio_config (void);
void timersA_init (void);
void wait_us (uint16_t us_val);
void delay_ms(unsigned int ms);
void ADC_init (void);
void UART_Init(void);
void UART_send(uint16_t symbol);

uint16_t ADC_measure (uint8_t channel);
volatile uint16_t a, b, a0, b0; 		// mes1, mes2, initial values
uint16_t i0 = 0, i1 = 0; 										// "FIRE" signal number

const double c0 = 1.5;								// magic numbers
const double c1 = 2.4;								// magic numbers
const uint16_t i0_condition = 10;
const uint16_t i1_condition = 40;
const uint16_t delta_a_treshold = 30;
const uint16_t delta2_b_treshold = 4;
const double delta_c0 = 0.1;
const double delta_c1 = 0.2;
double c_prev = 0;


void main(void) {

    WDTCTL = WDTPW | WDTHOLD;						// Stop watchdog timer
	main_freq_config();
	gpio_config();

	timersA_init ();
	wait_us(10000);
	ADC_init ();
	delay_ms(1000);
	P3OUT |= BIT2; 									//start emitter
	wait_us(20);

	a0 = ADC_measure(ADC10_B_INPUT_A6);				//it is PHAMP
	b0 = ADC_measure(ADC10_B_INPUT_A4); 			//it is PHAMP1

	P3OUT &= ~(BIT2); 								//shut down IRLED

	UART_Init();

	//P1OUT = BIT5;

	__bis_SR_register(GIE);

	while (1)
	{
		wait_us(1000);
	}

}

void main_freq_config (void)
{
    CS_setDCOFreq(CS_DCORSEL_0, CS_DCOFSEL_3); 												// Set DCO frequency to 8000000 Hz
    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);						// Setting MCLK source from CS_DCOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_1
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);						// Setting SMCLK source from CS_DCOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_1
    CS_initClockSignal(CS_ACLK, CS_VLOCLK_SELECT, CS_CLOCK_DIVIDER_1);						// Setting ACLK source from CS_VLOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_1.
	CS_clearAllOscFlagsWithTimeout (100000);												// Clears all oscillator fault flags including global oscillator fault flag																						// before switching clock sources
	CS_disableClockRequest(CS_MCLK);														// MCLK clock request disable. Clearing this disables conditional module requests for MCLK
}

void gpio_config (void)
{
	P1DIR = BIT5 | BIT1; 								//LED heartbeat
	P1OUT = 0;
	P3DIR = BIT2 | BIT4 | BIT3; 						//EMITTER, PHAMPEN, PAMPEN1
	P3OUT = 0;
	P3OUT |= (BIT4 | BIT3); 							//start OP warming

}

void timersA_init(void)
{
	//THREE SECOND TIMER - slow
	struct Timer_A_initUpModeParam TIMERA0_init_str =
	{
		TIMER_A_CLOCKSOURCE_ACLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_1,
		829,
		TIMER_A_TAIE_INTERRUPT_DISABLE,
	    TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
		TIMER_A_SKIP_CLEAR,
	    1
	};

	Timer_A_initUpMode(TIMER_A0_BASE, &TIMERA0_init_str);

	// fast continuous timer 1 step = 0.125us
	struct Timer_A_initContinuousModeParam TIMERA1_init_str =
	{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_1,
		TIMER_A_TAIE_INTERRUPT_DISABLE,
		TIMER_A_SKIP_CLEAR,
	    1
	};

	Timer_A_initContinuousMode(TIMER_A1_BASE, &TIMERA1_init_str);
}

#pragma vector = TIMER0_A0_VECTOR

__interrupt void TIMER0_A0_ISR_HOOK(void)
{
	//EVERY ONE SECOND DO
	int16_t delta_a, delta_b;
	double c, delta_c;

	P3OUT |= BIT2; 										//start emitter
	wait_us(20);

	a = ADC_measure(ADC10_B_INPUT_A6);					//it is PHAMP
	b = ADC_measure(ADC10_B_INPUT_A4); 					//it is PHAMP1

	P3OUT &= ~(BIT2); 									//shut down IRLED

	delta_a = a - a0;
	delta_b = b - b0;

	if (delta_a < 0 && delta_b < 0) {
		if (abs(delta_a) > delta_a_treshold) {
			c = delta_a/(delta_b + 0.00001);
			if ((c > c0) && (c < c1)) {
				delta_c = c - c_prev;
				if (delta_c < 0)
					delta_c *= -1;
				if (delta_c < delta_c0)
					i0++;
				else if ((delta_c >= delta_c0) && (delta_c < delta_c1)) {
					i1 = i0 + i1;
					i0 = 0;
					i1++;
				}
				else {
					i0 = 0;
					i1 = 0;
				}
			}
			c_prev = c;
			if (i0 == i0_condition || i1 == i1_condition)
				P1OUT |= BIT5;									//FIRE!!!
		}
	}

	//send values out over UART
	UART_send (a >> 8);
	UART_send (a & 0xFF);
	UART_send (b >> 8);
	UART_send (b & 0xFF);

	//double it
	UART_send (a >> 8 );
	UART_send (a & 0xFF);
	UART_send (b >> 8);
	UART_send (b & 0xFF);
}

void wait_us (uint16_t us_val)
{
	uint16_t tacts_to_wait = us_val * 8;

	TA1R = 0;
	Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_CONTINUOUS_MODE);
	while (TA1R < tacts_to_wait);
	Timer_A_stop(TIMER_A1_BASE);
}

void delay_ms(unsigned int ms)
{
	while (ms)
	{
		__delay_cycles(8000);
		ms--;
	}
}

void ADC_init (void)
{
    ADC10_B_init(ADC10_B_BASE, ADC10_B_SAMPLEHOLDSOURCE_SC, ADC10_B_CLOCKSOURCE_ADC10OSC, ADC10_B_CLOCKDIVIDER_1);	/* Initializes ADC10_B */
    ADC10_B_enable(ADC10_B_BASE);	  																				/* Enables ADC10_B */
    ADC10_B_setupSamplingTimer(ADC10_B_BASE, ADC10_B_CYCLEHOLD_16_CYCLES, ADC10_B_MULTIPLESAMPLESDISABLE);			/* Sets up and enables the Sampling Timer Pulse Mode */
    ADC10_B_configureMemory(ADC10_B_BASE, ADC10_B_INPUT_A0, ADC10_B_VREFPOS_AVCC, ADC10_B_VREFNEG_AVSS);			/* Configures the controls of the selected memory buffer */
    ADC10_B_setSampleHoldSignalInversion(ADC10_B_BASE, ADC10_B_NONINVERTEDSIGNAL);									/* Inverts/Uninverts the sample/hold signal */
    ADC10_B_setDataReadBackFormat(ADC10_B_BASE, ADC10_B_UNSIGNED_BINARY);											/* Sets the read-back format of the converted data */
    ADC10_B_setReferenceBufferSamplingRate(ADC10_B_BASE, ADC10_B_MAXSAMPLINGRATE_200KSPS);							/* Sets the reference buffer's sampling rate */
    ADC10_B_disableInterrupt(ADC10_B_BASE, ADC10IE0);																/* Disables interrupt ADC10IE0 */
    ADC10_B_disableInterrupt(ADC10_B_BASE, ADC10HIIE);																/* Disables interrupt ADC10HIIE */
    ADC10_B_disableInterrupt(ADC10_B_BASE, ADC10LOIE);																/* Disables interrupt ADC10LOIE */
    ADC10_B_disableInterrupt(ADC10_B_BASE, ADC10INIE);																/* Disables interrupt ADC10INIE */
}

uint16_t ADC_measure (uint8_t channel)
{
	ADC10_B_configureMemory(ADC10_B_BASE, channel, ADC10_B_VREFPOS_AVCC, ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion (ADC10_B_BASE,ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE));

	ADC10_B_disableConversions(ADC10_B_BASE,ADC10_B_COMPLETECONVERSION);
	return ADC10_B_getResults(ADC10_B_BASE);
}


void UART_Init(void)
{
	P2SEL1 |= BIT1 | BIT0;
	P2DIR |= BIT0;

	struct EUSCI_A_UART_initParam UART_init_struct =
	{
	    EUSCI_A_UART_CLOCKSOURCE_SMCLK,
		26,
	    0,
		214,
		EUSCI_A_UART_NO_PARITY,
	    EUSCI_A_UART_LSB_FIRST,
	    EUSCI_A_UART_ONE_STOP_BIT,
		EUSCI_A_UART_MODE,
		EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
	};

     /* initialize UART for 115200 baud (based on a 8000000 Hz clock) */
    if (STATUS_FAIL == EUSCI_A_UART_init(EUSCI_A0_BASE, &UART_init_struct))
        return;

    EUSCI_A_UART_enable(EUSCI_A0_BASE);    /* enable eUSCI UART */
    EUSCI_A_UART_selectDeglitchTime(EUSCI_A0_BASE, EUSCI_A_UART_DEGLITCH_TIME_200ns);    /* set deglitch time */
    EUSCI_A_UART_disableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_TRANSMIT_INTERRUPT);       /* disable eUSCI UART transmit interrupt */
    EUSCI_A_UART_disableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);   	 /* disable eUSCI UART receive interrupt */
}

void UART_send(uint16_t symbol)
{
	//do not forget SWITCHING PIN FOR MAX485

	EUSCI_A_UART_transmitData (EUSCI_A0_BASE, symbol);
	wait_us(550);
}
