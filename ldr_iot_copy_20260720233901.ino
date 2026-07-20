#define BLYNK_TEMPLATE_ID "TMPL34I9OzB6U"
#define BLYNK_TEMPLATE_NAME "Receiver Data"
#define BLYNK_AUTH_TOKEN "E7lvd2kyCS5I2tv7ed5PwKFqXL2iPEKH"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Vaishnavi's A17";
char pass[] = "vaishnavi'sA17";

BlynkTimer timer;

void sendLDRData()
{
  int ldrValue = analogRead(A0);   // Read LDR value

  // Show on Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Send value to Gauge (V0)
  Blynk.virtualWrite(V0, ldrValue);

  // LED Widget Control (V1)
  // Change threshold according to your LDR
  if (ldrValue < 500)
  {
    Blynk.virtualWrite(V1, 255);   // LED ON
    Serial.println("LED ON");
  }
  else
  {
    Blynk.virtualWrite(V1, 0);     // LED OFF
    Serial.println("LED OFF");
  }

  Serial.println("--------------------");
}

void setup()
{
  Serial.begin(9600);

  Serial.println("Connecting to WiFi...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connected to Blynk");

  timer.setInterval(1000L, sendLDRData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
