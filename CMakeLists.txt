cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(server src/server.cpp)
add_executable(client src/client.cpp)
target_compile_features(server PRIVATE cxx_std_17)
target_link_libraries(server  PRIVATE SFML::Graphics SFML::Network)


target_compile_features(client PRIVATE cxx_std_17)
target_link_libraries(client PRIVATE SFML::Graphics SFML::Network)
