add_executable(radio-emulator main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(radio-emulator PRIVATE core Qt6::Core)
