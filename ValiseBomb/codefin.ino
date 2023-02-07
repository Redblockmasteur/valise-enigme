int code_fin() {

  char customKey = customKeypad.getKey();

  lcd_1.blink();

  if (customKey) {
    updateCodeFin(customKey);
    state++;
  }

  if (state == 0) {
    lcd_1.clear();
    lcd_1.setBacklight(1);
    lcd_1.print("Code :");
    lcd_1.setCursor(0, 1);
    repcode = "";
    state++;
  }
  // Check if the code is correct
  if (state == 5) {
    if (repcode == codeBomb) {
      if ((millis() - lastmillisCode) >= 700) {
        state++;
        jeuActuel = 5;
        missionVictory();
      }
    } else {
      state = 0;
      repcode = "";
    }
  }
  Serial.println(state);
}

void updateCodeFin(char customKey) {

  if (state == 1) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(customKey);
    repcode += customKey;
  }
  if (state == 2) {
    lcd_1.setCursor(1, 1);
    lcd_1.print(customKey);
    repcode += customKey;
  }
  if (state == 3) {
    lcd_1.setCursor(2, 1);
    lcd_1.print(customKey);
    repcode += customKey;
  }
  if (state == 4) {
    lcd_1.setCursor(3, 1);
    lcd_1.print(customKey);
    repcode += customKey;
    lastmillisCode = millis();
  }
}