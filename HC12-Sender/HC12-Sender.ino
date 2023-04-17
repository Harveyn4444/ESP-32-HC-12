#include <SoftwareSerial.h>
#include <Wire.h>
#define RXD2 16	//(RX2)
#define TXD2 17	//(TX2)
#define HC12 Serial2  //Hardware serial 2 on the ESP32


int variable1 = 1;//random variables that will get sent
int variable2 = 20;
int variable3 = 30;
int variable4 = 40;
int variable5 = 50;


void setup() {
  HC12.begin(9600, SERIAL_8N1, RXD2, TXD2); //Sets the HC-12 communication to 9600 baud, which is the factory default
  Serial.begin(9600);
  //pinMode(5, OUTPUT);
  //digitalWrite(5, LOW);  //Pin 5 gets written low when you want to change the settings of the HC-12 

}

void loop() {
variable1++; //Just increasing the values of the variables purely for testing
variable2++;
variable3++;
variable4++;
variable5++;
  //Uncomment the following lines if you want the remote to also send the analog input data to the serial monitor, to check if the data is being read properly
 // If you do, It will look the same as it should on the other end's serial monitor
 
  Serial.print(variable1);
  Serial.print(",");
  Serial.print(variable2);
  Serial.print(",");
  Serial.print(variable3); 
  Serial.print(","); 
  Serial.print(variable4);
  Serial.print(",");
  Serial.print(variable5);
  Serial.println("");
  
  HC12.print(variable1);//sends the variables
  HC12.print(",");
  HC12.print(variable2);
  HC12.print(",");
  HC12.print(variable3);//if you just need to send 2 variables,simply change this value and the following to 0
  HC12.print(",");
  HC12.print(variable4);
  HC12.print(",");
  HC12.print(variable5);//if you just need to send 4 variables,simply change this value to 0
//if you need 5 or less variables, disregard comments below, but keep the next line of code, it is essential
  HC12.println("");//you can add even numbers of variables, ex add 2, 4, 6 ...(so 3, 5, 7, 9... variables in total) before this line by adding a variable line, then a comma line, another variable line then a second comma line under the 5th variable line but before the println.  
//for the purpose of simplicity, it is easier to add in groups of 2, so that less modification is necessary on the 
//other end
//if you have more variables than you are using, change the variable to 0, as above explained, again for the 
//purpose of simplicity
// This change must be reflected on receiver end: see below
  delay(100);
}