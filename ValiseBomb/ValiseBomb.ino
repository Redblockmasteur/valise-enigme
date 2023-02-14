#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <TM1637Display.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define CLK 49
#define DIO 48

uint8_t blank[] = { 0x0 };

int tempConcat = 0;

TM1637Display display = TM1637Display(CLK, DIO);

#define second(_time_) ((_time_ / 1000) % 60)
#define minute(_time_) (((_time_ / 1000) / 60) % 60)

const uint8_t OFF[] = { 0, 0, 0, 0 };
unsigned long timeLimit;

unsigned long startmillis = 0;

//////////////////////// 3LED/4SWITCHS
#define BUTTON_1 22
#define BUTTON_2 23
#define BUTTON_3 24
#define BUTTON_4 25

#define LED_1 26
#define LED_2 27
#define LED_3 28

#define SENSOR 29
#define LED_RED 30
#define LED_GREEN 31
#define BUZZER 13
#define SOUND 750

#define LED_CARTE 35

#define SENSOR_FERRY 32

#define ELAPSED_TIME 1500

int jeuActuel = 0;  //0 == code début // 1 == 3 led 4switch // 2 == Ferry // == 3 Azimut // 4 == Code fin   END_GAME    // 5 == Victoire // 6 == Défaite

int stateButton1;
int stateButton2;
int stateButton3;
int stateButton4;

int stateLed1 = LOW;
int stateLed2 = LOW;
int stateLed3 = LOW;

//varibale memoire de l'etat des boutons
int memory1 = LOW;
int memory2 = LOW;
int memory3 = LOW;
int memory4 = LOW;

bool stateSensor;
int stateLevel;
unsigned long lastTimeAction;
unsigned long lastmillis = 0;
unsigned long lastmillisCode = 0;

//Pin Electroaimant
int Electromagnet = 7;

//CODE MORSE
LiquidCrystal_I2C lcd_1(0x27, 20, 4);
int state = 0;  //état machine

int diff = 0;

const String codeCarteDiff1 = "746";
const String codeCarteDiff2 = "523";
const String codeCarteDiff3 = "108";
const String codeBomb = "1030";


String repcode;

//Store the corect azimut
const String azimut1 = "193";
const String azimut2 = "068";
const String azimut3 = "259";
// Store the anser
String repazimut;

// cadence morse
const int point = 500;  //1000
const int tiret = point * 3;
const int spaceL = point * 2;
const int spaceMot = point * 3;
const int start = point * 10;
uint32_t silence = 700;

// Définie le nombre de ligne et de colone que comporte le keypad
const byte ROWS = 4;
const byte COLS = 3;

// tableau qui représente le clavier.
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
//8765

byte rowPins[ROWS] = { 11, 10, 9, 8 };

byte colPins[COLS] = { 5, 4, 3 };
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//DF player

bool sireneSound;


SoftwareSerial mySoftwareSerial(12, 46);  // TX, RX (12 et 46 sur arduino mega)
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  pinMode(Electromagnet, OUTPUT);  // Electroaimant comme OUTPUT


  ////////////////////////3LED/4SWITCH
  display.setBrightness(0x0c);
  display.setSegments(OFF);

  pinMode(LED_CARTE, OUTPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(SENSOR_FERRY, INPUT);


  stateLevel = 0;

  digitalWrite(Electromagnet, HIGH);  //Electroaimant activé

  ////////////////////////////////CODE MORSE
  pinMode(30, OUTPUT);  //led rouge
  pinMode(31, OUTPUT);  //led verte
  lcd_1.init();
  lcd_1.clear();
  lcd_1.setBacklight(0);
  lcd_1.blink();

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    lcd_1.setBacklight(1);
    lcd_1.clear();
    lcd_1.begin(16, 2);
    lcd_1.setCursor(2, 0);
    lcd_1.print("DF Player BAD :(");
    digitalWrite(30, HIGH);

    while (true) {
      delay(0);  // Code to compatible with ESP8266 watch dog.
    }
  }


  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.loop(4);     //Play the mp3 (here it's the background sound)
  Serial.println(F("sound 3 playing"));
}

void loop() {
  if (jeuActuel == 0) {
    code_debut();
  } else if (jeuActuel == 1) {
    ledswitch();
  } else if (jeuActuel == 2) {
    ferry();
  } else if (jeuActuel == 3) {
    if (state < 12) {
      CodeAzimut();
    }
  } else if (jeuActuel == 4) {
    if (millis() - lastmillisCode >= 400) {
      code_fin();
    }
  }
  if (jeuActuel > 0 && jeuActuel <= 4) {
    timer();
  }
}