#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define the DHT sensor type and pin
#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD. Set the address to 0x27 for a 16 chars and 2-line display.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Start serial communication
  Serial.begin(9600);
Wire.begin();
  // Initialize the LCD
  lcd.begin();
  lcd.backlight();

  // Initialize the DHT sensor
  dht.begin();
  
  // Print a welcome message
  /*lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");*/
  lcd.setCursor(0,0);
  lcd.print("Temperature &");
  lcd.setCursor(0,1);
  lcd.print("Humidity Monitor");
  delay(4000);
  lcd.clear();
}

void loop() {
  // Read temperature and humidity
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early
  if (isnan(temp) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    Serial.println("Error reading sensor data");
    delay(2000);
    lcd.clear();
    return;
  }

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  // Display humidity on LCD
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Wait before refreshing the values
  delay(2000);
}
