project(imulib)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_definitions(-DEMPL_TARGET_LINUX -DMPU9150 -DAK8975_SECONDARY)
