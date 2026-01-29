cmake_minimum_required(VERSION 4.0)
project(GameJam26)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR /opt/homebrew/opt/sfml@2/lib/cmake/SFML)
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

add_executable(GameJam26 "Source Files/main.cpp"
        "Source Files/InputDispatcher.cpp"
        "Header Files/InputDispatcher.hpp"
        "Source Files/InputReceiver.cpp"
        "Header Files/InputReceiver.hpp"
        "Source Files/Factory.cpp"
        "Header Files/Factory.hpp"
        "Source Files/GameObject.cpp"
        "Header Files/GameObject.hpp"
        "Header Files/Component.hpp"
        "Source Files/Update.cpp"
        "Header Files/Update.hpp"
        "Source Files/Graphics.cpp"
        "Header Files/Graphics.hpp"
        "Source Files/SoundEngine.cpp"
        "Header Files/SoundEngine.hpp"
        "Source Files/LevelUpdate.cpp"
        "Header Files/LevelUpdate.hpp"
        "Source Files/PlayerUpdate.cpp"
        "Header Files/PlayerUpdate.hpp"
        "Source Files/PlayerGraphics.cpp"
        "Header Files/PlayerGraphics.hpp")

target_link_libraries(GameJam26 sfml-graphics sfml-window sfml-system sfml-audio)