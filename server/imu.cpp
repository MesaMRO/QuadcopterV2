#include "imu.h"

IMU::IMU(int bus,int rate,int yaw_factor) {
  int val;

    val = mpu9150_init(bus=DEFAULT_I2C_BUS,rate=DEFAULT_SAMPLE_RATE_HZ,yaw_factor=DEFAULT_YAW_MIX_FACTOR);

  if(val==-1) {
    throw -1;
  }

    //set_cal(0,0);
    //set_cal(1,0);

}

mpudata_t *IMU::getdata() {


}
