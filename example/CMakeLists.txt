add_executable(echo_test echo_test.cc)
target_link_libraries(echo_test WebREST-static -lpthread)

add_executable(http_test http_test.cc)
target_link_libraries(http_test WebREST-static -lpthread)