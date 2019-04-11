cmake_minimum_required (VERSION 2.6)
project (HelloGTK)

IF(WIN32)
SET(GUI_TYPE WIN32)
ENDIF(WIN32)

IF(APPLE)
SET(GUI_TYPE MACOSX_BUNDLE)
ENDIF (APPLE)

find_package(gtk REQUIRED)

add_executable(hello ${GUI_TYPE} main.c)
target_link_libraries(hello gtk)
