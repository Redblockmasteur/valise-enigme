// This function use is used to play de morse section of the game
void Updtate_screen_azimut(char customKey) {

  if (state == 0) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 1) {
    lcd_1.setCursor(1, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 2) {
    lcd_1.setCursor(2, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
    lastmillisCode = millis();
  }
  // Début azimut 2
  if (state == 4) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 5) {
    lcd_1.setCursor(1, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 6) {
    lcd_1.setCursor(2, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
    lastmillisCode = millis();
  }
  // Début azimut 3
  if (state == 8) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 9) {

    lcd_1.setCursor(1, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
  }
  if (state == 10) {
    lcd_1.setCursor(2, 1);
    lcd_1.print(customKey);
    repazimut += customKey;
    lastmillisCode = millis();
  }
  // fin azimut
}