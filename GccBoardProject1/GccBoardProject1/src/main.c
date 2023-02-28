/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#define F_CPU 20000000UL

#define CS1 (PB0)
#define CS2 (PB1)
#define CLR (PB3)
#define MOSI (PB5)
#define MISO (PB6)
#define SCK (PB7)



#define OUT_CS1				(DDRB |= _BV(CS1))
#define OUT_CS2				(DDRB |= _BV(CS2))

#define OUT_CLR				(DDRB |= _BV(CLR))

#define CS1_0		 (PORTB = PORTB & 0b11111110)
#define CS1_1	      (PORTB = PORTB | 0x01)

#define CS2_0		 (PORTB = PORTB & 0b11111101)
#define CS2_1	      (PORTB = PORTB | 0x02)

#define CLR_0		(PORTB = PORTB & 0b11110111)
#define CLR_1	    (PORTB = PORTB | 0b00001000)


#include <asf.h>




void Init_SPI_ADS131(void)
{
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPHA);//SPI activée, mode Maitre, PHASE=1, POL = 0, Horloge/8 soit 2,5Mhz
	SPSR =0x01; //SPI2X = 1
}


void Init_Entrees_Sortie (void)
{
	DDRB = DDRB|0b10110000 ;//SCK PB7, MOSI PB5, CS1 PB4 en sortie MISO PB6,en entrée
	
	OUT_CS1;
	CS1_1;
	OUT_CS2;
	CS2_1;
	OUT_CLR;
	CLR_1;
}


void Init_SPI_MAX5122(void)
{
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);//SPI activée, mode Maitre, PHASE=0, POL = 0, Horloge/8 soit 2,5Mhz
	SPSR =0x01; //SPI2X = 1
}

int main ()
{
	Init_Entrees_Sortie();
	Init_SPI_ADS131();
	while(1)
	{
		
	}
}