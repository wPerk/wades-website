
//DESCRIPTION//
//This program functions as a tank that moves according to values transmitted
//  from two joysticks via radio frequency.
//The left joystick controls motor A and the right joystick controls motor B.
//Both motor A and motor B should be able to move forward and backward independently of
//  or simultaneously with each other.
//The battery level is displayed on a small OLED screen so that it
//  can be constantly monitored while in use. The OLED screen will
//  display other message types to help keep the user aware of the charge.
//
//Listens to: P1_Controller8
//
//This code is closest to completion: 1/5/2025

//NOTES//
//1. Though the pins are not defined or actually used in the code, the SCK, MISO,
//   and MOSI pins must still be connected to the Arduino boards in order for the
//   NRF24L01 transceivers to communicate.
//2. There is no need for the y-axis values unless I'm only using one joystick
//   I guess because the speed of each motor is already controlled by the y-position
//   of each joystick.
//3. DO NOT let battery charge drop below 80% Ex. If V_max = 12.5V, then V_min = 10.0V
//4. No other reading of sensors, mathematical calculations, or pin manipulation can go
//   on during the delay function, so in effect, it brings most other activity to a halt.

//ISSUES//
//1. Voltage reader more accurate (almost exact) while tank is plugged into USB port.
//2. Using one 'if', one 'else', and the rest as 'else if' statements, the motors
//   only listen to the first signal sent by the joystick(s). So if both joystick
//   are pulled backwards, both motors continue backwards until Arduino Uno is reset.
//3. Using all 'if' and one 'else' statements, none of the motors work at all.
//4. Using all 'while' loops, everything works accordingly, but something causes
//   component to freeze after a few signals. OLED looks corrupted, motors continue
//   in same direction last received, and serial monitor no longer prints data received.

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_ADDR   0x3C      //OLED display TWI address
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//PINS
//A5 = SCL (Green)
//A4 = SDA (Blue)
//
//SCK is pin 13 (Grey)
//MISO is pin 11 (Orange)
//MOSI is pin 12 (Yellow)
RF24 radio(7, 8);                     //CE (green), CSN (blue)
const byte address[6] = "00001";      //Establish communication channel

typedef struct {
  int xVal_L;
  int yVal_L;
  int swVal_L;
  int xVal_R;
  int yVal_R;
  int swVal_R;
} jVals;        //Define data type called 'jVals'

jVals j = {0};  //Create and initialize a structure variable with default values called 'j'

//Motor A (Left Motor)
int enA = 10;   //Purple
int in1 = 9;    //Yellow
int in2 = 6;    //Brown
//Motor B (Right Motor)
int enB = 5;    //Grey
int in3 = 4;    //Orange
int in4 = 3;    //White

//Define the minimum and maximum expected battery voltages
#define MIN_VOLTAGE 10.5                //Minimum acceptable battery voltage (in volts)
#define MAX_VOLTAGE 12.0                //Maximum battery voltage (in volts)

float R1 = 4700.0;                      //Resistor 1 in Ohms
float R2 = 3200.0;                      //Resistor 2 in Ohms
int a = 0;                              //Flag for function batteryStatus()
unsigned long lastUpdateTime = 0;       //Timer for non-blocking delays

void setup() {
  Serial.begin(9600);                   //Initiate serial monitor at 9600 baud
  radio.begin();                        //Initiate RF communication
  radio.openReadingPipe(0, address);    //Establish communication channel as read only
  radio.setPALevel(RF24_PA_MAX);        //Set power level for transceiver
  radio.startListening();               //Establish transceiver as a receiver

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   //Initialize display
  display.clearDisplay();                           //Clear display
  display.setTextSize(1);                           //Text size
  display.setTextColor(WHITE);                      //Text color
  display.setCursor(25,13);                         //Text position
  display.print("Hello, world!");                   //Text
  display.display();                                //Apply above to display

  delay(1000);                                      //Halt program for 1 second
  display.clearDisplay();                           //Clear previous text
  display.display();                                //Apply above to display

  //Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
    
void loop() {
  int value = analogRead(A0);                           //Read voltage from voltage divider circuit at A0
  float voltage = value * (5.0/1023)*((R1 + R2)/(R2));  //Convert voltage at A0 back to voltage from source
  float percentage = (voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE) * 100.0;   //Calculate the battery percentage
  percentage = constrain(percentage, 0.0, 100.0);                                     //Limit percentage to 0-100

  batteryStatus(voltage);
    
  if(radio.available()) {               //Check for available signals
    Serial.println("Receiving data...");
    radio.read(&j, sizeof(j));
    Serial.println("Data received successfully!");
    handleMotorControl();
  } else {
    Serial.println("No signal available.");
  }

  delay(50);
}

//Handles motor control logic based on joystick inputs
void handleMotorControl() {
  unsigned long currentTime = millis();

  //Map joystick values to motor speeds
  int speedAFx = map(j.xVal_L, 505, 0, 0, 200);
  int speedBFx = map(j.xVal_R, 517, 0, 0, 200);
  int speedABx = map(j.xVal_L, 505, 1023, 0, 200);
  int speedBBx = map(j.xVal_R, 517, 1023, 0, 200);

  //Handle different motor control cases
  if (j.xVal_L < 495 && j.xVal_R < 507) {                     //Both motors forward
    driveMotors(speedAFx, LOW, HIGH, speedBFx, HIGH, LOW);
  } else if (j.xVal_L > 515 && j.xVal_R > 527) {              //Both motors backward
    driveMotors(speedABx, HIGH, LOW, speedBBx, LOW, HIGH);
  } else if (j.xVal_L < 495 && j.xVal_R > 507) {              //Motor A forward and motor B backward
    driveMotors(speedAFx, LOW, HIGH, speedBBx, LOW, HIGH);
  } else if (j.xVal_L > 515 && j.xVal_R < 507) {              //Motor A backward and motor B forward
    driveMotors(speedABx, HIGH, LOW, speedBFx, HIGH, LOW);
  } else if (j.xVal_L < 495) {                                //Motor A forward
    driveSingleMotor(speedAFx, in1, in2);
  } else if (j.xVal_L > 515) {                                //Motor A backward
    driveSingleMotor(speedABx, in1, in2);
  } else if (j.xVal_R < 507) {                                //Motor B forward
    driveSingleMotor(speedBFx, in3, in4);
  } else if (j.xVal_R > 527) {                                //Motor B backward
    driveSingleMotor(speedBBx, in3, in4);
  } else {
    stopMotors();                                             //Both motors stationary
  }

  lastUpdateTime = currentTime;  //Update the timer
}

//Controls direction of both motors
void driveMotors(int speedA, int dirA1, int dirA2, int speedB, int dirB1, int dirB2) {
  digitalWrite(in1, dirA1);
  digitalWrite(in2, dirA2);
  analogWrite(enA, speedA);

  digitalWrite(in3, dirB1);
  digitalWrite(in4, dirB2);
  analogWrite(enB, speedB);
}

//Controls direction of a single motor
void driveSingleMotor(int speed, int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  analogWrite(enA, speed);
}

//Stops both motors
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

//Displays battery status
void batteryStatus(float x) {
  if(x <= 10.5) {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(15, 8);
    display.println("CHARGE");
    display.display();                                    //Apply above to display
  } else if(x <= 11.5) {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(15, 8);
    if(a == 1) {
      display.println("LOW");
    }
    else {
      display.println(x);
    }
    display.display();                                    //Apply above to display
    a = 1;
  } else {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(15, 8);
    display.println(x);
    display.display();                                    //Apply above to display
  }
}
