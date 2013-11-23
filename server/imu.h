#ifndef IMU_H
#define IMU_H
#include <stdio.h>
#include <string.h>


extern "C"{
#include "imu.h"
#include "imulib/mpu9150.h"
#include "imulib/linux_glue.h"
#include "local_defaults.h"

}
class IMU
{
private:
    mpudata_t mpu;
    int done;
    float imudata[3];
    char *mag_cal_file;
    char *accel_cal_file;
    int set_cal(int mag, char *cal_file);

public:
    IMU(int bus,int rate,int yaw_factor);
    float IMUreadX();
    float IMUreadY();
    float IMUreadZ();
};

#endif // IMU_H
