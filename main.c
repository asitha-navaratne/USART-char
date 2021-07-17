#define F_CPU 8000000UL

#include <avr/io.h>

void USART_INIT(void);
void USART_SEND(unsigned char character);
unsigned char USART_RECEIVE(void);

uint8_t UBRR = 51;						///< Value to be changed to specify the baudrate for the particular operating clock frequency.

int main(void){
	USART_INIT();
	unsigned char message;
	
	while(1){
		message = USART_RECEIVE();
		USART_SEND(message);
	}
}

/*!
 *	@brief Initialize USART.
 */

void USART_INIT(void){
	UCSRB |= (1<<TXEN)|(1<<RXEN);				///< Enable transmission and receiving over USART.
	UCSRC |= (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);		///< Select register UCSRC and set transmission character size to 8 bits.
	UBRRL = UBRR;						///< Set UBRR value for specified baudrate at specified frequency.
}

/*!
 *	@brief Transmit a character over USART.
 *	@param Character to be transmitted (unsigned char).
 */

void USART_SEND(unsigned char character){
	while(!(UCSRA & (1<<UDRE)));				///< Wait until data register is empty.
	UDR = character;					///< Load character to be transmitted to data register.
	while(!(UCSRA & (1<<TXC)));				///< Wait until transmission is complete.
}

/*!
 *	@brief Receive a character over USART.
 *	@return Character received (unsigned char).
 */

unsigned char USART_RECEIVE(void){
	while(!(UCSRA & (1<<RXC)));				///< Wait until data receiving is complete.
	return UDR;						///< Return contents of UDR register.
}
