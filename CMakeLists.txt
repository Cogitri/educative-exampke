cmake_minimum_required(VERSION 3.16)

project(
  Shaer
  VERSION 1.0
  LANGUAGES CXX
)
include(CTest)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt REQUIRED)
find_package(Boost COMPONENTS program_options unit_test_framework REQUIRED)
find_package(Poco COMPONENTS Crypto REQUIRED)

add_library(core STATIC src/checksum.cpp)
target_link_libraries(core PUBLIC fmt::fmt Boost::program_options Poco::Crypto)
add_executable(shaer src/main.cpp)
target_link_libraries(shaer PRIVATE core)

add_executable(testShaer src/test.cpp)
target_link_libraries(testShaer core Boost::unit_test_framework)
add_test(NAME testShaer COMMAND testShaer)

configure_file(LICENSE LICENSE COPYONLY)
