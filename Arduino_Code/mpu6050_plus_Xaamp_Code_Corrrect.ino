// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

#include <WiFi.h>
#include <HTTPClient.h>

//String URL = "http://192.168.100.59/mpu6050_project/test_data.php";
String URL = "http://192.168.100.59/mpu6050_project2/test_data.php";
//String URL = "http://192.168.50.153/mpu6050_project2/test_data.php";
///String URL = "http://192.168.43.84/mpu6050_project2/test_data.php";
String PROJECT_API_KEY="5fsdsf2ev5FF";

//const char* ssid = "GalaxyJ6E9A"; 
//const char* password = "1234567890";

//const char* ssid = "FY"; 
//const char* password = "xoxodumb";

const char* ssid = "Best net 4g 427"; 
const char* password = "Honda125";


void setup(void) {
  Serial.begin(115200);
    connectWiFi();
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
 
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
 
  Serial.println("");
  delay(100);
}

float A,S,D;
float x_axis,y_axis,z_axis;
void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  A=a.acceleration.x;
  S=a.acceleration.y;
  D=a.acceleration.z;
  x_axis=A;
  y_axis=S;
  z_axis=D;
  Serial.print("Acceleration X: ");
  Serial.print(x_axis);
  //Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(y_axis);
  //Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(z_axis);
  //Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                          //WIFI Code Start

 // put your main code here, to run repeatedly:
if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

//String jsonData = "{\"x_axis\:" + String(x_axis) + ",\"y_axis\":" + String(y_axis) + ",\"z_axis\":" + String(z_axis) + "}";
String postData = "x_axis=" + String(x_axis) + "&y_axis=" + String(y_axis)+ "&z_axis=" + String(z_axis);
  //int postData=x_axis;
   HTTPClient http;   //Connection for webserver
  http.begin(URL);    //Make object of http  //Connect esp32 to webpage which is defined by URL
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
int httpCode = http.POST(postData);  //To send data to server use post method
String payload = http.getString(); //Response message from server
//Help server to understand the type of message that send
  //http.addHeader("Content-Type", "application/json");
  //http.addHeader("Content-Type", "application/POST");
//int httpCode = http.POST(jsonData);

  Serial.print("URL : "); Serial.println(URL);
//  Serial.print("Data: "); Serial.println(jsonData);
 
  Serial.print("Data: "); Serial.println(postData);
  Serial.print("httpCode: "); Serial.println(httpCode);
  Serial.print("payload : "); Serial.println(payload);
  Serial.println("--------------------------------------------------");
  //delay(5000);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                          //WIFI Code end


  Serial.println("");
  delay(500);
}






void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);
  //This line hides the viewing of ESP as wifi hotspot
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

