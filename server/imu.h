#ifndef IMU_H
#define IMU_H
#include "imu.h"
#include "mpu9150.h"
#include "linux_glue.h"
#include "local_defaults.h"

class IMU
{
private:
    mpudata_t mpudata;
public:
    IMU(int bus,int rate,int yaw_factor);
    mpudata_t *getdata();
};

#endif // IMU_H
