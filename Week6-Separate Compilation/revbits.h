/**
 * @file revbits.h
 * @author Hengyi Li
 * @brief This file is the header of the revbits.c
 * @version 0.1
 * @date 2021-10-15 11:27 PM
 * @copyright Copyright (c) 2021 Hengyi Li. All rights served
 */

#include <stdint.h>
#include <stdio.h>
#include "atoh.h"
#define MOVE_ONE_BITS 1

/**
 * @brief This function is to Mirror image reverse 8 bits value. 
 * @param value is the value to be reversed
 * @return uint8_t  is the reversed value
 */
uint8_t revbits8(uint8_t value);

/**
 * @brief This function is to Mirror image reverse 16 bits value. 
 * @param value is the value to be reversed
 * @return uint16_t  is the reversed value
 */
uint16_t revbits16(uint16_t value);
