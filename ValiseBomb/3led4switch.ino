void niveau1() {  ////////////////////////////////////////////////////////////////////////NIVEAU1
  stateButton1 = digitalRead(BUTTON_1);
  stateButton2 = digitalRead(BUTTON_2);
  stateButton3 = digitalRead(BUTTON_3);
  stateButton4 = digitalRead(BUTTON_4);

  if ((stateButton1 == LOW) && (stateButton1 != memory1)) {

    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
  }

  if ((stateButton2 == LOW) && (stateButton2 != memory2)) {

    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
  }

  if ((stateButton3 == LOW) && (stateButton3 != memory3)) {

    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
  }

  if ((stateButton4 == LOW) && (stateButton4 != memory4)) {

    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }
  memory1 = stateButton1;
  memory2 = stateButton2;
  memory3 = stateButton3;
  memory4 = stateButton4;
}

void niveau2() {  ////////////////////////////////////////////////////////////////////////NIVEAU2
  stateButton1 = digitalRead(BUTTON_1);
  stateButton2 = digitalRead(BUTTON_2);
  stateButton3 = digitalRead(BUTTON_3);
  stateButton4 = digitalRead(BUTTON_4);

  if ((stateButton1 == LOW) && (stateButton1 != memory1) && state == 0) {
    state = 1;
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
  }

  if ((stateButton2 == LOW) && (stateButton2 != memory2) && state == 0) {
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }

  if ((stateButton3 == LOW) && (stateButton3 != memory3) && state == 0) {
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }

  if ((stateButton4 == LOW) && (stateButton4 != memory4) && state == 0) {
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////

  if ((stateButton3 == LOW) && (stateButton3 != memory3) && state == 1) {
    state = 2;
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }

  if ((stateButton2 == LOW) && (stateButton2 != memory2) && state == 2) {
    state = 3;
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
  }

  if ((stateButton1 == LOW) && (stateButton1 != memory1) && state == 3) {
    state = 4;
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
  }

  if ((stateButton4 == LOW) && (stateButton4 != memory4) && state == 4) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
  }

  if ((digitalRead(LED_1) == HIGH) && (digitalRead(LED_2) == HIGH) && (digitalRead(LED_3) == HIGH)) {
    digitalWrite(LED_RED, LOW);
  } else {
    thief();
  }
  memory1 = stateButton1;
  memory2 = stateButton2;
  memory3 = stateButton3;
  memory4 = stateButton4;
}

void niveau3() {  ////////////////////////////////////////////////////////////////////////NIVEAU3
  stateButton1 = digitalRead(BUTTON_1);
  stateButton2 = digitalRead(BUTTON_2);
  stateButton3 = digitalRead(BUTTON_3);
  stateButton4 = digitalRead(BUTTON_4);

  if (state == 0) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      state = 1;
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 1) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      state = 2;
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 2) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      state = 3;
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 3) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      state = 4;
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 4) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      state = 5;
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 5) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      state = 6;
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }

  if (state == 6) {
    if ((stateButton1 == LOW) && (stateButton1 != memory1)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
    }

    if ((stateButton2 == LOW) && (stateButton2 != memory2)) {
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton3 == LOW) && (stateButton3 != memory3)) {
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed3 == LOW) {
        digitalWrite(LED_3, HIGH);
        stateLed3 = HIGH;
      } else {
        digitalWrite(LED_3, LOW);
        stateLed3 = LOW;
      }
    }

    if ((stateButton4 == LOW) && (stateButton4 != memory4)) {
      state = 6;
      if (stateLed2 == LOW) {
        digitalWrite(LED_2, HIGH);
        stateLed2 = HIGH;
      } else {
        digitalWrite(LED_2, LOW);
        stateLed2 = LOW;
      }
      if (stateLed1 == LOW) {
        digitalWrite(LED_1, HIGH);
        stateLed1 = HIGH;
      } else {
        digitalWrite(LED_1, LOW);
        stateLed1 = LOW;
      }
    }
  }



  ////////////////////////////////////////////////////////////////////////////////////////////

  if ((stateButton3 == LOW) && (stateButton3 != memory3) && state == 1) {
    state = 2;
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
  }

  if ((stateButton2 == LOW) && (stateButton2 != memory2) && state == 2) {
    state = 3;
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
  }

  if ((stateButton1 == LOW) && (stateButton1 != memory1) && state == 3) {
    state = 4;
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
    if (stateLed1 == LOW) {
      digitalWrite(LED_1, HIGH);
      stateLed1 = HIGH;
    } else {
      digitalWrite(LED_1, LOW);
      stateLed1 = LOW;
    }
  }

  if ((stateButton3 == LOW) && (stateButton3 != memory3) && state == 4) {
    state = 5;
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }

  if ((stateButton1 == LOW) && (stateButton1 != memory1) && state == 5) {
    state = 6;
    if (stateLed2 == LOW) {
      digitalWrite(LED_2, HIGH);
      stateLed2 = HIGH;
    } else {
      digitalWrite(LED_2, LOW);
      stateLed2 = LOW;
    }
    if (stateLed3 == LOW) {
      digitalWrite(LED_3, HIGH);
      stateLed3 = HIGH;
    } else {
      digitalWrite(LED_3, LOW);
      stateLed3 = LOW;
    }
  }

  if ((stateButton4 == LOW) && (stateButton4 != memory4) && state == 6) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
  }

  if ((digitalRead(LED_1) == HIGH) && (digitalRead(LED_2) == HIGH) && (digitalRead(LED_3) == HIGH)) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(SENSOR, LOW);
  } else {
    thief();
  }
  memory1 = stateButton1;
  memory2 = stateButton2;
  memory3 = stateButton3;
  memory4 = stateButton4;
}

void thief() {

  stateSensor = digitalRead(SENSOR);
  if (stateSensor == LOW) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 200, 100);

  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    noTone(BUZZER);
  }
}

void ledswitch() {
  if (stateLevel == 0) {
    if (diff == 1) {
      niveau1();
    } else if (diff == 2) {
      niveau2();
    } else if (diff == 3) {
      niveau3();
    }
    thief();
    if ((digitalRead(LED_1) == HIGH) && (digitalRead(LED_2) == HIGH) && (digitalRead(LED_3) == HIGH)) {
      stateLevel = 1;
    }
  } else if (stateLevel == 1) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(SENSOR, LOW);
    stateLevel = 2;
    lastTimeAction = millis();

  } else if ((stateLevel == 2) && ((millis() - lastTimeAction) >= ELAPSED_TIME)) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    state = 0;
    jeuActuel = 2;
    repcode = "";
  }
}