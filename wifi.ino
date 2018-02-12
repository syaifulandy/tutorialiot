#include <WiFi.h>

const char* ssid     = "Tulis nama SSID yang digunakan";
const char* password = "Tulis password SSID";

void setup()
{
    Serial.begin(115200);
    delay(10);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    //Apakah sudah terhubung?
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      WiFi.begin(ssid, password);
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    delay(500);
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Reconnecting");
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
          WiFi.begin(ssid, password);
       }
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
    }
}

