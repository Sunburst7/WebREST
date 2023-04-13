# Install script for directory: /home/sunburst7/桌面/Enhance_Tiny_muduo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/WebREST" TYPE FILE FILES
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/base/Thread.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/base/buffer.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/base/copyable.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/base/countdown_latch.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/base/non_copyable.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/acceptor.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/callback.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/channel.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/epoller.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/eventloop.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/eventloop_thread.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/eventloop_thread_pool.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/http_request.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/http_response.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/inet_address.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/socket.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/tcp_connection.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/core/tcp_server.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/server/echo.h"
    "/home/sunburst7/桌面/Enhance_Tiny_muduo/WebREST/server/http.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/sunburst7/桌面/Enhance_Tiny_muduo/build/example/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/sunburst7/桌面/Enhance_Tiny_muduo/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
