project(TestTransmitter)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(TestTransmitter SHARED
    include/testtransmitter.h
    src/testtransmitter.cpp
)

target_link_libraries(TestTransmitter PRIVATE core Qt6::Core)