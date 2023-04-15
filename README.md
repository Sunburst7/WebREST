# brief introduction
Enhanced version of tiny-muduo for personal learing purposes
feature:
* Using muduo mode(muti-thread + IO multiplexing + one loop per thread) to deal with Concurrency
* Using C++11 thread API instead of pthread, somewhere using string-view
* Support Post method, parse body data
* Concisely create path handler, Supported methods(Put Delete Post Get) according to RESTful specifications
* Automatically close useless long-connection
* Simple usage, Simple import


reference:
* https://github.com/chenshuo/muduo
* https://github.com/linyacool/WebServer
* https://github.com/linyacool/WebServer

[Webbench](https://github.com/EZLippi/WebBench) stress test:
![测试1](https://user-images.githubusercontent.com/65580753/232190372-c79511a4-a6d7-4a57-99b4-42a14f19c8de.png)


# build
assuming you are in WebREST source directory, type in below: 
```bash
mkdir build
cd build
# Release Version, Debug Version: change "Release" to "Debug"
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```
then, everything is in /build
* bin: executable file of example program
* WebREST: essential file to import WebREST
  * include: all .h file
  * lib: static library file and shared library file

# use
in you own project, you can create a directory called "third" in the root directory.
and then, you copy whole /build/WebREST into the /third directory.
I give a example of http-server
```c++
#include <iostream>

#include "eventloop.h"
#include "inet_address.h"
#include "http.h"
#include "http_request.h"
#include "http_response.h"

using namespace std;
using namespace WebREST;

int main()
{
    EventLoop loop;
    InetAddress listen_addr(54321);
    HttpServer server(&loop, listen_addr, false);

    server.Get("/test", [](const HttpRequest& req, HttpResponse& resp){
        printf("/test handler\n");
        resp.set_status_code(HttpResponse::k200OK);
        resp.set_status_message("OK");
        resp.set_body("test hello!\n");
    });
    
    server.start();
    loop.loop();
}
```
now you project structure like this:
```bash
.
├── CMakeLists.txt
├── http_test.cc
└── third
    └── WebREST
```
in CMakeLists.txt, you can write this to import WebREST:
```CMake
cmake_minimum_required(VERSION 3.15)
project(WebREST-test C CXX)
add_definitions(-std=c++17)

include_directories(${PROJECT_SOURCE_DIR}/third/WebREST/include)

add_executable(http_test http_test.cc)

target_link_libraries(http_test ${PROJECT_SOURCE_DIR}/third/WebREST/lib/libWebREST-static.a -lpthread)
```
Ok, you are ready for Compiling, type under code in terminal:
```bash
# in root directory
mkdir build && cd build
cmake ..
make
```
