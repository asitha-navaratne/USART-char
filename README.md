# USART-char

<p align="justify">In this program, single 8-bit ASCII characters are received and transmitted continuously over USART.</p>

<p align="justify">There are certain instances where a microcontroller will need to communicate with an external peripheral or another microcontroller to transmit data. Similar to
human communication, communications between electronic devices have to follow certain rules in order to transmit data accurately and efficiently. The rules of communication or 
"protocols" differ based on the communication method used.</p>

<p align="justify">The ATmega32A has 3 primary communication devices built within it; USART, SPI, and TWI or I2C. Each device follows different protocols and has their own 
advantages and disadvantages.</p>

<p align="justify">USART or Universal Synchronous and Asynchronous serial Receiver and Transmitter is a full duplex receiver and transmitter device capable of both synchronous and
asynchronous operation. USART is the easiest communication device to understand and implement for beginners, and is usually the communication device that is used most in sensors and other external peripherals. While synchronous operation is possible, asynchronous operation (also called UART) is used more often due to the relative ease of implementation.</p>

<p align="justify">USART works by transmitting data as consecutive frames of size 7 to 13 bits. The size of a frame can be determined by the programmer by setting the relevant bits of the UCSRB and UCSRC registers. The TX pin of the transmitter should be connected to the RX pin of the receiver. When idle this data bus will be in a logic HIGH state. First a start bit is sent from the transmitter to inform the receiver that a transmission has begun. The start bit is usually a transition of the data bus from the idle HIGH state to a LOW state. This is followed by upto 9 data bits depending on the size of the frame specified. After the data bits, an optional parity bit can be transmitted as well. Finally, a stop bit is transmitted where the data bus moves back to a logic HIGH state indefinitely, ending the transmission.</p>
