cmake_minimum_required(VERSION 3.17)
project(AC_automation)

set(CMAKE_CXX_STANDARD 11)

add_executable(AC_automation acauto.cpp AC_automachine.cpp AC_automachine.h queue.cpp queue.h List.h)