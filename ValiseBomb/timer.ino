void timer() {
  unsigned long timeRemaining = timeLimit + startmillis - millis();
  int sec = second(timeRemaining);
  int min = minute(timeRemaining);
  tempConcat = min * 100 + sec;
  display.showNumberDecEx(tempConcat, 0b11100000, false, 4, 0);
  timeRemaining = timeLimit - millis();
  if(tempConcat == 0){
    missionfailed();
  }

  if(tempConcat <= 10 && sireneSound==false){
    myDFPlayer.volume(20);  //Set volume value. From 0 to 30
    myDFPlayer.play(3);  //Play the mp3 (here it's the sirene sound)
    sireneSound = true; 
    Serial.println("Df player");
  }
}