cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CORE_FILES
    src/Core/Game.cpp
)

set(GRAPHICS_FILES
    src/Graphics/Render.cpp
    src/Graphics/TextureManager.cpp
)

set(ENTITIES_FILES
    src/Entities/Player.cpp
    src/Entities/Background.cpp
    src/Entities/Ground.cpp
)

set(EVENTS_FILES
    src/Events/EventDispatcher.cpp
)

set(COLLISIONS_FILES
    src/Collisions/CollisionManager.cpp
    src/Collisions/CollisionEvent.cpp
    src/Collisions/ICollidable.cpp
)

add_executable(main 
    src/main.cpp
    ${CORE_FILES} 
    ${GRAPHICS_FILES} 
    ${ENTITIES_FILES} 
    ${EVENTS_FILES} 
    ${COLLISIONS_FILES}
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
