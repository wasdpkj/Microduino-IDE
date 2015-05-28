/*************************************************** 
 * This is an example for the DFRobot Wido - Wifi Integrated IoT lite sensor and control node
 * Product Page & More info: http://www.dfrobot.com/index.php?route=product/product&product_id=1159
 * Designed specifically to work with the DFRobot Wido products:
 * 
 * The library is forked from Adafruit
 * 
 * Contributed by James
 * BSD license, all text above must be included in any redistribution
 * 
 ****************************************************/

/*
This example code is used to connect the Carriots cloud service (Official homepage: http://www.carriots.com).
 
 The device required is just:
 
 1. LM35 low cost temperature sensor or any device you used to upload data
 2. And Wido
 
 Note: Please don't forget to change the setting below before using!
 1. WLAN_SSID & WlAN_PASS 
 2. API_key
 3. Device ID 
 
 */


#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#define Wido_IRQ   7
#define Wido_VBAT  5
#define Wido_CS    10
#include "utility/debug.h"

Adafruit_CC3000 Wido = Adafruit_CC3000(Wido_CS, Wido_IRQ, Wido_VBAT,SPI_CLOCK_DIVIDER); // you can change this clock speed

// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

#define WLAN_SSID       "myNetwork"         // cannot be longer than 32 characters!
#define WLAN_PASS       "myPassword"        // For connecting router or AP, don't forget to set the SSID and password here!!


#define TCP_TIMEOUT      3000

#define API_key  "xxxxe435154399ffefc9926ee5279009733aef834e537dda67d6a12f76aexxxx"  
// Update Your API Key. To get your API Key, please check the link below
// For checking your API key, please login your carriots account.Then click -> My setting -> My account

#define DEVICE   "defaultDevice@username.username"       // Replace with the id_developer of your device
                                                         // Create and check your device here. 
                                                         // https://cpanel.carriots.com/device/


void setup(){

  Serial.begin(115200);
  Serial.println(F("Hello, CC3000!\n"));

  /* Initialise the module */
  Serial.println(F("\nInitialising the CC3000 ..."));
  if (!Wido.begin())
  {
    Serial.println(F("Unable to initialise the CC3000! Check your wiring?"));
    while(1);
  }

  /* Attempt to connect to an access point */
  char *ssid = WLAN_SSID;             /* Max 32 chars */
  Serial.print(F("\nAttempting to connect to ")); 
  Serial.println(ssid);

  /* NOTE: Secure connections are not available in 'Tiny' mode!
   By default connectToAP will retry indefinitely, however you can pass an
   optional maximum number of retries (greater than zero) as the fourth parameter.
   */
  if (!Wido.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println(F("Failed!"));
    while(1);
  }

  Serial.println(F("Connected!"));

  /* Wait for DHCP to complete */
  Serial.println(F("Request DHCP"));
  while (!Wido.checkDHCP())
  {
    delay(100); // ToDo: Insert a DHCP timeout!
  }  

}

uint32_t ip = 0;    // Store Carriots ip address
float temp = 0;     // Store temporary sensor data for post
Adafruit_CC3000_Client WidoClient;

void loop(){

  static unsigned long RetryMillis = 0;
  static unsigned long uploadtStamp = 0;
  static unsigned long sensortStamp = 0;

  if(!WidoClient.connected() && millis() - RetryMillis > TCP_TIMEOUT){
    // Update the time stamp for reconnecting the ip 
    RetryMillis = millis();

    Serial.println(F("Try to connect the cloud server"));

    // Connect to the Carriots Server
    ip = Wido.IP2U32(82,223,244,60);               
    WidoClient = Wido.connectTCP(ip, 80);          // Try to connect cloud server
    Serial.println(F("Successed to connect Carriots server."));

  }

  if(WidoClient.connected() && millis() - uploadtStamp > 2000){
    // If the device is connected to the cloud server, upload the data every 2000ms.
    uploadtStamp = millis();

    // send http data stream to Carriots server
    // For more details about the template of data stream, please check the link below
    // https://cpanel.carriots.com/wizards/sendstreams

    sendstream2Carriots("Temperature",int(temp));  // send the temperature sensor reading from LM35 sensor to server
                                                   // Check the data stream uploaded here.
                                                   // https://cpanel.carriots.com/stream/

    /********** Get the http page feedback and print the response ***********/
    unsigned long rTimer = millis();
    Serial.println(F("Reading Cloud Response!!!\r\n"));
    while (millis() - rTimer < 2000) {
      while (WidoClient.connected() && WidoClient.available()) {
        char c = WidoClient.read();
        Serial.print(c);
      }
    }
    delay(1000);             // Wait for 1s to finish posting the data stream   

    WidoClient.close();      // Close the service connection
    RetryMillis = millis();  // Reset the timer stamp for applying the connection with the service
  }

  if(millis() - sensortStamp > 1000){
    sensortStamp = millis();
    // read the LM35 sensor value and convert to the degrees every 100ms.

    int reading = analogRead(0);
    temp = reading *0.0048828125*100;
    Serial.print(F("Real Time Temp: ")); 
    Serial.println(temp); 
  }
}

// More details about the Carriots
// https://www.carriots.com/tutorials

void sendstream2Carriots(String dataType, int value){

  //    Serial.print("Free RAM: "); Serial.println(getFreeRam(), DEC);

  // Variables for storing the length of http package body 
  int length = 0;
  char lengthstr[5];

  String httpBodyPackage = "{\"protocol\":\"v2\",\"device\":\""+String(DEVICE)+"\",\"at\":\"now\",\"data\":{\"" + dataType + "\":"+String(value)+"}}";
  Serial.println(httpBodyPackage);                       // Debug the http body stream

  //Make an HTTP request to the Carriots server
  Serial.print(F("Sending Http Headers..."));
  WidoClient.fastrprintln(F("POST /streams HTTP/1.1"));
  WidoClient.fastrprintln(F("Host: api.carriots.com"));
  WidoClient.fastrprintln(F("Accept: application/json"));
  WidoClient.fastrprintln(F("User-Agent: Arduino-Carriots"));
  WidoClient.fastrprintln(F("Content-Type: application/json"));
  WidoClient.fastrprint(F("carriots.apikey: "));
  WidoClient.fastrprintln(API_key);
  WidoClient.fastrprint(F("Content-Length: "));
  WidoClient.println(String(httpBodyPackage.length()));
  WidoClient.fastrprintln(F("Connection: close"));
  WidoClient.fastrprintln("");

  Serial.println(F("Sending Http Data Body..."));
  WidoClient.println(httpBodyPackage);

  Serial.println(F("Done....."));
}


