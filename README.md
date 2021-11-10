# USART-char

<p align="justify">In this program, single 8-bit ASCII characters are received and transmitted continuously over USART.</p>

<p align="justify">There are certain instances where a microcontroller will need to communicate with an external peripheral or another microcontroller to transmit data. Similar to
human communication, communications between electronic devices have to follow certain rules in order to transmit data accurately and efficiently. The rules of communication or 
"protocols" differ based on the communication method used.</p>

<p align="justify">The ATmega32A has 3 primary communication devices built within it; USART, SPI, and TWI or I2C. Each device follows different protocols and has their own 
advantages and disadvantages.</p>

<p align="justify">USART or Universal Synchronous and Asynchronous serial Receiver and Transmitter is a full duplex receiver and transmitter device capable of both synchronous and
asynchronous operation. USART is the easiest communication device to understand and implement for beginners, and is usually the communication device that is used most in sensors and other external peripherals. While synchronous operation is possible, asynchronous operation (also called UART) is used more often due to the relative ease of implementation.</p>

<p align="justify">USART works by transmitting data as consecutive packages of size 7 to 13 bits called a frame. The size of a frame can be determined by the programmer by setting the relevant bits of the UCSRB and UCSRC registers. A frame can contain 0 to 8 or 9 bits of the user's data, along with other bits which are required for communication.</p>

<p align="justify">The TX pin of the transmitter should be connected to the RX pin of the receiver. When idle this data bus will be in a logic HIGH state. First a start bit is sent from the transmitter to inform the receiver that a transmission has begun. The start bit is usually a transition of the data bus from the idle HIGH state to a LOW state. This is followed by upto 9 data bits depending on the size of the frame specified. After the data bits, an optional parity bit can be transmitted as well. Finally, a stop bit is transmitted where the data bus moves back to a logic HIGH state indefinitely, ending the transmission.</p>

<p align="justify">In order to send data via USART, first the relevant register bits have to be set to configure and initialize the device as necessary. Afterwards, the data to be transmitted has to be simply loaded byte-by-byte onto the UDR register. The UDR register is a double-buffered register which can be read from or written to, depending on the function of the microcontroller as a reciever or transmitter respectively. As a transmitter, once a databyte has been loaded onto the UDR register, the microcontroller will immediately try to send it over the data bus and flush the UDR register. On the receiver's side, the microcontroller simply has to read the UDR register to extract the received databyte, following which the receiver's UDR register will be flushed in preparation for the arrival of the next byte of data. In this way, transmitting and receiving data over USART is simply a matter of writing to and reading from the UDR register.</p>

<p align="justify">Care should be taken when communicating between two devices that their baud rate be the same. The baud rate is a measurement of the speed of communication between the devices. If the baud rates of the devices do not match, the devices will be sending or receiving data faster or slower than the other device can handle, resulting in errors due to missing data. Generally a higher baud rate is better for faster communication, although faster transmission speeds could result in a higher chance of the misreading of data by the microcontroller. Lower baud rates are much better for stability. Additionally, for some forms of wireless communication, using a lower baud rate helps increase the range of communication between the two devices.</p>

<p align="justify">While USART is easy to use, reliable and is supported by many modules and peripherals, its main disadvantages are its relatively slow transmission speeds and inability of interfacing multiple devices on a single data line. Common devices that use USART for communication with a host microcontroller include the Neo line of GPS modules, the HC series of bluetooth and RF communication modules and most Wi-Fi modules.</p>
