void monitorButton() {   
  if(digitalRead(fleeceButtonPin)){
    fleecePower = fleecePower % maxPower + 1;
    fleecePWM = fleecePower / maxPower;
    rgbColor(redFleecePin, greenFleecePin, blueFleecePin, rgbPower[fleecePower-1][0], rgbPower[fleecePower-1][1], rgbPower[fleecePower-1][2]);
    Serial.print("fleecePower: ");
    Serial.println(fleecePower);
    delay(500);
  }   
  if(digitalRead(insoleButtonPin)){
    insolePower = insolePower % maxPower + 1;
    insolePWM = insolePower / maxPower;
    rgbColor(redInsolePin, greenInsolePin, blueInsolePin, rgbPower[insolePower-1][0], rgbPower[insolePower-1][1], rgbPower[insolePower-1][2]);
    Serial.print("insolePower: ");
    Serial.println(insolePower);
    delay(500);
  }
}

void rgbColor(int redPin, int greenPin, int bluePin, bool r, bool g, bool b) {
  Serial.print(r); Serial.print(",");
  Serial.print(g); Serial.print(",");
  Serial.print(b); Serial.println(" ");

  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
  digitalWrite(bluePin, b);
}
