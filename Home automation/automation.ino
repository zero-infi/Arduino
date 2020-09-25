#include <ESP8266WiFi.h>
#define OUTDOOR D2
#define LIGHT D4
const char* ssid = “WIFI NAME”;
const char* password = “######”;

WiFiServer server(80);


void setup() {
Serial.begin(115200);
pinMode(OUTDOOR, OUTPUT);
pinMode(LIGHT, OUTPUT);
digitalWrite(OUTDOOR,HIGH);
digitalWrite(LIGHT,HIGH);

Serial.println();
Serial.println();
Serial.print(“Connecting to “);
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(“.”);
}
Serial.println(“”);
Serial.println(“WiFi connected”);
server.begin();
Serial.println(“Server started”);
Serial.println(WiFi.localIP());
}

void loop() {
WiFiClient client = server.available();
if (!client) {
return;
}

Serial.println(“new client”);
while(!client.available())
{
delay(1);
}
String req = client.readStringUntil(‘\r’);
Serial.println(req);
client.flush();

if (req.indexOf(“/r2on”) != -1)  //switch on outdoor lights
{

digitalWrite(OUTDOOR,LOW);
Serial.println(“OUTDOOR ON”);
}
else if(req.indexOf(“/r2off”) != -1)   //switch off outdoor lights
{
digitalWrite(OUTDOOR,HIGH);
Serial.println(“OUTDOOR OFF”);
}

if (req.indexOf(“/r1on”) != -1) //switch on indoor lights
{
digitalWrite(LIGHT,LOW);
Serial.println(“LIGHT ON”);
}
else if(req.indexOf(“/r1off”) != -1)   //switch off indoor lights
{
digitalWrite(LIGHT,HIGH);
Serial.println(“LIGHT OFF”);
}
if (req.indexOf(“/allon”) != -1)   //switch on all lights
{
digitalWrite(LIGHT,LOW);
Serial.println(“LIGHT ON”);
digitalWrite(OUTDOOR,LOW);
Serial.println(“OUTDOOR ON”);
}
else if(req.indexOf(“/alloff”) != -1) //switchoff all lights
{
digitalWrite(LIGHT,HIGH);
Serial.println(“LIGHT OFF”);
digitalWrite(OUTDOOR,HIGH);
Serial.println(“OUTDOOR OFF”);
}
String web = “HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n”;

client.print(web);
}



