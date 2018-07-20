int enviarAT(String ATcommand, char* resp_correcta, unsigned int tiempo)
{

  int x = 0;
  bool correcto = 0;
  char respuesta[100];
  unsigned long anterior;

  memset(respuesta, '\0', 100); // Inicializa el string
  delay(100);
  while ( mySerial.available() > 0) mySerial.read(); // Limpia el buffer de entrada
  mySerial.println(ATcommand); // Envia el comando AT
  x = 0;
  anterior = millis();
  // Espera una respuesta
  do {
    // si hay datos el buffer de entrada del UART lee y comprueba la respuesta
    if (mySerial.available() != 0)
    {
        respuesta[x] = mySerial.read();
        x++;
      // Comprueba si la respuesta es correcta
      if (strstr(respuesta, resp_correcta) != NULL)
      {
        correcto = 1;
      }
    }
  }
  // Espera hasta tener una respuesta
  while ((correcto == 0) && ((millis() - anterior) < tiempo));
  Serial.println(respuesta);

  return correcto;
}
