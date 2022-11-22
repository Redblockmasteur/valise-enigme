int ferry() {

  char customKey = customKeypad.getKey();
  Serial.println(state);

  if (customKey) {
    updateCodeferry(customKey);
    state++;
  }

  if (state == 0) {
    lcd_1.clear();
    lcd_1.setBacklight(1);
    lcd_1.print("Longitude");
    lcd_1.setCursor(0, 1);
    state++;
  }
  // Check if the code is correct
  if (state == 3) {
    if ((millis() - lastmillis) >= 1500) {
      lastmillis = millis();
      if (repcode == codeLatVille) {
        state++;
        lcd_1.clear();
        lcd_1.noBlink();
      } else {
        state = 0;
        repcode = "";
      }
    }
  }
  if (state == 4) {
    if ((millis() - lastmillis) >= 700) {
      lcd_1.clear();
      state = 0;
      jeuActuel = 3;
      prepAzimut();
    }
  }
}

void updateCodeferry(char customKey) {

  if (state == 1) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(customKey);
    repcode += customKey;
  }
  if (state == 2) {
    lcd_1.setCursor(1, 1);
    lcd_1.print(customKey);
    repcode += customKey;
    lastmillis = millis();
  }
}