project(TestReceiver)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(TestReceiver SHARED
    include/testreceiver.h
    src/testreceiver.cpp
)

target_link_libraries(TestReceiver PRIVATE core Qt6::Core)