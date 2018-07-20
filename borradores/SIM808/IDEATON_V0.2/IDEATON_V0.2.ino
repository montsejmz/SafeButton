/*
 * Created by Island
 * Modified by keen 
 * Date: 17/03/2017
 */
#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial mySerial(7,8); 
        
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600); 
  getgps();
}

void loop(){
   sendData( "AT+CGNSINF",1000,DEBUG);   
}

void getgps(void){
   sendData( "AT+CGNSPWR=1",1000,DEBUG); 
   sendData( "AT+CGPSINF=0",1000,DEBUG); 
}

void sendData(String command, const int timeout, boolean debug){
    String response = "";    
    mySerial.println(command); 
    delay(5);
    if(debug){
    long int time = millis();   
    while( (time+timeout) > millis()){
      while(mySerial.available()){       
        response += char(mySerial.read());
      }  
    }    
      Serial.println(response);
    }    
}
