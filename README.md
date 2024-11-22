# robotic-prosthetic-hand
glove with flex sensors to control prosthetic robotic hand wirelessly using HC_05 Bluetooth master-slave modules

first confifure the master-slave modules using AT commands while holding the power button at power up and making sure RX and TX pins are not connected at every step
the useful AT commands after you have uploaded an empty arduino file:
AT
AR+ORGL
AT+UART
AT+ADDR
AT+NAME
AT+BIND
AT+ROLE
AT+CMODE

use ? or = after the coommand to either inquire about the state or change the state respectively

after configuration you may upload the code files for transmit in the master arduino
and recieve file in the slave arduino

note: the analog signal can be any analog signal not necessarily flex pressure sensors

note: to connect flex sensors to arduino you need a voltage divider circuit which will tranform the change in the resistance value to a change in voltage which arduino analog pins can read

good luck!
