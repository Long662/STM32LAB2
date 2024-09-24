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
