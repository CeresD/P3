cmake_minimum_required(VERSION 3.10)
project(Praktikum_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Praktikum_3 main.cpp PriorityQueue.cpp PriorityQueue.h Exception.cpp Exception.h DiGraph.cpp DiGraph.h Node.cpp Node.h Edge.cpp Edge.h liste.h SFMLGraphVisualizer.cpp SFMLGraphVisualizer.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()