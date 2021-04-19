float monitorPWM(int channel, float channelRecordTime, float channelPWM) {
  if((millis() - channelRecordTime) >= period){
    channelRecordTime = millis();
    digitalWrite(channel, HIGH);
    Serial.println("PWM HIGH");
  }
  else if((millis() - channelRecordTime) >= (period * channelPWM))
    digitalWrite(channel, LOW);
  return channelRecordTime;
}
