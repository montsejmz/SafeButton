void iniciar()
{
  enviarAT("AT+CPIN=\"1111\"", "OK", 1000);
  Serial.println("Conectando a la red...");
  delay (5000);

  //espera hasta estar conectado a la red movil
  while ( enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 0 )
  {
  }
  Serial.println("Conectado a la red.");
  enviarAT("AT+CLIP=1\r", "OK", 1000); // Activamos la identificacion de llamadas
  enviarAT("AT+CMGF=1\r", "OK", 1000); //Configura el modo texto para enviar o recibir mensajes
  enviarAT("AT+CNMI=2,2,0,0,0\r", "OK", 1000); //Configuramos el modulo para que nos muestre los SMS recibidos por comunicacion serie
  Serial.println("Preparado.");
}

void mensaje_sms(String respuesta)
{
  if (enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 1) //comprueba la conexion a la red
  {
    Serial.println("Enviando SMS...");
    enviarAT("AT+CMGF=1\r", "OK", 1000); //Comando AT para mandar un SMS
    sprintf(aux_str, "AT+CMGS=\"3313278601\"", strlen(sms)); //Numero al que vamos a enviar el mensaje
    //Texto del mensaje
    if (enviarAT(aux_str, ">", 10000) == 1)
    {
      enviarAT(respuesta, "OK", 10000);
    }
    Serial.println("SMS enviado");
  }
  else
  {

    iniciar();
  }
}
void llamar()
{
  if (enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 1) //Comprueba la conexion a la red
  {
    Serial.println("Realizando llamada...");
    enviarAT("ATDXXXXXXXXX;", "OK", 1000);
    delay(20000); // Espera 20 segundos mientras realiza la llamada
    enviarAT("ATH", "OK", 1000); // Cuelga la llamada
    Serial.println("Llamada finalizada");
  }
  else
  {

    iniciar();
  }
}
