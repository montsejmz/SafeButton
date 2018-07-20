void getgps(void){
   sendData( "AT+CGNSPWR=1",1000,DEBUG); 
   //sendData( "AT+CGPSINF=0",1000,DEBUG); 
}

String sendData(String command, const int timeout, boolean debug){
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
      return response;
    }    
}


String Ubicacion_a_mandar (String cadena){

  int cont =0;
  int i=0;
  String longitud, latitud, trash, coord;
  float longf, latf;
  
  while (cadena[i] !=3){
    if (cadena[i] == ','){
      cont++;
    }
    switch (cont){
      case 2: latitud += cadena[i];
      break;
      case 3: longitud += cadena[i];
      break;
      default: trash =cadena[i];
      break;
    }
    i++;
  }
  
  latf = latitud.toFloat();
  latf = latf/100;
  latitud = String(latf);

  longf = longitud.toFloat();
  longf = longf/100;
  longitud = String(longf);

  
  coord = latitud + "," + longitud;
  return coord;
}


