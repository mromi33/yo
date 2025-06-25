cmake_minimum_required(VERSION 3.20)
project("Yo" VERSION 1.0.0 DESCRIPTION "" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are prohibited. 
    Please make a build directory and only after this build the app")
endif()

include(cmake/CPM.cmake)

find_package(Threads REQUIRED)

CPMAddPackage("gh:chriskohlhoff/asio#asio-1-34-2@1.34.2")

if(asio_ADDED)
  add_library(asio INTERFACE)

  target_include_directories(asio SYSTEM INTERFACE ${asio_SOURCE_DIR}/asio/include)

  target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)

  target_link_libraries(asio INTERFACE Threads::Threads)

endif()

find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)

CPMAddPackage(
    NAME libpqxx
    GIT_REPOSITORY https://github.com/jtv/libpqxx
    GIT_TAG "7.10.1"
)

add_subdirectory(front/)
add_subdirectory(server/)