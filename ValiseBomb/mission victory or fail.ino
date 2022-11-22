void missionfailed() {
  //char customKey = customKeypad.getKey();
  lcd_1.clear();
  lcd_1.setCursor(1, 0);
  lcd_1.print("Mission failed");
  jeuActuel = 6;
  
  tone(BUZZER, 500, 200);

  tone(BUZZER, 500, 200);

  tone(BUZZER, 500, 200);

  tone(BUZZER, 800, 150);

  tone(BUZZER, 500, 500);

  tone(BUZZER, 600, 1000);
/*  lcd_1.print("PRESS ANY KEY");
  lcd_1.noBlink();
  if (customKey) {
    updateCodeDebut(customKey);
    jeuActuel = 0;
    state = 0;
  } */
}


void missionVictory(){
  lcd_1.clear();
  lcd_1.setCursor(2, 0);
  lcd_1.print("Bomb defused");
  lcd_1.setCursor(4, 1);
  lcd_1.print("good job");
  lcd_1.noBlink();
}