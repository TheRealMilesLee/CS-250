#include <stdio.h>
#include <stdint.h>

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
 * @brief This function is to convert the 16 bits char into the hexadecimal numbers
 * @param digit is the char character that needs to be converted
 * @return uint16_t is the hexadecimal numbers that returned and send it to the revbits function
 */
uint16_t hexdigit_converted_16bits(char digit);

/**
 * @brief This function is to convert the 8 bits char into the hexadecimal numbers
 * @param digit is the the char character that needs to be converted
 * @return uint16_t is the hexadecimal numbers that returned and send it to the revbits function
 */
uint8_t hexdigit_converted_8bits(char digit);
