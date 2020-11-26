#include <string.h>

#include <Tello.h>
#include <Tello.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>





const char* ssid = "TELLO-DC1779";
const char* password = "";

WiFiUDP Udp;
unsigned int localUdpPort = 8889;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

Tello tello;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  tello.takeoff();
    delay(5000);
    tello.up(30);
    delay(2000);
    tello.down(30);
    delay(2000);
    tello.land();
    //you have 5 seconds to save your tello before it takes off again
    delay(5000);
}
