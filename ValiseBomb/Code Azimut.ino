void prepAzimut() {
  lcd_1.setBacklight(1);
  lcd_1.print("Azimut 1:");
  lcd_1.setCursor(0, 1);
  if (diff == 1) {
    if (state == 0) {
      state = 8;
      lcd_1.clear();
      lcd_1.begin(16, 2);
      lcd_1.print("Azimut 3:");
      lcd_1.setCursor(0, 1);
    }
  }
}

void CodeAzimut() {

  char customKey = customKeypad.getKey();
  lcd_1.blink();

  if (customKey) {
    Serial.println(customKey);
    Updtate_screen_azimut(customKey);
    state++;
    Serial.print(repazimut);
  }
  if (state == 3) {  //Check if Azimut 1 is correct
    if (azimut1 == repazimut) {
      if (millis() - lastmillisCode >= 400) {
        state = state + 1;
        repazimut = "";
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        noTone(BUZZER);

        lcd_1.clear();
        lcd_1.begin(16, 2);
        lcd_1.print("Azimut 2:");
        lcd_1.setCursor(0, 1);
      }
    } else {
      state = 0;
      repazimut = "";
      lcd_1.clear();
      lcd_1.begin(16, 2);
      lcd_1.print("Azimut 1:");
      lcd_1.setCursor(0, 1);
    }
  }
  if (state == 7) {  //Check if Azimut 2 is correct
    if (azimut2 == repazimut) {
      if (millis() - lastmillisCode >= 400) {
        state = state + 1;
        repazimut = "";
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        noTone(BUZZER);


        lcd_1.clear();
        lcd_1.begin(16, 2);
        lcd_1.print("Azimut 3:");
        lcd_1.setCursor(0, 1);
      }
    } else {
      lcd_1.clear();
      lcd_1.begin(16, 2);
      lcd_1.print("Azimut 2:");
      lcd_1.setCursor(0, 1);
      state = 4;
      repazimut = "";
      Serial.println("code is baaaaad");
    }
  }
  if (state == 11) {  //Check if Azimut 3 is correct
    if (azimut3 == repazimut) {
      if (millis() - lastmillisCode >= 400) {
        state = state + 1;
        repazimut = "";
        Serial.println("code is gooooooood");
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        noTone(BUZZER);


        lcd_1.begin(16, 2);
        lcd_1.print("Bomb located");
        lcd_1.noBlink();
        digitalWrite(LED_CARTE, HIGH);
        state = 0;
        jeuActuel = 4;
        lastmillisCode = millis();
        return true;
      }
    } else {
      state = 8;
      repazimut = "";
      Serial.println("code is baaaaad");
      lcd_1.clear();
      lcd_1.begin(16, 2);
      lcd_1.print("Azimut 3:");
      lcd_1.setCursor(0, 1);
    }
  }

  // Transmisiosn du morse
  if (diff == 1) {
    shortmoscow(17);
  }
  if (diff == 2) {
    if (state < 3) {
      shortparis(18);
    } else if (state > 3 && state < 7) {
      shortboston(18);
    } else if (state > 7 && state < 33) {
      shortmoscow(17);
    }
  }
  if (diff == 3) {
    if (state < 3) {
      paris(36);
    } else if (state > 3 && state < 7) {
      boston(40);
    } else if (state > 7 && state < 33) {
      moscow(42);
    }
  }
}


void paris(int NoOffBeeps) {
  // paris 193
  uint32_t PARIS[] = { start, point, tiret, tiret, point, spaceL, point, tiret, spaceL, point, tiret, point, spaceL, point, point, spaceL, point, point, point, spaceL, point, tiret, tiret, tiret, tiret, spaceL, tiret, tiret, tiret, tiret, point, spaceL, point, point, point, tiret, tiret };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (PARIS[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println("Tiret");

      } else if (PARIS[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);


        Serial.println("Point");
      } else {

        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      waitTime = PARIS[index];
      index = (index + 1) % NoOffBeeps;
      Serial.print("Index : ");
      Serial.println(index);
      Serial.print("Wait time :");
      Serial.println(PARIS[index]);
      
    }
  }
}

