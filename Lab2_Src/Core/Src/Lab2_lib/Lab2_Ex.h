/*
 * Lab2_Ex.h
 *
 *  Created on: Sep 24, 2024
 *      Author: HP WORK
 */

#ifndef SRC_LAB2_LIB_LAB2_EX_H_
#define SRC_LAB2_LIB_LAB2_EX_H_

#include "main.h"
#include "MyLED7SEG.h"

void Lab2_Init();

// Exercise 1
LED7SEG_Name LED7SEG;
void display7SEG(int num);

// Exercise 2
void Enable_led7seg(int num); // 0 - 3

// Exercise 3
void update7SEG(int index);

// Exercise 5
void updateClockBuffer(int hr_ind, int min_ind);

// Exercise 9
void updateLEDMatrix(int index);

// Exercise 10
void shift_left();

#endif /* SRC_LAB2_LIB_LAB2_EX_H_ */
