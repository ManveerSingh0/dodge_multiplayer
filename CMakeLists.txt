cmake_minimum_required(VERSION 4.0)
project(dodge_multiplayer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.1
  GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)



add_subdirectory(src)


target_link_libraries(main PRIVATE SFML::Graphics SFML::Network)
