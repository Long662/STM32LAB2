/*
 * Lab2_Ex.c
 *
 *  Created on: Sep 24, 2024
 *      Author: HP WORK
 */

#include "Lab2_Ex.h"

void Lab2_Init(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);

	LED7SEG_Init(&LED7SEG,	SEG0_GPIO_Port, SEG0_Pin,
							SEG1_GPIO_Port, SEG1_Pin,
							SEG2_GPIO_Port, SEG2_Pin,
							SEG3_GPIO_Port, SEG3_Pin,
							SEG4_GPIO_Port, SEG4_Pin,
							SEG5_GPIO_Port, SEG5_Pin,
							SEG6_GPIO_Port, SEG6_Pin);
}

void display7SEG(int num){
	LED7SEG_Write(&LED7SEG, num);
}

//---------------------------------------------------
// BEGIN function for exercise 2
void Enable_led7seg(int num){
	switch (num){
		case 0: HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
				break;
		case 1: HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				break;
		case 2: HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				break;
		case 3: HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				break;
	}
}
// END of function for exercise 2
//---------------------------------------------------


//---------------------------------------------------
// BEGIN function for exercise 3
const int MAX_LED = 4;
int led_buffer[4];

void update7SEG(int index) {
	switch (index) {
		case 0:	//Display the first 7 SEG with led_buffer [0]
				Enable_led7seg(3);
				display7SEG(led_buffer[index]);
				break;
		case 1:	//Display the second 7 SEG with led_buffer [0]
				Enable_led7seg(2);
				display7SEG(led_buffer[index]);
				break;
		case 2:	//Display the third 7 SEG with led_buffer [0]
				Enable_led7seg(1);
				display7SEG(led_buffer[index]);
				break;
		case 3:	//Display the fourth 7 SEG with led_buffer [0]
				Enable_led7seg(0);
				display7SEG(led_buffer[index]);
				break;
		default://DO NOT THING
				break;
	}
}
// END of function for exercise 3
//---------------------------------------------------

//---------------------------------------------------
// BEGIN function for exercise 5
void updateClockBuffer(int hr_ind, int min_ind){
//	if (hr_ind >= 10) {
//		led_buffer[0] = hr_ind / 10;
//		led_buffer[1] = hr_ind % 10;
//	}
//	else {
//		led_buffer[0] = 0;
//		led_buffer[1] = hr_ind;
//	}
//	if (min_ind < 10) {
//		led_buffer[2] = 0;
//		led_buffer[3] = min_ind;
//	}
//	else {
//		led_buffer[2] = min_ind / 10;
//		led_buffer[3] = min_ind % 10;
//	}
	led_buffer[0] = hr_ind / 10;
	led_buffer[1] = hr_ind % 10;
	led_buffer[2] = min_ind / 10;
	led_buffer[3] = min_ind % 10;
}
// END of function for exercise 5
//---------------------------------------------------

//---------------------------------------------------
// BEGIN function for exercise 9
uint16_t COLUMS_PINS[8] = {ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin, ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin};
//uint16_t COLUMS_PINS = (ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin);
//uint16_t ROWS_PINS[8] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin, ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin};
uint16_t ROWS_PINS = (ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin);

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};//quét theo hàng

void updateLEDMatrix(int index){
	switch (index){
	case 0:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW0_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 1:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW1_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 2:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW2_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 3:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW3_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 4:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW4_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 5:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW5_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 6:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW6_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	case 7:	HAL_GPIO_WritePin(GPIOB, ROWS_PINS, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, ROW7_Pin, GPIO_PIN_RESET);
			for (int col = 0; col < 8; col++) {
				if (matrix_buffer[index] & (1 << col)) {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_RESET);
				}
				else {
					HAL_GPIO_WritePin(GPIOA, COLUMS_PINS[col], GPIO_PIN_SET);
				}
			}
			break;
	default:
			break;
	}
}
// END of function for exercise 9
//---------------------------------------------------
