#include <mpu5060.h>
#include <main.h>

#include "string.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c3;

//TODO: Rewrite this code later
void mpu5060_check_sensors()
{
	uint8_t mpu6050_thumb_check = 0;
	uint8_t mpu6050_index_check = 0;
	uint8_t mpu6050_middle_check = 0;
	uint8_t mpu6050_ring_check = 0;
	uint8_t mpu6050_baby_check = 0;

	HAL_I2C_Mem_Read(&hi2c3, ADRES_MPU_6050_LOW, WHO_AM_I, 1, &mpu6050_thumb_check, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, ADRES_MPU_6050_LOW, WHO_AM_I, 1, &mpu6050_index_check, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, ADRES_MPU_6050_HIGHT, WHO_AM_I, 1, &mpu6050_middle_check, 1, 100);
	HAL_I2C_Mem_Read(&hi2c2, ADRES_MPU_6050_LOW, WHO_AM_I, 1, &mpu6050_ring_check, 1, 100);
	HAL_I2C_Mem_Read(&hi2c2, ADRES_MPU_6050_HIGHT, WHO_AM_I, 1, &mpu6050_baby_check, 1, 100);

	if(mpu6050_index_check==WHO_AM_I_CHECKED)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);
	if(mpu6050_index_check==WHO_AM_I_CHECKED)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	if(mpu6050_middle_check==WHO_AM_I_CHECKED)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
	if(mpu6050_ring_check==WHO_AM_I_CHECKED)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
	if(mpu6050_baby_check==WHO_AM_I_CHECKED)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);

}

void mpu5060_register_configuration()
{
	uint8_t PWR_MGMT_1_Reg_Value =	0x00;
	uint8_t SMPLRT_DIV_Reg_Value =	0x07;
	uint8_t CONFIG_Reg_Value =		0x00;
	uint8_t GYRO_CONFIG_Reg_Value =	0x00;

	//thumb
	HAL_I2C_Mem_Write(&hi2c3, ADRES_MPU_6050_LOW, PWR_MGMT_1,	 1, &PWR_MGMT_1_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c3, ADRES_MPU_6050_LOW, SMPLRT_DIV,	 1, &SMPLRT_DIV_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c3, ADRES_MPU_6050_LOW, CONFIG,		 1, &CONFIG_Reg_Value,	    1, 100);
	HAL_I2C_Mem_Write(&hi2c3, ADRES_MPU_6050_LOW, GYRO_CONFIG,   1, &GYRO_CONFIG_Reg_Value, 1, 100);
	//index finger
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_LOW, PWR_MGMT_1,	 1, &PWR_MGMT_1_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_LOW, SMPLRT_DIV,	 1, &SMPLRT_DIV_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_LOW, CONFIG,		 1, &CONFIG_Reg_Value,	    1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_LOW, GYRO_CONFIG,   1, &GYRO_CONFIG_Reg_Value, 1, 100);
	//middle finger
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_HIGHT, PWR_MGMT_1,	 1, &PWR_MGMT_1_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_HIGHT, SMPLRT_DIV,	 1, &SMPLRT_DIV_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_HIGHT, CONFIG,		 1, &CONFIG_Reg_Value,	    1, 100);
	HAL_I2C_Mem_Write(&hi2c1, ADRES_MPU_6050_HIGHT, GYRO_CONFIG, 1, &GYRO_CONFIG_Reg_Value, 1, 100);
	//ring finger
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_LOW, PWR_MGMT_1,	 1, &PWR_MGMT_1_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_LOW, SMPLRT_DIV,	 1, &SMPLRT_DIV_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_LOW, CONFIG,		 1, &CONFIG_Reg_Value,	    1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_LOW, GYRO_CONFIG,   1, &GYRO_CONFIG_Reg_Value, 1, 100);
	//baby finger
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_HIGHT, PWR_MGMT_1,	 1, &PWR_MGMT_1_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_HIGHT, SMPLRT_DIV,	 1, &SMPLRT_DIV_Reg_Value,  1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_HIGHT, CONFIG,		 1, &CONFIG_Reg_Value,	    1, 100);
	HAL_I2C_Mem_Write(&hi2c2, ADRES_MPU_6050_HIGHT, GYRO_CONFIG, 1, &GYRO_CONFIG_Reg_Value, 1, 100);
}

