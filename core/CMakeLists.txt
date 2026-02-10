project(core)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(core STATIC
    include/deviceconfig.h
    include/devicecontext.h
    include/ideviceemulator.h
    include/pluginmanager.h
    include/deviceinstance.h
    include/simulatorengine.h
    include/configloader.h
    src/configloader.cpp
    src/simulatorengine.cpp
    src/deviceinstance.cpp
    src/pluginmanager.cpp
)

target_link_libraries(core PUBLIC Qt6::Core)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})
