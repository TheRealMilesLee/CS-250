#include <stdio.h>
#include <stdint.h>
#define HEX_CHARACTER_PLACE 2
#define NEXT_HEX_CHARACTER_PLACE 3
#define MOVE_FOUR_BIT_FOR_PLACE 4

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