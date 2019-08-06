/*
 * Forked from : https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P
 * 
 * Prime number benchmark sketch compatible with :
 *  - ATmega32x Arduino boards
 *  - LGT8Fx boards
 *  - STM32 boards
 * 
 * Calculate 10,000 prime numbers :
 * 
 *  ATmega328p @ 16MHz : 121 seconds (Duemilanove made in Italy)
 *  ATmega328p @ 16MHz : 121 seconds (Uno + CH340 made in China)
 *  ATmega32u4 @ 16MHz : 120 seconds (Leonardo made in Italy)
 *  ATmega32u4 @ 16MHz : 120 seconds (Leonardo Micro made in China)
 *  ATmega328p @  8MHz : 242 seconds (Mini pro 3.3V made in China)
 *  
 *  LGT8F328p  @ 16MHz : 118 seconds using default Arduino Nano stuff (old bootloader)
 *  LGT8F328p  @ 16MHz : 118 seconds using Larduino_HSP
 *  LGT8F328p  @ 32MHz :  59 seconds using Larduino_HSP
 *  
 *  STM32F103  @ 72MHz :   3 seconds using Arduino_Core_STM32 ("Blue Pill" made in China)
 *  
 */

#ifdef _AVR_COMMON_H
// Must include this to be able change the prescaler frequency
#include <avr/power.h> 
#endif

long start       = 0;
long max_primes = 10000;
long i           = 2; // Start at 2
long found       = 0; // Number of primes we've found
long lastPrime   = 0;
long lastfound = found;

//#define DISPLAY_OUTPUT 1

void setup() {
  
  #ifdef _AVR_COMMON_H
    byte default_clkpr = CLKPR;
    
    #ifdef __LGT8F__ // <-- if using Larduino_HSP
      bool lgt8f_detected = true;
    #else
      bool lgt8f_detected = CLKPR == 3; // <-- LGFP32 MiniEVB runs at 4MHz if using default Arduino Nano config
    #endif
       
    if ( lgt8f_detected ) {
      // the MCU Frequency is described in ~\Arduino Sketches\hardware\LGT\avr\boards.txt
      // on this line: lardu_328x.build.f_cpu=32000000L
    
      clock_prescale_set( F_CPU == 32000000 ? clock_div_1 : clock_div_2 );
    }
  #endif

  // Wait for serial to initialise
  Serial.begin(9600);
  while (!Serial) { }

  
  pinMode(5, OUTPUT); // init beeper pin
  beep(2); // In case the serial output is corrupt let's beep the start

  Serial.print("F_CPU value: "); Serial.println(F_CPU);
  Serial.print("Clock cycles per µsecond: "); Serial.println(clockCyclesPerMicrosecond());

  #ifdef _AVR_COMMON_H
    if ( lgt8f_detected ) {
      Serial.print("LGT8Fx detected");
    }
    Serial.print("CLKPR : "); Serial.print( default_clkpr ); Serial.print(" -> "); Serial.println( CLKPR );
  #endif
  
  #ifdef GUID0
    uint32_t guid = *(uint32_t*)&GUID0 ;
    Serial.print("GUID of this device: "); Serial.println(guid, HEX);
  #endif

  // Go!
  Serial.println("Prime calculation starting.");

#ifdef DISPLAY_OUTPUT
  Serial.print("0: ");
#endif
  start = millis();
}

void loop() {
  int prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) {
#ifdef DISPLAY_OUTPUT
    Serial.print(i); Serial.print(" ");
#endif
    lastPrime = i;
    found++;
  }

  int running_seconds = (millis() - start) / 1000;

  if (found >= max_primes) {
    Serial.print("\nFound ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(running_seconds);
    Serial.println(" seconds");
    Serial.print("Highest prime found was: ");
    Serial.println(lastPrime);
    //beep(3);
    delay(60000);

    i     = 2;
    found = 0;
    lastPrime = 0;
    Serial.println("Prime calculation starting (again)");
    start = millis();
  }
  else {
    i++;
#ifdef DISPLAY_OUTPUT
    if (found != lastfound && found % 10 == 0) {
      Serial.println(""); Serial.print(found); Serial.print(": ");
      lastfound = found;
    }
#endif
  }
}

int is_prime(long num) {
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (long cnum = 2; cnum <= upper; cnum++) {
    long mod = num % cnum; // Remainder

    if (mod == 0) {
      return 0;
    } // If the remainder is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}

void beep(int count) {
  for (auto cnt = 0; cnt < count; cnt++) {
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    delay(200);
  }
}
