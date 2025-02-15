
//Soldered Controller//

//DESCRIPTION//
//This program functions as a controller with two joysticks, left joystick controlling
//  the left motor (motor A) and the right joystick controlling the right motor (motor B).
//The controller transmits joystick values to the tank via radio frequency.
//
//Talks to: P1_Tank10
//
//This code is closest to completion: 1/5/2025
//
//Upload using "ATmega328P (Old Bootloader)" processor
//Also, verify code before uploading it.

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(4, 6);                     //CE (green), CSN (blue)
const byte address[6] = "00001";      //Establish communication channel
//SCK  is pin 13 (White)
//MOSI is pin 11 (Yellow)
//MISO is pin 12 (White)

//Left Joystick
const int VRy_L = A0;  //Green
const int VRx_L = A1;  //Blue
const int sw_L = 10;   //Yellow
//Right Joystick
const int VRy_R = A6;  //Green
const int VRx_R = A7;  //Blue
const int sw_R = 3;    //Yellow

typedef struct{
  int xVal_L;
  int yVal_L;
  int swVal_L;
  int xVal_R;
  int yVal_R;
  int swVal_R;
} jVals;        //Define data type called 'jVals'

jVals j = {0};  //Create and initialize a structure variable with default values called 'j'

void setup() {
  Serial.begin(9600);                   //Initiate serial monitor at 9600 baud
  radio.begin();                        //Initiate RF communication
  // if (!radio.begin()) {
  //   Serial.println("RF24 initialization failed!");
  //   while (1);                          //Halt execution if initialization fails
  // }
  radio.openWritingPipe(address);       //Establish communication channel as write only
  radio.setPALevel(RF24_PA_MAX);        //Set power level for transceiver
  radio.stopListening();                //Establish transceiver as a transmitter

  pinMode(sw_L, INPUT);       //Initiate switch on left joystick as an input
  digitalWrite(sw_L, HIGH);   //Turn on switch on left joystick
  pinMode(sw_R, INPUT);       //Initiate switch on right joystick as an input
  digitalWrite(sw_R, HIGH);   //Turn on switch on right joystick
}
    
void loop() {
  j.xVal_L = analogRead(VRx_L);   //Define variable that depends on x-axis value from left joystick
  j.yVal_L = analogRead(VRy_L);   //Define variable that depends on y-axis value from left joystick
  j.swVal_L = digitalRead(sw_L);  //Define variable that depends on switch position on left joystick
  j.xVal_R = analogRead(VRx_R);   //Define variable that depends on x-axis value from right joystick
  j.yVal_R = analogRead(VRy_R);   //Define variable that depends on y-axis value from right joystick
  j.swVal_R = digitalRead(sw_R);  //Define variable that depends on switch position on right joystick

  //Add serial debugging outputs here:
  Serial.print("Left Joystick - X: ");
  Serial.print(j.xVal_L);
  Serial.print(", Y: ");
  Serial.print(j.yVal_L);
  Serial.print(", Switch: ");
  Serial.println(j.swVal_L);

  Serial.print("Right Joystick - X: ");
  Serial.print(j.xVal_R);
  Serial.print(", Y: ");
  Serial.print(j.yVal_R);
  Serial.print(", Switch: ");
  Serial.println(j.swVal_R);

  // // Transmission Debugging
  // Serial.println("Transmitting...");
  // bool success = radio.write(&j, sizeof(j));     //Write signals
  // if (success) {
  //   Serial.println("Transmission successful!");
  // } else {
  //   Serial.println("Transmission failed!");
  // }

  radio.write(&j, sizeof(j));

  delay(50);
}
