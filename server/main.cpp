#include <iostream>
#include <stdio.h>
#include <string.h>


#include "imu.h"

using namespace std;

int main()
{
    IMU quad(1,10,0);
    int imuperiod = (1000/10)-2;
    cout << "I am going to run the IMU" << endl;
    for(int i = 0; i<100; i++){

        cout << " x: "<< quad.IMUreadX() <<" y: " << quad.IMUreadY() << " z: " << quad.IMUreadZ() << endl;
        linux_delay_ms(imuperiod);
    }
    quad.~IMU();

    return 0;
}

