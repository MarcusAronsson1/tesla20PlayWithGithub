#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Smartcar.h>

const int fSpeed = 70; //70% of the full speed forward
const int bSpeed = -70; //70% of the full speed backward
const int lDegrees = -75; //degrees to turn left
const int rDegrees = 75; //degrees to turn right

BrushedMotor leftMotor(8, 10, 9);
BrushedMotor rightMotor(12, 13, 11);
DifferentialControl control(leftMotor, rightMotor);

SimpleCar car(control);
SoftwareSerial BTSerial = SoftwareSerial(14, 15);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // make sure your Serial Monitor is also set at this baud rate.
  pinMode(14,INPUT);
  pinMode(15,OUTPUT);
  BTSerial.begin(9600);
  //Dabble.begin(9600); //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
}

void loop() {
  //Dabble.processInput();  //this function is used to refresh data obtained from smartphone. Hence calling this function is mandatory in order to get data properly from your mobile.

  //if(BTSerial.available())
  //{
    //char input = BTSerial.read();
    char input = Serial.read();

    String inputS = 
    int speed1 = extraxtSpeed(inputS)
    int angle = extraxtAngle(inputS);
    if (input == '0')
  {
    car.setSpeed(fSpeed);
    car.setAngle(0);
  } 
  else if (input == '1')
  {
    car.setSpeed(bSpeed);
    car.setAngle(0);
  } 
  else if (input == '2')
  {
    car.setSpeed(fSpeed);
    car.setAngle(lDegrees);
  }
  else if (input == '3')
  {
    car.setSpeed(fSpeed);
    car.setAngle(rDegrees);
  }
  /*else 
  {
    car.setSpeed(0);
    car.setAngle(0);
  }*/

}
