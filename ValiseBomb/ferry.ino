int ferry() {
  Serial.println(digitalRead(SENSOR_FERRY));

  if (digitalRead(SENSOR_FERRY) == 1) {
    state = 0;
    jeuActuel = 3;
    prepAzimut();
  }
}