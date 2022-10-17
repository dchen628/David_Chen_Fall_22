add_executable(GameEngine Source.cpp)

include_directories(../Pixel)

target_link_libraries(GameEngine Pixel)