cmake_minimum_required(VERSION 2.8.9)
project (Engine)
SET(CMAKE_CXX_FLAGS "-std=c++14 -O0 -Wall" )

#Bring the headers, such as Student.h into the project
include_directories(include/tinyXML/)
include_directories(include/SFML)
include_directories(include/lua/)
include_directories(include/eventSystem/)
include_directories(include/luaApi)
include_directories(include/graphicWrapper/)
include_directories(include)



#For the shared library:
#set ( PROJECT_LINK_LIBS libsfml-graphics.so libsfml-window.so libsfml-system.so liblua.a)
set ( PROJECT_LINK_LIBS libsfml-graphics.dylib libsfml-window.dylib libsfml-system.dylib liblua.a)
#link_directories( /usr/lib/x86_64-linux-gnu/)
link_directories( ./lib/lua/osx/)
link_directories( ./lib/SFML/)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp" "src/tinyXML/*.cpp"  "src/eventSytem/*.cpp" "src/luaApi/*.cpp" 
"src/xmlWrapper/*.cpp" "src/graphicWrapper/*.cpp" "src/entities/*.cpp" )
add_executable(Engine ${SOURCES} Games/Pong.cpp Games/Pong.h)

target_link_libraries(Engine ${PROJECT_LINK_LIBS} )
