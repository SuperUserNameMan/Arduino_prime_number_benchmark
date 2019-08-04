# Arduino_ATmega_vs_LGT8Fx_prime_number_benchmark
A single prime number benchmark sketch that runs on both ATmega32x and LGT8Fx Arduino compatible boards

forked from : https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P

Modifications : runs out of the box on both ATmega32 boards and LGT8Fx boards.

/*
 * Prime number benchmark compatible with standard Arduino boards and with LGT8Fx MCU boards
 * 
 * Calculate 10,000 prime numbers :
 * 
 *  ATmega328p @ 16MHz : 121 seconds (Duemilanove made in Italy)
 *  ATmega328p @ 16MHz : 121 seconds (Uno + CH340 made in China)
 *  ATmega32u4 @ 16MHz : 120 seconds (Leonardo made in Italy)
 *  ATmega32u4 @ 16MHz : 120 seconds (Leonardo Micro made in China)
 *  ATmega328p @  8MHz : 242 seconds (Mini pro 3.3V made in China)
 *
 *  LGT8F328p  @ 16MHz : 118 seconds using default Arduino Nano config (old bootloader)
 *  LGT8F328p  @ 16MHz : 118 seconds using Larduino_HSP
 *  LGT8F328p  @ 32MHz :  59 seconds using Larduino_HSP
 *  
 */
