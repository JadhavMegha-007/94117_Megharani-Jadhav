/*
 * switch_seq.h
 *
 *  Created on: Dec 18, 2025
 *      Author: nk
 */

#ifndef SWITCH_SEQ_H_
#define SWITCH_SEQ_H_
#include<stdio.h>
#include<stdint.h>
#include"stm32F407xx.h"
#define BV(n) (1 << (n))

void switch_init(void);
int switch_status(void);



#endif /* SWITCH_SEQ_H_ */
