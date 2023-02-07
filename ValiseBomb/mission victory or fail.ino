void missionfailed() {

  lcd_1.clear();
  lcd_1.setCursor(1, 0);
  lcd_1.print("Mission failed");
  jeuActuel = 6;
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.play(2);  //Play the first mp3 (here it's the bomb sound)
  Serial.println("Df player");
}


void missionVictory(){
  lcd_1.clear();
  lcd_1.setCursor(2, 0);
  lcd_1.print("Bomb defused");
  lcd_1.setCursor(4, 1);
  lcd_1.print("good job");
  lcd_1.noBlink();
  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the second mp3 (here it's the victory sound)
  Serial.println("Df player");
}