//	HAL_StatusTypeDef ret = HAL_I2C_IsDeviceReady(&hi2c1, ADRES_MPU_6050_1DEV , 1, 100);
//	if(ret == HAL_OK)
//	{
//		HAL_Delay(1000);
//	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//	    HAL_Delay(100);
//	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
//	    HAL_Delay(100);
//	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//	    HAL_Delay(100);
//	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
//	    HAL_Delay(100);
//	}
//	HAL_StatusTypeDef ret_2 = HAL_I2C_Mem_Read(&hi2c1, ADRES_MPU_6050_1DEV, WHO_AM_I, 1, &check_MPU6050_DEV1, 1, 100);
//	if(ret_2 == HAL_OK)
//	{
//		if(check_MPU6050_DEV1==0x68)
//		{
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//	      	HAL_Delay(1000);
//	      	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
//		}
//	}

//void mpu_5060_read_gyro(I2C_HandleTypeDef *hi2c, uint8_t deviceAddress, int16_t *GYRO_X, int16_t *GYRO_Y, int16_t *GYRO_Z );

//void mpu_5060_read_gyro(I2C_HandleTypeDef *hi2c, uint8_t deviceAddress, int16_t *GYRO_X, int16_t *GYRO_Y, int16_t *GYRO_Z)
//{
//	uint8_t Rec_Data[6];
//
//	float Gyro_X_RAW = 0;
//	float Gyro_Y_RAW = 0;
//	float Gyro_Z_RAW = 0;
//
//	// Read 6 BYTES of data starting from GYRO_XOUT_H register
//	HAL_I2C_Mem_Read (hi2c, deviceAddress, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);
//
//	Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
//	Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
//	Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
//
//	*GYRO_X = (float)Gyro_X_RAW/131.0;
//	*GYRO_Y = (float)Gyro_Y_RAW/131.0;
//	*GYRO_Z = (float)Gyro_Z_RAW/131.0;
//}

//mpu_5060_read_gyro(&hi2c1, ADRES_MPU_6050_1DEV, &INDEX_X, &INDEX_Y, &INDEX_Z);
//HAL_I2C_Mem_Read (hi2c, deviceAddress, GYRO_OUT_ALL, 1, Rec_Data, 6, 100);

//typedef struct {
//    int16_t GYRO_DATA_X;
//    int16_t GYRO_DATA_Y;
//    int16_t GYRO_DATA_Z;
//} GyroDataThumbFinger;
//typedef struct {
//    int16_t GYRO_DATA_X;
//    int16_t GYRO_DATA_Y;
//    int16_t GYRO_DATA_Z;
//} GyroDataIndexFinger;
//typedef struct {
//    int16_t GYRO_DATA_X;
//    int16_t GYRO_DATA_Y;
//    int16_t GYRO_DATA_Z;
//} GyroDataMiddleFinger;
//typedef struct {
//    int16_t GYRO_DATA_X;
//    int16_t GYRO_DATA_Y;
//    int16_t GYRO_DATA_Z;
//} GyroDataRingFinger;
//typedef struct {
//    int16_t GYRO_DATA_X;
//    int16_t GYRO_DATA_Y;
//    int16_t GYRO_DATA_Z;
//} GyroDataFinger;
