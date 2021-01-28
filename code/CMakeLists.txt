cmake_minimum_required(VERSION 2.8)
project(threadpool)
set(sources main.cpp
	ThreadPool.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} pthread)
