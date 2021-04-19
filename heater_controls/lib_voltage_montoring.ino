void monitorVoltage() {

  float sum1 = 0.0;  // monitoring variables
  float sum2 = 0.0;  
  float v1 = 0.0;
  float v2 = 0.0;
  int samples = 0;
  float cal = 5;  // voltage calibration constant

  // take a few samples of voltage and average
  while(samples < numSamples) {
    samples++;
    sum1 += analogRead(A0);
    sum2 += analogRead(A2);
    delay(sampleDelay);
  }

  // calculate voltage
  v1 = cal * sum1 / samples / 1024;
  v2 = cal * sum2 / samples / 1024;

  // low battery cell voltage protection override
  if (powerOn & ((v1 < vCutoff) | (v2 < vCutoff))) 
    powerOn--;

  Serial.println("Monitor:");
  Serial.println(v1);
  Serial.println(v2);

}
