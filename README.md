# Arduino_prime_number_benchmark

A single prime number benchmark sketch.

forked from : https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P

Modifications : 

* [x] runs out of the box on LGT8Fx boards @ 16MHz using default Arduino Nano core.
* [x] runs out of the box on LGT8Fx boards @ 32MHz and 16MHz using Larduino_HSP core.
* [x] runs out of the box on old Arduino boards that does not have GUID
* [x] runs out of the box on non AVR boards

Calculate 10,000 prime numbers :

- ATmega328p @ 16MHz : 121 seconds (Duemilanove made in Italy)
- ATmega328p @ 16MHz : 121 seconds (Uno + CH340 made in China)
- ATmega32u4 @ 16MHz : 120 seconds (Leonardo made in Italy)
- ATmega32u4 @ 16MHz : 120 seconds (Leonardo Micro made in China)
- ATmega328p @  8MHz : 242 seconds (Mini pro 3.3V made in China)
  
- LGT8F328p  @ 16MHz : 118 seconds using default Arduino Nano stuff (old bootloader)
- LGT8F328p  @ 16MHz : 118 seconds using Larduino_HSP
- LGT8F328p  @ 32MHz :  59 seconds using Larduino_HSP
  
- STM32F103  @ 72MHz :   3 seconds using Arduino_Core_STM32 ("Blue Pill" made in China)

| MCU | Clock | Benchmark | SDK |
|:---:|:---:|:---:|:---:|
| ATmega328p | 16MHz | 121 s. | |
| ATmega32u4 | 16MHz | 120 s. | |
| ATmega328p | 8MHz  | 242 s. | |
| LGT8F328p  | 16MHz | 118 s. | default Arduino Nano SDK (old bootloader) |
| LGT8F328p  | 16MHz | 118 s. | Larduino_HSP SDK |
| LGT8F328p  | 32MHz | 59 s. | Larduino_HSP SDK |
| STM32F103  | 72MHz | 3 s. | Arduino Core STM32 SDK |
