
#include <SoftwareSerial.h>
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(10, 11); //SIM800L Tx & Rx is connected to Arduino #3 & #2
void setup()
{
//Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
Serial.begin(9600);
//Begin serial communication with Arduino and SIM800L
mySerial.begin(9600);
Serial.println("Initializing...");
delay(1000);
mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
updateSerial();
mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
updateSerial();
mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
updateSerial();
mySerial.println("AT+CREG?"); //Check whether it has registered in the network
mySerial.println("AT+CCLK?"); //Once the handshake test is successful, it will back to OK
updateSerial();
mySerial.println("AT+CLTS=1"); //Once the handshake test is successful, it will back to OK
updateSerial();
mySerial.println("AT+CLTS?");
updateSerial();
mySerial.println("AT&W");
updateSerial();
mySerial.println("AT+CCLK?");
updateSerial();
Serial.println("Please Power OFF the System Once...");
delay(10000);
}
void loop()
{
delay(29000);
mySerial.println("AT+CCLK?");
updateSerial();
}
void updateSerial()
{
delay(1000);
while (Serial.available())
{
mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
}
}
