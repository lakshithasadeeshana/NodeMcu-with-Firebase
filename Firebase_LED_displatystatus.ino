#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
 
// Set these to run example.
#define FIREBASE_HOST "nodemcu-iot-a8e67.firebaseio.com"
#define FIREBASE_AUTH "qCdAFAdbQ4pK4ZJmOgW7nVy51LpQPJheX1WkMZBf"
#define WIFI_SSID "AF23-B9CC"
#define WIFI_PASSWORD "35L957Q7"
 
int led1; 
int LED = 5;

 
void setup()
{
  // Debug console
  Serial.begin(9600);

  // connect to wifi.
 pinMode(LED, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("Automation/Value/status","No Data");

}
 
void loop()
{
 
led1= Firebase.getInt("Automation/Value/LED1");
//led1= Firebase.getInt("Automation/Value/LED1");


if(Firebase.failed()){

   Serial.println(Firebase.error());
   
  }else{
    
    Serial.println(led1);
    
    }

if(led1==1){
  
  digitalWrite(LED,HIGH);
  Firebase.setString("Automation/Value/status","LED ON");
  
  }
  else{
    digitalWrite(LED,LOW);
    Firebase.setString("Automation/Value/status","LED OFF");
    }


    
            
}
