#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 2; //four rows
const byte COLS = 14; //three columns
char keys[ROWS][COLS] = {
{'X', 'Fs', 'Gs', 'As', 'X', 'Cs', 'Ds', 'X', 'Fs', 'Gs', 'As', 'X', 'Cs', 'Ds'},
  {'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E'}
};
byte rowPins[ROWS] = {30, 31}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {32, 0, 1, 9, 5, 4, 3, 2, 14, 24, 25, 26, 27, 28}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String msg;

void setup() {
    Serial.begin(9600);
    msg = "";
}


void loop() {
    char key = kpd.getKey();
    
    if (kpd.getKeys())
    {
        Serial.print(key);
    }  // End loop
}