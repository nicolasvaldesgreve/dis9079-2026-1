// enviarArduino
// placa se conecta a un servidor mosquitto
// y envia mensaje a un topic
// para ser recibido por otra placa
// y prender su led
// basado en ejemplo de la biblioteca
// ArduinoMqttClient - WiFi Simple Sender
// marzo 2026
// por montoyamoraga para disenoUDP

// importar bibliotecas
#include <ArduinoMqttClient.h>
#include <WiFiS3.h>

// wifi en lid
char ssid[] = "dis9079";
char pass[] = "75288273";

// declarar cliente
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

// direccion ip de la raspberry pi 5 que usamos
char broker[] = "192.168.0.100";
int port = 1883;



// intervalo de tiempo para enviar mensaje
// medido en ms
const long intervalo = 10000;

// variable para guardar el momento en que se envio
// el mensaje anterior
unsigned long momentoAnterior = 0;

int numeritoMensaje = 0;


// MODIFICAR
const char topic[] = "dis9079/solemne/1/aaron";
const char mqttId[] = "arduinoAaron";
const char mqttPass[] = "dis9079";



void setup() {
  // inicializar el puerto serial
  Serial.begin(9600);

  // conectarse a wifi
  Serial.print("conectandose a red ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // si falla, reintentar
    Serial.print(".");
    delay(5000);
  }

  Serial.println("te conectaste a la red!");

  // ID del cliente
  // cada cliente debe tener una ID unica
  // este cliente es la placa arduino
  mqttClient.setId(mqttId);

  // autenticacion con username y clave
  Serial.println(mqttId);
  mqttClient.setUsernamePassword(mqttId,mqttPass);

  Serial.print("tratando de conectarse al MQTT broker ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("conexion a MQTT fallida! codigo del error = ");
    Serial.println(mqttClient.connectError());

    delay(2000);
  }

  Serial.println("te conectaste al MQTT broker!");
  Serial.println();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alives which
  // avoids being disconnected by the broker
  mqttClient.poll();

  // to avoid having delays in loop, we'll use the strategy from BlinkWithoutDelay
  // see: File -> Examples -> 02.Digital -> BlinkWithoutDelay for more info
  unsigned long currentMillis = millis();

  if (currentMillis - momentoAnterior >= intervalo) {
    // save the last time a message was sent
    momentoAnterior = currentMillis;

    Serial.print("enviando mensaje al topic:");
    Serial.println(topic);
    Serial.print("numeritoMensaje ");
    Serial.println(numeritoMensaje);

    // enviar mensaje
    // la interfaz print puede ser usada para
    // definir los contenidos del mensaje
    mqttClient.beginMessage(topic);
    mqttClient.print("numeritoMensaje ");
    mqttClient.print(numeritoMensaje);
    mqttClient.endMessage();

    Serial.println();

    // toggle numerito
    if (numeritoMensaje == 0) {
      numeritoMensaje = 1;
    } else {
      numeritoMensaje = 0;
    }
  }
}
