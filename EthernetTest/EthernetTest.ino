

#include <SPI.h>
#include <Ethernet.h>

#define FIREBASE_HOST "hms-monitor.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyBj6RdgGz_jP4L_rH7qmlF0HccWZvTg7RM"
#define AUTH_KEY "AAAAtWdn_Qc:APA91bGtxfNkcCpUe1G3Pm3JlIsB5sMoOWbGr0LjFBhU7RqmIdDEL7551xAb3wCL98it5Nx7-C43R6uxmi7w2jIlt5JJClRoktxWuRQwXQLtUMWtsACuAhn0B74LA7m7DpquVeV5eYI5"

// the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte server[] = { 64, 233, 187, 99 }; // Google 

EthernetClient client;

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Ethernet.begin(mac);

  Serial.print("The DNS server IP address is: ");
  Serial.println(Ethernet.dnsServerIP());

  Serial.print("The gateway IP address is: ");
  Serial.println(Ethernet.gatewayIP());

  

  if(client.connect("https://fcm.googleapis.com", 80)) {
    Serial.println("Hello");
    client.println("POST /fcm/send HTTP/1.1");
    client.println("Host: fcm.googleapis.com");
    client.print("Authorization: key=");
    client.println(AUTH_KEY);
    client.println("Content-Type: application/json");

    const char* data = "{"
                       "\"to\": \"fUchwVH7iTs:APA91bHJGwd0sAQlOJLUAsHTGoSD7-MfsHYS46HnnGdWa9PZUn6uHXvW5xWiFuBaQEDytZ25DeeXZPAhyKxCBSegUyBdK5sTYxelDKswKzKI43cbt6wL4K6K6w1l30JTN1v4ivM4V9xB\","
                       "\"notification\" : {"
                       "\"title\":\"Hello\","
                       "\"body\":\"This is the body\""
                       "}}";
    Serial.println(data);
    client.println(data);

    client.flush();

    while(client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }
  else {
    Serial.println("No");
  }

}

void loop() {}
