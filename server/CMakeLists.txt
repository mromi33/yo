message(STATUS "The server directory is on building process...")

set(SOURCES src/main.cpp src/logger.cpp src/core.cpp)

add_executable(yo_exe ${SOURCES})

find_package(asio REQUIRED)
find_package(libpqxx REQUIRED)

target_include_directories(yo_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(yo_exe PRIVATE asio)
target_link_libraries(yo_exe PRIVATE pqxx)

message(STATUS "The server directory is builded")