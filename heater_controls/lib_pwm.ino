float monitorPWM(int channel, float channelRecordTime, float channelPWM) {
  if((millis() - channelRecordTime) >= period){
    channelRecordTime = millis();
    digitalWrite(channel, HIGH);
    Serial.println("PWM HIGH");
  }
  else if((millis() - channelRecordTime) >= (period * 0.95)){
    if(channel == insole){
      int relay = 0;
      while(relay < numChannels){
        digitalWrite(allChannels[relay], LOW);
        relay++;
      }
      monitorVoltage();
    }
  }
  else if((millis() - channelRecordTime) >= (period * channelPWM))
    digitalWrite(channel, LOW);
  return channelRecordTime;
}
