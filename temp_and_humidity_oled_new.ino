#include <dht.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

dht DHT;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define DHT11_PIN A0

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
char dataString[50] = {0};
int a =0;
int count = 0;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temp = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  
  //sprintf(dataString,"%02X",a); // convert a value to hexa 
  display.print("Temp=");
  display.println(DHT.temperature);   
  display.print("Humid=");
  display.println(DHT.humidity);
  display.display();
  delay(1000);// give the loop some break
  display.clearDisplay();
  display.setCursor(0, 10);
  
}
