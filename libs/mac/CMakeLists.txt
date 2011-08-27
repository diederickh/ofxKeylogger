cmake_minimum_required(VERSION 2.8)

project(keylogger_mac)

include_directories(include)

set(CMAKE_OSX_ARCHITECTURES i386)

set(libname "Keylogger_Mac")

add_library(${libname} STATIC src/Keylogger_Mac.mm)

target_link_libraries(${libname} "-framework Foundation")

set_target_properties(${libname} PROPERTIES PREFIX "")

install(TARGETS ${libname}
  LIBRARY DESTINATION .
  ARCHIVE DESTINATION .
)

