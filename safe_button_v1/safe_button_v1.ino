#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial mySerial(7,8); 
String ubicacion;
char aux_str[100];
        
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600); 
  getgps();
}

void loop(){
   
   getgps();
   ubicacion= sendData( "AT+CGNSINF",1000,DEBUG);
   delay(1000);  

   String sms = "https://www.google.com.mx/maps/place/" + Ubicacion_a_mandar(ubicacion) ;
   mensaje_sms (sms);
}



