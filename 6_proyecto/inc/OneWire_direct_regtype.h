#ifndef OneWire_Direct_RegType_h
#define OneWire_Direct_RegType_h

#include <stdint.h>
#include "sapi.h" // @Eric

// Platform specific I/O register type

#if defined(__AVR__)
#define IO_REG_TYPE uint8_t

#elif defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MK66FX1M0__) || defined(__MK64FX512__)
#define IO_REG_TYPE uint8_t

#elif defined(ciaa_nxp) || defined(edu_ciaa_nxp)
#define IO_REG_TYPE           uint32_t
#define millis                tickRead
#define interrupts()
#define noInterrupts()
#define delayMicroseconds     delayInaccurateUs
#ifndef PROGMEM
#define PROGMEM
#endif
#ifndef pgm_read_byte
#define pgm_read_byte(addr)   (*(const uint8_t *)(addr))
#endif


#elif defined(__MKL26Z64__)
#define IO_REG_TYPE uint8_t

#elif defined(__SAM3X8E__) || defined(__SAM3A8C__) || defined(__SAM3A4C__)
#define IO_REG_TYPE uint32_t

#elif defined(__PIC32MX__)
#define IO_REG_TYPE uint32_t

#elif defined(ARDUINO_ARCH_ESP8266)
#define IO_REG_TYPE uint32_t

#elif defined(ARDUINO_ARCH_ESP32)
#define IO_REG_TYPE uint32_t
#define IO_REG_MASK_ATTR

#elif defined(__SAMD21G18A__)
#define IO_REG_TYPE uint32_t

#elif defined(RBL_NRF51822)
#define IO_REG_TYPE uint32_t

#elif defined(__arc__) /* Arduino101/Genuino101 specifics */
#define IO_REG_TYPE uint32_t

#elif defined(__riscv)
#define IO_REG_TYPE uint32_t

#else
#define IO_REG_TYPE unsigned int

#endif
#endif
