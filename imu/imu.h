/*
 * imu.h
 *
 *  Created on: Oct 23, 2014
 *      Author: jcobb
 */

#ifndef IMU_H_
#define IMU_H_

#include "../util/defines.h"

#define IMU_ADDRESS			0x68
#define IMU_BUFFER_LENGTH	14

uint8_t imu_address;
uint8_t imu_buffer[IMU_BUFFER_LENGTH];

void imu_init();
void imu_tick();
bool imu_test();
void imu_read6(uint16_t *ax, uint16_t *ay, uint16_t *az, uint16_t *gx, uint16_t *gy, uint16_t *gz);
void imu_read9(uint16_t *ax, uint16_t *ay, uint16_t *az, uint16_t *gx, uint16_t *gy, uint16_t *gz, uint16_t *mx, uint16_t *my, uint16_t *mz);

#endif /* IMU_H_ */
