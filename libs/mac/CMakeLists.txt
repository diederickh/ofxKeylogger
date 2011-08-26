cmake_minimum_required(VERSION 2.8)
project(keylogger_mac)
include_directories(include)
set(CMAKE_OSX_ARCHITECTURES i386)

add_library(${CMAKE_PROJECT_NAME} STATIC src/Keylogger_Mac.mm)
target_link_libraries(${CMAKE_PROJECT_NAME} "-framework Foundation")
