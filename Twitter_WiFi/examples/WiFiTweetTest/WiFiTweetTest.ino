#include <SPI.h> // needed in Arduino 0019 or later
#include <WiFi.h>
#include <Twitter.h>


char ssid[] = "Network Name";
char pass[] = "Secret Password"; 

// Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)
Twitter twitter("Your Token Here!");

// Message to post
char msg[] = "Automatic tweet!";

void setup()
{
  delay(1000);
  WiFi.begin(ssid, pass);
  // or you can use DHCP for automatic IP address configuration.
  // WiFi.begin(mac);
  delay(10000);
  Serial.begin(9600);
  
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}

void loop()
{
}
