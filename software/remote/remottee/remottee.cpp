
#include <SoftwareSerial.h>


int x = 0;
int y = 0;
int x_cam = 0;


SoftwareSerial mySerial(10, 11);
String data;

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(A0,INPUT); // X
  pinMode(A1,INPUT); // Y


  pinMode(A2,INPUT); // X - 2nd Joystick

  Serial.println("Remote Joystick");


}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);

  x_cam = analogRead(A2);

  data += "X:";
  data += (String)x;
  data += "-Y:";
  data += (String)y;
  data += "_C:";
  data += (String)x_cam;

  Serial.println(data);

  Serial.println("Data Sent to Router");

  mySerial.println(data);

  delay(200);
  data = "";



  /*
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
 */


}

