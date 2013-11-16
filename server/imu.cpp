#include "imu.h"
#include "mpu9150.h"
#include "linux_glue.h"
#include "local_defaults.h"


void IMU::setIMUparams()
{

    opt, len;
    i2c_bus = DEFAULT_I2C_BUS;
    sample_rate = DEFAULT_SAMPLE_RATE_HZ;
    yaw_mix_factor = DEFAULT_YAW_MIX_FACTOR;
}
void IMU::setIMUdebug()
{
    verbose = 0;
}

void IMU::setIMUcal()
{
    mag_cal_file = NULL;
    accel_cal_file = NULL;
}

void IMU::initializeIMU()
{

}

float IMU::readIMUdata()
{

}
