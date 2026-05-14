// Code for Arduino on Tinker cad

int RED_LED       = 12;
int YELLOW_LED    = 8;
int GREEN_LED     = 4;
int Advancebutton = 13;
int Resetbutton   = 2;

bool AdvancebuttonState     = false;
bool ResetbuttonState       = false;
bool lastAdvancebuttonState = false;
bool lastResetbuttonState   = false;

int currState = 0; // 0=Red, 1=Green, 2=Yellow

void setup(){
  pinMode(RED_LED,       OUTPUT);
  pinMode(YELLOW_LED,    OUTPUT);
  pinMode(GREEN_LED,     OUTPUT);
  pinMode(Advancebutton, INPUT);
  pinMode(Resetbutton,   INPUT);

  updateLEDs();
}

void updateLEDs()
{
  digitalWrite(RED_LED,    currState == 0 ? HIGH : LOW);
  digitalWrite(GREEN_LED,  currState == 1 ? HIGH : LOW);
  digitalWrite(YELLOW_LED, currState == 2 ? HIGH : LOW);
}

void loop()
{
  ResetbuttonState   = digitalRead(Resetbutton);
  AdvancebuttonState = digitalRead(Advancebutton);

  if (ResetbuttonState == HIGH && lastResetbuttonState == LOW)
  {
    currState = 0;
    updateLEDs();
  }

  if (AdvancebuttonState == HIGH && lastAdvancebuttonState == LOW)
  {
    currState = (currState + 1) % 3;
    updateLEDs();
  }

  lastAdvancebuttonState = AdvancebuttonState;
  lastResetbuttonState   = ResetbuttonState;

  delay(50);
}
