cmake_minimum_required(VERSION 3.0)

project(SDL_Image_Display)

# Set the name of the executable
SET(APP_NAME main)

# Add all the source files
SET(APP_FILES main.cpp
        cards.hpp cards.cpp
        MazeCards.hpp MazeCards.cpp
        Coordinates.hpp Coordinates.cpp
        Stack.hpp Stack.cpp
        CircularQueue.hpp CircularQueue.cpp
        Enums.cpp FixedMazeCards.cpp
        Player.hpp Player.cpp
        Game.hpp Game.cpp
        board.hpp board.cpp)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find SDL2_image package
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Add the executable
add_executable(${APP_NAME} ${APP_FILES})

# Link SDL2 libraries
target_link_libraries(${APP_NAME} ${SDL2_LIBRARIES})

# Link SDL2_image libraries
target_link_libraries(${APP_NAME} ${SDL2_IMAGE_LIBRARIES})
