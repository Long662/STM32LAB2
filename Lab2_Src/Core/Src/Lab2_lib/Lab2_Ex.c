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
int led_buffer[4] = {1 , 2 , 3 , 4};

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
	led_buffer[0] = hr_ind / 10;
	led_buffer[1] = hr_ind % 10;
	led_buffer[2] = min_ind / 10;
	led_buffer[3] = min_ind % 10;
}
// END of function for exercise 5
//---------------------------------------------------
