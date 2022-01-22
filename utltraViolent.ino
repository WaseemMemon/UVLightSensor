#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "Adafruit_VEML6070.h"
 
Adafruit_VEML6070 uv = Adafruit_VEML6070();

// Update these with values suitable for your network.
const char* ssid = "realme 3";
const char* password = "physics12";
const char* mqtt_server = "192.168.43.248";
const char* mqtt_user = "guest";
const char* mqtt_password = "guest";


WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[550];
int value = 0;

void setup_wifi() {
   delay(100);
  // We start by connecting to a WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
   
    if (client.connect(mqtt_password))
    {
      Serial.println("connected");
      client.subscribe("bmp180");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
} //end reconnect()
 
void setup() 
{
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server,1883);
  Serial.println("VEML6070 Test");
  uv.begin(VEML6070_1_T);  // pass in the integration time constant
}
 
 
void loop() 
{
   if (!client.connected()) {
    reconnect();
  }
  Serial.print("UV light level: "); 
  Serial.println(uv.readUV());
  sprintf(msg,"%i",uv.readUV());
  client.publish("iot/sensor/uvsensor", msg);
  delay(1000);
}
