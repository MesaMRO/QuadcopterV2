#include "imu.h"
int done;

IMU::IMU(int bus,int rate,int yaw_factor) {
    int val;
    char *mag_cal_file = NULL;
    char *accel_cal_file = NULL;

    register_sig_handler();

    val = mpu9150_init(bus=DEFAULT_I2C_BUS,rate=DEFAULT_SAMPLE_RATE_HZ,yaw_factor=DEFAULT_YAW_MIX_FACTOR);

  if(val==-1) {
    throw -1;
  }

  set_cal(0, accel_cal_file);
  set_cal(1, mag_cal_file);

  if (accel_cal_file)
          free(accel_cal_file);

  if (mag_cal_file)
          free(mag_cal_file);


}


int IMU::set_cal(int mag, char *cal_file)
{
    int i;
    FILE *f;
    char buff[32];
    long val[6];
    caldata_t cal;

    if (cal_file) {
        f = fopen(cal_file, "r");

        if (!f) {
            perror("open(<cal-file>)");
            return -1;
        }
    }
    else {
        if (mag) {
            f = fopen("./magcal.txt", "r");

            if (!f) {
                printf("Default magcal.txt not found\n");
                return 0;
            }
        }
        else {
            f = fopen("./accelcal.txt", "r");

            if (!f) {
                printf("Default accelcal.txt not found\n");
                return 0;
            }
        }
    }

    memset(buff, 0, sizeof(buff));

    for (i = 0; i < 6; i++) {
        if (!fgets(buff, 20, f)) {
            printf("Not enough lines in calibration file\n");
            break;
        }

        val[i] = atoi(buff);

        if (val[i] == 0) {
            printf("Invalid cal value: %s\n", buff);
            break;
        }
    }

    fclose(f);

    if (i != 6)
        return -1;

    cal.offset[0] = (short)((val[0] + val[1]) / 2);
    cal.offset[1] = (short)((val[2] + val[3]) / 2);
    cal.offset[2] = (short)((val[4] + val[5]) / 2);

    cal.range[0] = (short)(val[1] - cal.offset[0]);
    cal.range[1] = (short)(val[3] - cal.offset[1]);
    cal.range[2] = (short)(val[5] - cal.offset[2]);

    if (mag)
        mpu9150_set_mag_cal(&cal);
    else
        mpu9150_set_accel_cal(&cal);

    return 0;
}

float IMU::IMUreadX(){
    memset(&mpu, 0, sizeof(mpudata_t));


    return mpu.fusedEuler[VEC3_X] * RAD_TO_DEGREE;

}

float IMU::IMUreadY(){
    memset(&mpu, 0, sizeof(mpudata_t));

    return  mpu.fusedEuler[VEC3_Y] * RAD_TO_DEGREE;
}
float IMU::IMUreadZ(){
    memset(&mpu, 0, sizeof(mpudata_t));


    return mpu.fusedEuler[VEC3_Z] * RAD_TO_DEGREE;
}
IMU::~IMU(){
    mpu9150_exit();
}

void register_sig_handler()
{
    struct sigaction sia;

    bzero(&sia, sizeof sia);
    sia.sa_handler = sigint_handler;

    if (sigaction(SIGINT, &sia, NULL) < 0) {
        perror("sigaction(SIGINT)");
        exit(1);
    }
}


void sigint_handler(int sig)
{
    done = 1;
}
