
#include <SparkFun_ADXL345.h>         // SparkFun ADXL345 Library
ADXL345 adxl = ADXL345();             // USE FOR I2C COMMUNICATION
void setup(){ 
  Serial.begin(9600);                 // Start the serial terminal
  adxl.powerOn();                     // Power on the ADXL345
  adxl.setRangeSetting(16);           // Give the range settings
                                      // Accepted values are 2g, 4g, 8g or 16g
                                      // Higher Values = Wider Measurement Range
                                      // Lower Values = Greater Sensitivity
}
void loop(){
  
  // Accelerometer Readings
  int x,y,z;   
  
  adxl.readAccel(&x, &y, &z);         // Read the accelerometer values and store them in variables declared above x,y,z
  Serial.print("X=");
  Serial.print(x);
  Serial.print(", ");
  Serial.print("Y=");
  Serial.print(y);
  Serial.print(", ");
  Serial.print("Z=");
  Serial.print(z); 
  byte interrupts = adxl.getInterruptSource();
  Serial.print("        ");
  Serial.print("  F");
  Serial.print(adxl.triggered(interrupts, ADXL345_FREE_FALL));
  Serial.print("  I");
  Serial.print(adxl.triggered(interrupts, ADXL345_INACTIVITY));
  Serial.print("  A");
  Serial.print(adxl.triggered(interrupts, ADXL345_ACTIVITY));
  Serial.print("  D");
  Serial.print(adxl.triggered(interrupts, ADXL345_DOUBLE_TAP));
  Serial.print("  S");
  Serial.println(adxl.triggered(interrupts, ADXL345_SINGLE_TAP));
  
  delay(500); 
}
