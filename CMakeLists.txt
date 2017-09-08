cmake_minimum_required(VERSION 2.8)

set(APP sdk_demo)
project(${APP})

add_subdirectory(3rdparty/libbson-1.6.3)

set (SPEAKIN_SDK_VERSION 1.0)
set (speakin-sdk-shared "speakin-sdk-${SPEAKIN_SDK_VERSION}")
set (speakin-sdk-static "speakin-sdk-static-${SPEAKIN_SDK_VERSION}")

set(CMAKE_CXX_FLAG "-g -Wall -o2")

AUX_SOURCE_DIRECTORY(./speakin/core SOURCES)
AUX_SOURCE_DIRECTORY(./demo DEMO_SOURCES)

SET(BSON_INCLUDE 3rdparty/libbson-1.6.3/src/bson)
SET(BSON_LIB 3rdparty/libbson-1.6.3/)
INCLUDE_DIRECTORIES(./speakin ./speakin/core ${BSON_INCLUDE})
LINK_DIRECTORIES(${BSON_LIB})
ADD_LIBRARY(${speakin-sdk-shared} SHARED ${SOURCES})
ADD_LIBRARY(${speakin-sdk-static} STATIC ${SOURCES})
add_executable(${APP} ${SOURCES} ${DEMO_SOURCES})
TARGET_LINK_LIBRARIES(${APP} curl ssl crypto bson-1.0)
