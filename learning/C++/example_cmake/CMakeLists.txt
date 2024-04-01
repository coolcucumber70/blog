cmake_minimum_required(VERSION 3.15)

# set the project name
project(Tutorial VERSION 1.0.2)

SET(SRC_LIST tutorial.cpp)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

configure_file(TutorialConfig.h.in TutorialConfig.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})