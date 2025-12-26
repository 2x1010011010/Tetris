set(HEADER_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/headers"
        "${CMAKE_CURRENT_SOURCE_DIR}/const"
)

file(GLOB_RECURSE HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/const/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/const/*.hpp"
)

add_executable(Tetris
        main.cpp
        ${HEADERS}
        Game.cpp
        GameStats.cpp
        GameController.cpp
        InputHandler.cpp
        TileManager.cpp
        Tetromino.cpp
        Playfield.cpp
        UIRenderer.cpp
)

target_link_libraries(Tetris
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        SFML::Audio
)

target_include_directories(Tetris
        PRIVATE
        ${HEADER_DIRS}
)

add_dependencies(Tetris copy_assets copy_fonts)

if (WIN)
    add_custom_command(TARGET Tetris POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:Tetris>
            $<TARGET_FILE_DIR:Tetris>
            COMMAND_EXPAND_LISTS
    )
endif()