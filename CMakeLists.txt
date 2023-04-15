cmake_minimum_required(VERSION 3.15)

project(WebREST C CXX)

# c++ version
add_definitions(-std=c++17)

# cmake build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 根据不同的build type设置宏，在Debug模式下打印一些语句
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG_OUTPUT)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/WebREST/lib)

# 生成项目头文件
file (GLOB HEADERS 
    ${PROJECT_SOURCE_DIR}/WebREST/core/*.h
    ${PROJECT_SOURCE_DIR}/WebREST/server/*.h
    ${PROJECT_SOURCE_DIR}/WebREST/base/*.h
)
file(COPY ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/WebREST/include)

# 指定头文件搜索路径
include_directories(
    ${PROJECT_SOURCE_DIR}/WebREST/core
    ${PROJECT_SOURCE_DIR}/WebREST/server
    ${PROJECT_SOURCE_DIR}/WebREST/base
) 

# 生成库文件
file(GLOB MY_SRC ${PROJECT_SOURCE_DIR}/WebREST/core/*.cc
                ${PROJECT_SOURCE_DIR}/WebREST/core/*.h
                ${PROJECT_SOURCE_DIR}/WebREST/server/*.h
                ${PROJECT_SOURCE_DIR}/WebREST/server/*.cc
                ${PROJECT_SOURCE_DIR}/WebREST/base/*.h
                ${PROJECT_SOURCE_DIR}/WebREST/base/*.cc
)
add_library(WebREST-static STATIC ${MY_SRC})
add_library(WebREST-shared SHARED ${MY_SRC})

# 添加子项目处理子项目的CMakeLists.txt
add_subdirectory(example)
