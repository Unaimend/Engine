cmake_minimum_required(VERSION 2.8.9)
project (Engine)
SET(CMAKE_CXX_FLAGS "-std=c++14")

#Bring the headers, such as Student.h into the project
include_directories(include/tinyXML)
include_directories(include/SFML)
include_directories(include/lua)
include_directories(include/eventSystem)
include_directories(include)


#For the shared library:
set ( PROJECT_LINK_LIBS libsfml-graphics.so libsfml-window.so libsfml-system.so liblua.a)
link_directories( /usr/lib/x86_64-linux-gnu/)
link_directories( ~/dev/cpp/sfml/Engine/lib/lua)


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp" "src/eventSystem/*.cpp")
add_executable(Engine ${SOURCES})

target_link_libraries(Engine ${PROJECT_LINK_LIBS} )
