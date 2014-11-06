/*
 * itg3200.c
 *
 *  Created on: 3 oct. 2014
 *      Author: ldo
 *
 * The ITG-3200 is a 3-axis MEMS gyroscope with digital outputs.
 * It features three 16-bit analog-to-digital converters for digitizing the gyro outputs,
 * a user-selectable internal low-pass filter bandwidth, and a fast-mode I2C (400 KHz) interface.
 * Digital-output X-, Y- and Z-axis angular rate sensors (gyros) on one integrated circuit
 * with a sensitivity of 14.375 LSBs per °/sec end full-scale range of +/- 2000°/sec.
 * It includes a digital-output temperature sensor with a sensitivity of 280 LSB per °C.
 */

#include "itg3200.h"

/*
 * \fn void itg3200_setup (void)
 * \brief setup i2c interface
 * */
void
itg3200_setup (void)
{
  volatile uint8_t buffer[2];

  twi_master_setup (/*SCL_FREQ_100*/);

  buffer[0] = DLPF;
  buffer[1] = FS_SEL | DLPF_256_Hz;
  twi_write_bytes (ITG3200_ADDRESS, 2, buffer);
}

/**
 * \fn uint8_t itg3200_read_device_id (void)
 * \brief read device ID
 * \return I2C address of the device
 * */
uint8_t
itg3200_read_device_id (void)
{
  volatile uint8_t device_id;
  volatile uint8_t reg = WHO_AM_I;

  twi_read_bytes (ITG3200_ADDRESS, &reg, 1, &device_id);

  return device_id;
}

/*
 * \fn double itg3200_read_temp (void)
 * \brief read temperature
 * \return temperature in °C
 * */
double
itg3200_read_temperature (void)
{
  volatile uint8_t reg = TEMP_OUT_H;
  volatile uint8_t buffer[2];
  volatile double temperature;

  twi_read_bytes (ITG3200_ADDRESS, &reg, 2, buffer);

  temperature = (buffer[0] << 8) + buffer[1];
  temperature += TEMP_OFFSET;
  temperature /= TEMP_SENSITIVITY;

  return temperature;
}

/*
 * \fn xyz itg3200_read_gyro_xyz (void)
 * \brief read x, y and z gyro output data
 * \return x, y and z gyro output data in °/sec
 * */
xyz
itg3200_read_gyro_xyz (void)
{
  volatile uint8_t reg = GYRO_XOUT_H;
  volatile uint8_t buffer[6];
  volatile xyz gyro;

  twi_read_bytes (ITG3200_ADDRESS, &reg, 6, buffer);

  gyro.x = ((buffer[0] << 8) + buffer[1]) / GYRO_SENSITIVITY;
  gyro.y = ((buffer[2] << 8) + buffer[3]) / GYRO_SENSITIVITY;
  gyro.z = ((buffer[4] << 8) + buffer[5]) / GYRO_SENSITIVITY;

  return gyro;
}
