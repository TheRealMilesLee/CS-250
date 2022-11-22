/**
 * @file atoh.h
 * @author Hengyi Li
 * @brief This file is the header file of the atoh.c
 * @version 0.1
 * @date 2021-10-15 11:24PM
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved
 */

#include <stdio.h>
#include <stdint.h>
#define FIRST_INDEX 0
#define SECOND_INDEX 1
#define NEXT_INDEX 1
#define THIRD_INDEX 2
#define FIRST_DIGIT 2
#define SECOND_DIGIT 3
#define THIRD_DIGIT 4
#define LAST_DIGITS 5
#define MOVE_BITS 4

/**
 * @brief This function is to convert ascii to hex under 8 bits value
 * @param string is the ASCII character that needs to be converted
 * @return uint8_t is the hexadecimal number that ascii converted to
 */
uint8_t atoh8(const char* string);

/**
 * @brief This function is to convert ascii to hex under 16 bits value
 * @param string is the ASCII character that needs to be converted
 * @return uint16_t is the hexadecimal number that ascii converted to
 */
uint16_t atoh16(const char* string);

/**
 * @brief This function is to convert the 16 bits char into the hexadecimal
 * numbers
 * @param digit is the char character that needs to be converted
 * @return uint16_t is the hexadecimal numbers that returned and send it to
 * the revbits function
 */
uint16_t hexdigit_converted_16bits(char digit);

/**
 * @brief This function is to convert the 8 bits char into the hexadecimal
 * numbers
 * @param digit is the the char character that needs to be converted
 * @return uint16_t is the hexadecimal numbers that returned and send it to
 * the revbits function
 */
uint8_t hexdigit_convert_8bits(char digit);
