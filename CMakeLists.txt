cmake_minimum_required(VERSION 3.17)
project(UDB)

set(CPP src/database.cpp src/student.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
  )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
  
add_executable(${PROJECT_NAME} src/main.cpp src/database.cpp src/student.cpp)

enable_testing()
add_executable(${PROJECT_NAME}-ut src/test.cpp src/database.cpp src/student.cpp)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

