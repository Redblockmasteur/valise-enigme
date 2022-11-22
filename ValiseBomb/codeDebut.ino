int code_debut() {

  char customKey = customKeypad.getKey();

  if (customKey) {
    updateCodeDebut(customKey);
    state++;
  }

  if (state == 0) {
    lcd_1.clear();
    lcd_1.setBacklight(1);
    lcd_1.print("Code :");
    lcd_1.setCursor(0, 1);
    state++;
  }
  // Check if the code is correct
  if (state == 4) {
    if ((millis() - lastmillis) >= 400) {
      lastmillis = millis();
      if (repcode == codeCarteDiff1) {
        state++;
        lcd_1.clear();
        lcd_1.setCursor(3, 0);
        lcd_1.print("Game Start");
        lcd_1.noBlink();
        timeLimit = 180000;
        diff = 1;
      } else if (repcode == codeCarteDiff2) {
        state++;
        lcd_1.clear();
        lcd_1.setCursor(3, 0);
        lcd_1.print("Game Start");
        lcd_1.noBlink();
        timeLimit = 420000;
        diff = 2;
      } else if (repcode == codeCarteDiff3) {
        state++;
        lcd_1.clear();
        lcd_1.setCursor(3, 0);
        lcd_1.print("Game Start");
        lcd_1.noBlink();
        timeLimit = 900000;
        diff = 3;
      } else {
        state = 0;
        repcode = "";
      }
    }
  }
  if (state == 5) {
    if ((millis() - lastmillis) >= 400) {
      lcd_1.clear();
      lcd_1.noBacklight();
      state = 0;
      jeuActuel = 1;
      startmillis = millis();
    }
  }
}

void updateCodeDebut(char customKey) {

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
    lastmillis = millis();
  }
}