set(APP_DIR "${CMAKE_BINARY_DIR}/app")
set(PLUGIN_DIR "${APP_DIR}/plugins")

# Глобально для всех целей, созданных ПОСЛЕ этого
# Настройки должны быть установлены ДО добавления подкаталогов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PLUGIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PLUGIN_DIR})

add_subdirectory(testreceiver)
add_subdirectory(testtransmitter)