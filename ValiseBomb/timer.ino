void timer() {
  unsigned long timeRemaining = timeLimit + startmillis - millis();
  int sec = second(timeRemaining);
  int min = minute(timeRemaining);
  tempConcat = min * 100 + sec;
  display.showNumberDecEx(tempConcat, 0b11100000, false, 4, 0);
  timeRemaining = timeLimit - millis();
  Serial.println(tempConcat);
  if(tempConcat == 0){
    missionfailed();
  }
}