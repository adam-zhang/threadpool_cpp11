cmake_minimum_required(VERSION 2.8)
project(threadpool)
add_definitions(-std=c++17)
set(sources main.cpp
	ThreadPool.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} pthread)
