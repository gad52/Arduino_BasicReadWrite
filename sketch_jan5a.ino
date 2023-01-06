int led1 = 9;
int led2 = 6;
int led3 = 5;
int button = 11;
boolean lastbutton = LOW;
boolean ledOn = true;
int portPot = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);
}

boolean debounce(boolean last)
{
   boolean current = digitalRead(button);
   if(current != last)
   {
    delay(5);
    current = digitalRead(button);
    }
    return current;
}

void loop() {
  int val = 0;
  boolean current = debounce(lastbutton);
  if(lastbutton == LOW && current == HIGH )
  {
    ledOn = !ledOn;
  }
  lastbutton = current;
  if(ledOn)
  {
    val = analogRead(portPot);
    val = map(val,0,1023,255,0);
    Serial.println(val);
    analogWrite(led1, val);
    analogWrite(led2, val);
    analogWrite(led3, val);
    delay(10);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
}
