cmake_minimum_required(VERSION 3.16)
project(RadioEmulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#
## Пути к подпроектам
add_subdirectory(core)
add_subdirectory(plugins)
add_subdirectory(app)
