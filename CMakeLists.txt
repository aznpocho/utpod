cmake_minimum_required(VERSION 3.12)
project(utpod)

set(CMAKE_CXX_STANDARD 14)

add_executable(utpod UtPodDriver.cpp UtPod.cpp UtPod.h song.cpp song.h)