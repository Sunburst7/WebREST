cmake_minimum_required(VERSION 3.15)

project(WebREST C CXX)
# c++ version
add_definitions(-std=c++17)

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 生成项目头文件
file (GLOB HEADERS 
    ${PROJECT_SOURCE_DIR}/WebREST/core/*.h
    ${PROJECT_SOURCE_DIR}/WebREST/server/*.h
    ${PROJECT_SOURCE_DIR}/WebREST/base/*.h
)
install(FILES ${HEADERS} DESTINATION include/WebREST)

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
