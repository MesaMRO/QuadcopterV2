#ifndef IMU_H
#define IMU_H

class IMU
{
private:
    int opt, len;
    int i2c_bus;
    int sample_rate;
    int yaw_mix_factor;
    int verbose;
    char *mag_cal_file;
    char *accel_cal_file;
public:
    void setIMUparams();
    void setIMUdebug();
    void setIMUcal();
    void initializeIMU();
    float readIMUdata();
};

#endif // IMU_H
