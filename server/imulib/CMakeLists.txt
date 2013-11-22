cmake_minimum_required(VERSION 2.8)
add_library(imulib      inv_mpu.h
                        inv_mpu.c
			inv_mpu_dmp_motion_driver.c 
                        inv_mpu_dmp_motion_driver.h
			linux_glue.c
                        linux_glue.h
			mpu9150.c
                        mpu9150.h
			quaternion.c
                        quaternion.h
                        vector3d.c
                        vector3d.h)
			
add_definitions(-DEMPL_TARGET_LINUX -DMPU9150 -DAK8975_SECONDARY)
