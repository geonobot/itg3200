/*
 * itg3200.h
 *
 *  Created on: 3 oct. 2014
 *      Author: ldo
 */

#ifndef ITG3200_H_
#define ITG3200_H_

#include "twi.h"
#include "imu.h"

#define ITG3200_ADDRESS 0x68 // 7-bits i2c address

/* sensitivity and offset */
#define TEMP_SENSITIVITY 280 // 280 LSB per °C
#define TEMP_OFFSET (13200 + 35*TEMP_SENSITIVITY) // 13200 LSB + 35°C
#define GYRO_SENSITIVITY 14.375 // 14.375 LSB per °/s

/* Register map */
#define WHO_I_AM 0x00
#define TEMP_OUT_H 0x1B
#define TEMP_OUT_L 0x1C
#define GYRO_XOUT_H 0x1D
#define GYRO_XOUT_L 0x1E
#define GYRO_YOUT_H 0x1F
#define GYRO_YOUT_L 0x20
#define GYRO_ZOUT_H 0x21
#define GYRO_ZOUT_L 0x22

void
itg3200_setup (void);

uint8_t
itg3200_read_device_id (void);

double
itg3200_read_temperature (void);

xyz
itg3200_read_gyro_xyz (void);

#endif /* ITG3200_H_ */
