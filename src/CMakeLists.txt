# src/CMakeLists.txt
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS *.h)

add_executable(Tetris ${SOURCES} ${HEADERS} "Tetromino.cpp" "Tetromino.hpp")

# Link SFML (make sure you install it separately first)
find_package(SFML 3 COMPONENTS Graphics Window System Network Audio REQUIRED)

target_include_directories(Tetris PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Tetris PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)