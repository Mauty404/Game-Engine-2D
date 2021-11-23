cmake_minimum_required(VERSION 3.20)
project(Game-Engine-2D)

set(CMAKE_CXX_STANDARD 23)

add_executable(Game-Engine-2D src/main.cpp src/engine.cpp headers/engine.hpp src/draw.cpp src/input.cpp src/Primitives/PrimitiveRenderer.cpp src/Primitives/PrimitiveRenderer.hpp src/LineSegment/LineSegment.cpp src/LineSegment/LineSegment.h src/Point2d/Point2d.cpp src/Point2d/Point2d.h src/ShapeObject.h src/DrawableObject.h src/TransformableObject.h)

include_directories(headers c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game-Engine-2D ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()