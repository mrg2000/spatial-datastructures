cmake_minimum_required(VERSION 2.8)
project(spatial_implementation)

set(CMAKE_CXX_STANDARD 14)

if (NOT TARGET gtest_main)
    add_subdirectory(googletest)
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

# BOOST
# RUN brew install boost in your terminal and configure the destination files
set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.75.0_2/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.75.0_2/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
# enable_testing()

add_executable(
  quad_test
  quad_test.cpp
)

target_link_libraries(
  quad_test
  gtest_main
  gtest
  gmock
)