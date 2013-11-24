#include <iostream>
#include <stdio.h>
#include <string.h>


#include "imu.h"

using namespace std;

int main()
{
    IMU quad(1,10,1);
    int imuperiod = (1000/10)-2;
    cout << "I am going to run the IMU" << endl;
    float IMUvector[3];
    for(int i = 0; i<100; i++){
        quad.IMUread(IMUvector);
        cout << " x: "<< IMUvector[1] <<" y: " << IMUvector[2] << " z: " << IMUvector[3] << endl;
        linux_delay_ms(imuperiod);
    }
    quad.~IMU();

    return 0;
}