void shortparis(int NoOffBeeps) {
  // 193
  uint32_t shortPARIS[] = { start, point, tiret, tiret, tiret, tiret, spaceL, tiret, tiret, tiret, tiret, point, spaceL, point, point, point, tiret, tiret };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (shortPARIS[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println("Tiret");

      } else if (shortPARIS[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);


        Serial.println("Point");
      } else {

        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      waitTime = shortPARIS[index];
      index = (index + 1) % NoOffBeeps;
      Serial.println(index);
    }
  }
}

void boston(int NoOffBeeps) {
  // boston 068
  uint32_t BOSTON[] = { start, tiret, point, point, point, spaceL, tiret, tiret, tiret, spaceL, point, point, point, spaceL, tiret, spaceL, tiret, tiret, tiret, spaceL, tiret, point, spaceL, tiret, tiret, tiret, tiret, tiret, spaceL, tiret, point, point, point, point, spaceL, tiret, tiret, tiret, point, point };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (BOSTON[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println(BOSTON[index]);
        Serial.println("Tiret");

      } else if (BOSTON[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);

        Serial.println(BOSTON[index]);
        Serial.println("Point");
      } else {
        Serial.println(BOSTON[index]);
        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      Serial.println(index);
      waitTime = BOSTON[index];
      index = (index + 1) % NoOffBeeps;
    }
  }
}

void shortboston(int NoOffBeeps) {
  //068
  uint32_t shortBOSTON[] = { start, tiret, tiret, tiret, tiret, tiret, spaceL, tiret, point, point, point, point, spaceL, tiret, tiret, tiret, point, point };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (shortBOSTON[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println(shortBOSTON[index]);
        Serial.println("Tiret");

      } else if (shortBOSTON[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);

        Serial.println(shortBOSTON[index]);
        Serial.println("Point");
      } else {
        Serial.println(shortBOSTON[index]);
        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      Serial.println(index);
      waitTime = shortBOSTON[index];
      index = (index + 1) % NoOffBeeps;
    }
  }
}

void moscow(int NoOffBeeps) {
  // moscow 253 
  uint32_t MOSCOW[] = { start, tiret, tiret, spaceL, tiret, tiret, tiret, spaceL, point, point, point, spaceL, tiret, point, tiret, point, spaceL, tiret, tiret, tiret, spaceL, point, point, tiret, spaceL, point, point, tiret, tiret, tiret, spaceL, point, point, point, point, point, spaceL, point, point, point, tiret, tiret };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (MOSCOW[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println(MOSCOW[index]);
        Serial.println("Tiret");

      } else if (MOSCOW[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);

        Serial.println(MOSCOW[index]);
        Serial.println("Point");
      } else {
        Serial.println(MOSCOW[index]);
        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      Serial.println(index);
      waitTime = MOSCOW[index];
      index = (index + 1) % NoOffBeeps;
    }
  }
}

void shortmoscow(int NoOffBeeps) {
  // 253
  uint32_t shortMOSCOW[] = { start, point, point, tiret, tiret, tiret, spaceL, point, point, point, point, point, spaceL, tiret, tiret, tiret, point };
  uint32_t currentMillis = millis();
  static uint8_t index = 0;
  static uint32_t lastMillis;
  static uint32_t waitTime;
  static bool toneOn;
  if (currentMillis - lastMillis >= waitTime) {
    lastMillis = currentMillis;
    if (toneOn) {
      toneOn = false;
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      waitTime = silence;
    } else {
      toneOn = true;
      if (shortMOSCOW[index] == tiret) {
        digitalWrite(LED_GREEN, HIGH);
        tone(BUZZER, 200, tiret);

        Serial.println(shortMOSCOW[index]);
        Serial.println("Tiret");

      } else if (shortMOSCOW[index] == point) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 600, point);

        Serial.println(shortMOSCOW[index]);
        Serial.println("Point");
      } else {
        Serial.println(shortMOSCOW[index]);
        Serial.println("Start ou Space");

        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
      }
      Serial.println(index);
      waitTime = shortMOSCOW[index];
      index = (index + 1) % NoOffBeeps;
    }
  }
}