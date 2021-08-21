//Grid Storm
//Firmware adaptation for the Glitch Storm MK2
//by 2021 Spherical Sound Society

//Based on Mutable Instruments Anushri and Grids
// It turns the Glitch Storm MK2 hardware into a kind of grids gate sequencer

//Bits of code thanks to:
//Emilie Gillet (emilie@mutable-instruments.net)

// Thopa djthopa@djthopa.net

//Honza Hrubes /aka ashimoke ashimoke@gmail.com

//Geert @ http://Goltstein.nl

//Darwin Grosse @  (www.20objects.com)



// Controls:

//Bass drum density pot  --->A POT
//Snare drum density pot --->A POT 
//HiHat density pot      --->B POT 
//OhHat density pot      --->B POT 

//X coordinate           --->C POT 
//Y coordinate           --->RATE POT 

// left button+RATE POT ---->change BPMs

//pin definitions
#define BDrum_Out  7
#define SDrum_Out  8
#define HHats_out  10
#define OHats_out  12
#define out1Pin  6
#define out2Pin  5
#define out3Pin  4
#define out4Pin  3
#define leftButtonPin  2
#define rightButtonPin  A5
#define isDebuggin false


//// copied from grids

int BDcluster1[16] = {255, 0, 0, 0, 0, 0, 145, 0, 0, 0, 0, 0, 218, 0, 0, 0 };
int SDcluster1[16] = {72, 0, 36, 0, 182, 0, 0, 0, 109, 0, 0, 0, 72, 0, 0, 0 };
int HHcluster1[16] = {36, 0, 109, 0, 0, 0, 8, 0, 255, 0, 0, 0, 0, 0, 72, 0 };
int OHcluster1[16] = {0, 0, 182, 0, 0, 0, 36, 0, 218, 0, 0, 0, 145, 0, 0, 0 };

int BDcluster2[16] = {229, 0, 25, 0, 102, 0, 25, 0, 204, 0, 25, 0, 76, 0, 8, 0 };
int SDcluster2[16] = {255, 0, 8, 0, 51, 0, 25, 0, 178, 0, 25, 0, 153, 0, 127, 0 };
int HHcluster2[16] = {28, 0, 198, 0, 56, 0, 56, 0, 226, 0, 28, 0, 141, 0, 28, 0 };
int OHcluster2[16] = {28, 0, 170, 0, 28, 0, 28, 0, 255, 0, 113, 0, 85, 0, 85, 0 };

int BDcluster3[16] = {255, 0, 0, 0, 127, 0, 0, 0, 0, 0, 102, 0, 0, 0, 229, 0 };
int SDcluster3[16] = {0, 0, 178, 0, 204, 0, 0, 0, 76, 0, 51, 0, 153, 0, 25, 0 };
int HHcluster3[16] = {0, 0, 127, 0, 0, 0, 0, 0, 255, 0, 191, 0, 31, 0, 63, 0 };
int OHcluster3[16] = {0, 0, 95, 0, 0, 0, 0, 0, 223, 0, 0, 0, 31, 0, 159, 0 };

int BDcluster4[16] = {255, 0, 212, 0, 63, 0, 0, 0, 106, 0, 148, 0, 85, 0, 127, 0 };
int SDcluster4[16] = {191, 0, 21, 0, 233, 0, 0, 0, 21, 0, 170, 0, 0, 0, 42, 0 };
int HHcluster4[16] = {0, 0, 0, 0, 141, 0, 113, 0, 255, 0, 198, 0, 0, 0, 56, 0 };
int OHcluster4[16] = {0, 0, 85, 0, 56, 0, 28, 0, 226, 0, 28, 0, 170, 0, 56, 0 };

int BDcluster5[16] = {255, 0, 31, 0, 63, 0, 63, 0, 127, 0, 95, 0, 191, 0, 63, 0 };
int SDcluster5[16] = {223, 0, 31, 0, 159, 0, 63, 0, 31, 0, 63, 0, 95, 0, 31, 0 };
int HHcluster5[16] = {8, 0, 0, 0, 95, 0, 63, 0, 255, 0, 0, 0, 127, 0, 0, 0 };
int OHcluster5[16] = {8, 0, 0, 0, 159, 0, 63, 0, 255, 0, 223, 0, 191, 0, 31, 0 };

int BDcluster6[16] = {255, 0, 51, 0, 25, 0, 76, 0, 0, 0, 0, 0, 102, 0, 0, 0 };
int SDcluster6[16] = {204, 0, 229, 0, 0, 0, 178, 0, 0, 0, 153, 0, 127, 0, 8, 0 };
int HHcluster6[16] = {178, 0, 127, 0, 153, 0, 204, 0, 255, 0, 0, 0, 25, 0, 76, 0 };
int OHcluster6[16] = {102, 0, 51, 0, 0, 0, 0, 0, 229, 0, 25, 0, 25, 0, 204, 0 };

