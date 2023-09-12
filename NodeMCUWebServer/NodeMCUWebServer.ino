#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "LEB_EVO_COM";
const char* password = "satuduatiga";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);

  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("...");
  }

  Serial.println("");
  Serial.println(WiFi.localIP());

  server.on("/", []()
  {
    server.send(200, "text/html",
    "<html>\
    <head><title>WEB SERVER</title></head>\
    <body style='background-color:orange;'>\
    <h1>Web Server NodeMCU</h1>\
    <hr>\
    <h1><b style='color:blue'> Selamat Datang</b></h1>\
    <button style='background-color:blue'><a style='text-decoration:none; color:white' href='/hidup'>HIDUPKAN LAMPU</a></button>\
    </body>\
    </html>");
    digitalWrite(LED_BUILTIN, HIGH);
  });

  server.on("/hidup", []()
  {
    server.send(200, "text/html",
    "<html>\
    <head><title>WEB SERVER</title></head>\
    <body style='background-color:orange;'>\
    <h1>Web Server NodeMCU</h1>\
    <hr>\
    <h1><b style='color:blue'> Selamat Datang</b></h1>\
    <button style='background-color:red'><a style='text-decoration:none; color:white' href='/mati'>MATIKAN LAMPU</a></button>\
    </body>\
    </html>");
    digitalWrite(LED_BUILTIN, LOW);
  });

  server.begin();
}


void loop() {

  server.handleClient();


}
