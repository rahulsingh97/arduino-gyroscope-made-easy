#include <SparkFun_ADXL345.h>        

ADXL345 adxl = ADXL345();             // USE FOR I2C COMMUNICATION
void setup(){
  
  Serial.begin(9600);                
  adxl.powerOn();                     // Power on the ADXL345
  adxl.setRangeSetting(16);           // Give the range settings
                                      // Accepted values are 2g, 4g, 8g or 16g
                                      // Higher Values = Wider Measurement Range
                                      // Lower Values = Greater Sensitivity
}
void loop(){
  int x,y,z;   
  
  adxl.readAccel(&x, &y, &z);         
  Serial.print("X=");
  Serial.print(x);
  Serial.print(", ");
  Serial.print("Y=");
  Serial.print(y);
  Serial.print(", ");
  Serial.print("Z=");
  Serial.println(z); 
  delay(100); 
}