int BDcluster7[16] = {255, 0, 0, 0, 223, 0, 0, 0, 31, 0, 8, 0, 127, 0, 0, 0 };
int SDcluster7[16] = {95, 0, 0, 0, 159, 0, 0, 0, 95, 0, 63, 0, 191, 0, 0, 0 };
int HHcluster7[16] = {51, 0, 204, 0, 0, 0, 102, 0, 255, 0, 127, 0, 8, 0, 178, 0 };
int OHcluster7[16] = {25, 0, 229, 0, 0, 0, 76, 0, 204, 0, 153, 0, 51, 0, 25, 0 };

int BDcluster8[16] = {223, 0, 0, 0, 63, 0, 0, 0, 95, 0, 0, 0, 223, 0, 31, 0 };
int SDcluster8[16] = {255, 0, 0, 0, 159, 0, 0, 0, 127, 0, 31, 0, 191, 0, 31, 0 };
int HHcluster8[16] = {0, 0, 0, 0, 109, 0, 0, 0, 218, 0, 0, 0, 182, 0, 72, 0 };
int OHcluster8[16] = {8, 0, 36, 0, 145, 0, 36, 0, 255, 0, 8, 0, 182, 0, 72, 0 };

int BDcluster9[16] = {255, 0, 0, 0, 218, 0, 0, 0, 36, 0, 0, 0, 218, 0, 0, 0 };
int SDcluster9[16] = {182, 0, 109, 0, 255, 0, 0, 0, 0, 0, 0, 0, 145, 0, 72, 0 };
int HHcluster9[16] = {159, 0, 0, 0, 31, 0, 127, 0, 255, 0, 31, 0, 0, 0, 95, 0 };
int OHcluster9[16] = {8, 0, 0, 0, 191, 0, 31, 0, 255, 0, 31, 0, 223, 0, 63, 0 };

int BDfreq = 0;
int SDfreq = 0;
int HHfreq = 0;
int OHfreq = 0; // variables for storing drum density

float Xmap = 0;
float Ymap = 0;                          // coordinates of the 2D pattern map

//  variables for interrupt handling of the clock input
volatile int clkState = LOW;


byte reset_current;
byte reset_previous;

int tempo = 120;
unsigned long time_now = 0;

//const int clkIn = 2;           // the digital (clock) input
//const int rstClkIn = 7;       // The Reset Clock Input // Need to change this to 7 as used on Euclidean template
const int trigTime = 25;       // 25 ms trigger timing

unsigned long digMilli[2] = {0, 0};  // a place to store millis()


int Position = 0;

int Sector = 0;                          // I have no idea what I'm doing... but it works... in a way.
float BDrum = 0;
float SDrum = 0;
float HHats = 0;
float OHats = 0;

int tempoLED = 13;


void setup() {

  if (isDebuggin)Serial.begin(9600);


  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);

  // pinMode(rstClkIn, INPUT_PULLUP);

  /// Setup the Drum Out Pins

  pinMode(BDrum_Out, OUTPUT);
  digitalWrite(BDrum_Out, LOW);

  pinMode(SDrum_Out, OUTPUT);
  digitalWrite(SDrum_Out, LOW);

  pinMode(HHats_out, OUTPUT);
  digitalWrite(HHats_out, LOW);

  pinMode(OHats_out, OUTPUT);
  digitalWrite(OHats_out, LOW);

  // Note: Interrupt 0 is for pin 2 (clkIn)
  // attachInterrupt(0, isr, RISING);
}

void isr()
{
  clkState = HIGH;
}



void loop() {

  if (millis() > time_now + tempo) {
    time_now = millis();
    nextStep();
  }
}