void mpu_5060_read_gyro(GyroDataLeftHand *data)
{
	uint8_t Rec_Data[6] = {0};

	// Read 6 BYTES of data starting from GYRO_XOUT_H register

	HAL_I2C_Mem_Read (&hi2c3, ADRES_MPU_6050_LOW, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
	float GYRO_X_RAW_THUMB = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	float GYRO_Y_RAW_THUMB = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	float GYRO_Z_RAW_THUMB = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
	data->GYRO_DATA_X_THUMB = (float)GYRO_X_RAW_THUMB/131.0;
	data->GYRO_DATA_Y_THUMB = (float)GYRO_Y_RAW_THUMB/131.0;
	data->GYRO_DATA_Z_THUMB = (float)GYRO_Z_RAW_THUMB/131.0;
	memset(Rec_Data, 0, sizeof(Rec_Data));

	HAL_I2C_Mem_Read (&hi2c1, ADRES_MPU_6050_LOW, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
	float GYRO_X_RAW_INDEX = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	float GYRO_Y_RAW_INDEX = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
    float GYRO_Z_RAW_INDEX = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
    data->GYRO_DATA_X_INDEX = (float)GYRO_X_RAW_INDEX/131.0;
    data->GYRO_DATA_Y_INDEX = (float)GYRO_Y_RAW_INDEX/131.0;
    data->GYRO_DATA_Z_INDEX = (float)GYRO_Z_RAW_INDEX/131.0;
    memset(Rec_Data, 0, sizeof(Rec_Data));

    HAL_I2C_Mem_Read (&hi2c1, ADRES_MPU_6050_HIGHT, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
    float GYRO_X_RAW_MIDDLE = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
   	float GYRO_Y_RAW_MIDDLE = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
    float GYRO_Z_RAW_MIDDLE = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
	data->GYRO_DATA_X_MIDDLE = (float)GYRO_X_RAW_MIDDLE/131.0;
	data->GYRO_DATA_Y_MIDDLE = (float)GYRO_Y_RAW_MIDDLE/131.0;
	data->GYRO_DATA_Z_MIDDLE = (float)GYRO_Z_RAW_MIDDLE/131.0;
	memset(Rec_Data, 0, sizeof(Rec_Data));

	HAL_I2C_Mem_Read (&hi2c2, ADRES_MPU_6050_LOW, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
	float GYRO_X_RAW_RING = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	float GYRO_Y_RAW_RING = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	float GYRO_Z_RAW_RING = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
	data->GYRO_DATA_X_RING = (float)GYRO_X_RAW_RING/131.0;
	data->GYRO_DATA_Y_RING = (float)GYRO_Y_RAW_RING/131.0;
	data->GYRO_DATA_Z_RING = (float)GYRO_Z_RAW_RING/131.0;
	memset(Rec_Data, 0, sizeof(Rec_Data));

	HAL_I2C_Mem_Read (&hi2c2, ADRES_MPU_6050_HIGHT, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
	float GYRO_X_RAW_BABY = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	float GYRO_Y_RAW_BABY = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	float GYRO_Z_RAW_BABY = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
	data->GYRO_DATA_X_BABY = (float)GYRO_X_RAW_BABY/131.0;
	data->GYRO_DATA_Y_BABY = (float)GYRO_Y_RAW_BABY/131.0;
	data->GYRO_DATA_Z_BABY = (float)GYRO_Z_RAW_BABY/131.0;
	memset(Rec_Data, 0, sizeof(Rec_Data));
}

