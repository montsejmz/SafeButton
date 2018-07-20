#include <SoftwareSerial.h>
SoftwareSerial SIM808(7,8);
String inChar;
String strData;

char aux_str[100];
//Contenido del sms que enviamos. \x1A corresponde al caracter de finalizacion
char sms[] = "hOLAP";

void setup() {
  // put your setup code here, to run once:

SIM808.begin(19200);
Serial.begin (19200);
delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:


  if (Serial.available()>0){
  /*  if(Serial.read()=='s')
    {
    mensaje_sms();
    }*/
      SIM808.write (Serial.read());
     GPS();
 }
  
  
  if (SIM808.available()>0){

//    inChar=SIM808.read();
//
//    Serial.print(String(inChar));
   Serial.write (SIM808.read());
   //GPS();
  }
   /*if (SIM808.available()>0){
Serial.println (SIM808.available());
*/

}
