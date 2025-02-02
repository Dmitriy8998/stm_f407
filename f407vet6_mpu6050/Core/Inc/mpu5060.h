#include "stdint.h"
#include "stm32f4xx_hal.h"

#ifndef INC_MPU5060_H_
#define INC_MPU5060_H_

typedef struct {
    int16_t GYRO_DATA_X_THUMB;
    int16_t GYRO_DATA_Y_THUMB;
    int16_t GYRO_DATA_Z_THUMB;
    int16_t ACCEL_DATA_X_THUMB;
    int16_t ACCEL_DATA_Y_THUMB;
    int16_t ACCEL_DATA_Z_THUMB;

    int16_t GYRO_DATA_X_INDEX;
    int16_t GYRO_DATA_Y_INDEX;
    int16_t GYRO_DATA_Z_INDEX;
    int16_t ACCEL_DATA_X_INDEX;
    int16_t ACCEL_DATA_Y_INDEX;
    int16_t ACCEL_DATA_Z_INDEX;

    int16_t GYRO_DATA_X_MIDDLE;
    int16_t GYRO_DATA_Y_MIDDLE;
    int16_t GYRO_DATA_Z_MIDDLE;
    int16_t ACCEL_DATA_X_MIDDLE;
    int16_t ACCEL_DATA_Y_MIDDLE;
    int16_t ACCEL_DATA_Z_MIDDLE;

    int16_t GYRO_DATA_X_RING;
    int16_t GYRO_DATA_Y_RING;
    int16_t GYRO_DATA_Z_RING;
    int16_t ACCEL_DATA_X_RING;
    int16_t ACCEL_DATA_Y_RING;
    int16_t ACCEL_DATA_Z_RING;

    int16_t GYRO_DATA_X_BABY;
    int16_t GYRO_DATA_Y_BABY;
    int16_t GYRO_DATA_Z_BABY;
    int16_t ACCEL_DATA_X_BABY;
    int16_t ACCEL_DATA_Y_BABY;
    int16_t ACCEL_DATA_Z_BABY;
} DataLeftHand;

#define SMPLRT_DIV		0x19
#define CONFIG			0x1A
#define GYRO_CONFIG		0x1B
#define ACCEL_CONFIG	0x1C
#define ACCEL_XOUT_H	0x3B
#define GYRO_XOUT_H		0x43
#define PWR_MGMT_1		0x6B
#define WHO_AM_I		0x75

#define GYRO_XOUT_H	0x43
#define GYRO_XOUT_L	0x44
#define GYRO_YOUT_H	0x45
#define GYRO_YOUT_L	0x46
#define GYRO_ZOUT_H	0x47
#define GYRO_ZOUT_L	0x48

#define WHO_AM_I_CHECKED	0x68

#define ADRES_MPU_6050_LOW		0b01101000 << 1
#define ADRES_MPU_6050_HIGHT	0b01101001 << 1

void check_i2c();
void mpu5060_check_sensors();
void mpu5060_register_configuration();
void mpu_5060_read_gyro(DataLeftHand *data);

#endif /* INC_MPU5060_H_ */
