# USART-char

<p align="justify">In this program, single 8-bit ASCII characters are received and transmitted continuously over USART.</p>

<p align="justify">There are certain instances where a microcontroller will need to communicate with an external peripheral or another microcontroller to transmit data. Similar to
human communication, communications between electronic devices have to follow certain rules in order to transmit data accurately and efficiently. The rules of communication or 
"protocols" differ based on the communication method used.</p>

<p align="justify">The ATmega32A has 3 primary communication devices built within it; USART, SPI, and TWI or I2C. Each device follows different protocols and has their own 
advantages and disadvantages.</p>

<p align="justify">USART or Universal Synchronous and Asynchronous serial Receiver and Transmitter is a full duplex receiver and transmitter device capable of both synchronous and
asynchronous operation. USART is the easiest communication device to understand and implement for beginners and is usually the one used most in sensors and other external 
peripherals. While synchronous operation is possible, as the name suggests, asynchronous operation is used more often due to the relative ease of implementation.</p>
