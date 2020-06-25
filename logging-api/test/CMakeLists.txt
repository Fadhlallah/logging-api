cmake_minimum_required (VERSION 3.8)
set(execName "LoggingTest")
set(SRC "LoggingTest.cpp")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")


add_executable("${execName}" "${SRC}")

target_link_libraries("${execName}" PRIVATE
	liblogging
	gtest_main
	)

add_test(
	NAME ${execName}
	COMMAND ${execName})
