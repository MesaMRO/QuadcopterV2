project(server)

include_directories("${PROJECT_SOURCE_DIR}/imulib")
add_subdirectory(imulib)

cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

add_definitions(-DEMPL_TARGET_LINUX -DMPU9150 -DAK8975_SECONDARY)