void nextStep() {



  digMilli[0] = millis();
  //tempo = analogRead(0) >> 7;

  //

  BDfreq = analogRead(A1);                              // read bass drum density pot
  BDfreq = map(BDfreq, 0, 1023, 255, 0);
  SDfreq = BDfreq;

  // remap it to values similar to those in cluster configurations
  // SDfreq = analogRead(A1);                              // read snare drum density pot
  // SDfreq = map(SDfreq, 0, 1023, 255, 0);                // remap it to values similar to those in cluster configurations
  HHfreq = analogRead(A0);                              // read hi hat density pot
  HHfreq = map(HHfreq, 0, 1023, 255, 0);
  OHfreq = HHfreq; // remap it to values similar to those in cluster configurations
  //OHfreq = analogRead(A3);                              // read hi hat density pot
  // OHfreq = map(OHfreq, 0, 1023, 255, 0);                // remap it to values similar to those in cluster configurations

  // read the X-pot for cluster navigation
  Xmap = analogRead(A2);     //Added External Cv control
  // Serial.print("Xmap");
  // Serial.print(Xmap);
  Xmap = map(Xmap, 0, 1023, -100, 100);                 // remap around zero

  if (!digitalRead(leftButtonPin)) {
    //if left button is pressed, change the tempo, in milisecons per beat
    tempo = map(analogRead(A3), 0, 1023, 300, 30); 
    
  } else {
    //else change map

    Ymap = analogRead(A3) ;       //Added External Cv control
    Ymap = map(Ymap, 0, 1023, -100, 100);                   // remap around zero
  }
  if (Xmap < 0 && Ymap < 0) Sector = 1;
  if (Xmap < 0 && Ymap > 0) Sector = 2;
  if (Xmap >= 0 && Ymap >= 0) Sector = 3;
  if (Xmap >= 0 && Ymap <= 0) Sector = 4;               // determine sector - which 4 clusters do we want to interpolate

  Xmap = abs(Xmap / 100);
  Ymap = abs(Ymap / 100);                               // get rid off negative values and make it smaller


  if (Sector == 1) {
    SDrum = ( ( (SDcluster1[Position] * Xmap) + (SDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
    BDrum = ( ( (BDcluster1[Position] * Xmap) + (BDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
    HHats = ( ( (HHcluster1[Position] * Xmap) + (HHcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
    OHats = ( ( (OHcluster1[Position] * Xmap) + (OHcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (OHcluster4[Position] * Xmap) + (OHcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
  }

  if (Sector == 2) {
    SDrum = ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (SDcluster7[Position] * Xmap) + (SDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
    BDrum = ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (BDcluster7[Position] * Xmap) + (BDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
    HHats = ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (HHcluster7[Position] * Xmap) + (HHcluster8[Position] * (1 - Xmap) ) ) * Ymap );
    OHats = ( ( (OHcluster4[Position] * Xmap) + (OHcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (OHcluster7[Position] * Xmap) + (OHcluster8[Position] * (1 - Xmap) ) ) * Ymap );
  }

  if (Sector == 3) {
    SDrum = ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (SDcluster8[Position] * ( 1 - Xmap )) + (SDcluster9[Position] * Xmap ) ) * Ymap );
    BDrum = ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (BDcluster8[Position] * ( 1 - Xmap )) + (BDcluster9[Position] * Xmap ) ) * Ymap );
    HHats = ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (HHcluster8[Position] * ( 1 - Xmap )) + (HHcluster9[Position] * Xmap ) ) * Ymap );
    OHats = ( ( (OHcluster5[Position] * ( 1 - Xmap ) ) + (OHcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (OHcluster8[Position] * ( 1 - Xmap )) + (OHcluster9[Position] * Xmap ) ) * Ymap );
  }

  if (Sector == 4) {
    SDrum = ( ( (SDcluster2[Position] * ( 1 - Xmap ) ) + (SDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
    BDrum = ( ( (BDcluster2[Position] * ( 1 - Xmap ) ) + (BDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
    HHats = ( ( (HHcluster2[Position] * ( 1 - Xmap ) ) + (HHcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
    OHats = ( ( (OHcluster2[Position] * ( 1 - Xmap ) ) + (OHcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (OHcluster5[Position] * ( 1 - Xmap ) ) + (OHcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
  }

  ///////////////////////////////// above are the equations for interpolating between values. Nothing fancy.


  if (BDrum > BDfreq) {
    digitalWrite(BDrum_Out, HIGH);
    digitalWrite(out1Pin, HIGH);
  }


  if (SDrum > SDfreq) {
    digitalWrite(SDrum_Out, HIGH);
    digitalWrite(out2Pin, HIGH);
  }


  if (HHats > HHfreq) {
    digitalWrite(HHats_out, HIGH);
    digitalWrite(out3Pin, HIGH);
  }


  if (OHats > OHfreq) {
    digitalWrite(OHats_out, HIGH);
    digitalWrite(out4Pin, HIGH);
  }


  Position ++;                       // increase the step count

  digitalWrite(tempoLED, HIGH);       // blink led every step
  delay(20);
  digitalWrite(tempoLED, LOW);

  //delay(tempo);                                               // step lenght



  // Turn the off the Digital Outs
  for (int i = 0; i < 2; i++) {
    if ((millis() - digMilli[i] > trigTime)) {
      digitalWrite(BDrum_Out, LOW);
      digitalWrite(SDrum_Out, LOW);
      digitalWrite(HHats_out, LOW);
      digitalWrite(OHats_out, LOW);
      digitalWrite(out1Pin, LOW);
      digitalWrite(out2Pin, LOW);
      digitalWrite(out3Pin, LOW);
      digitalWrite(out4Pin, LOW);
    }
  }

  if (Position > 16) {// This resets to step 1
    Position = 0;

    //reset not working
    /*
        reset_current = digitalRead(rstClkIn);

        if (reset_current != reset_previous) {
          reset_previous = reset_current;

          if (reset_current == 1) {
            Position = 0;
          }
    */

    // Read the Pot Values for debugging // Comment out if not Debugging

    // Serial.print(analogRead(0));   // print the A2 input
    //Serial.print('\t');            // print a tab character
    //Serial.print(analogRead(1));   // print the A2 input
    //Serial.print('\t');            // print a tab character
    //Serial.print(analogRead(2));   // print the A2 input
    //Serial.print('\t');            // print a tab character
    //Serial.print(analogRead(3));   // print the A3 input
    //Serial.print('\t');            // print a tab character
    //Serial.print(analogRead(4));   // print the A3 input
    //Serial.print('\t');            // print a tab character
    //Serial.print(analogRead(5));   // print the A3 input
    //Serial.println();              // line feed

  }

}
