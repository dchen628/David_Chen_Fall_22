add_executable(GameEngine Source.cpp Score.cpp)

include_directories(../Pixel)

target_link_libraries(GameEngine Pixel)