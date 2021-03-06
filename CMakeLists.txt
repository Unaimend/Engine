cmake_minimum_required(VERSION 2.8.9)
project (Engine)
SET(CMAKE_CXX_FLAGS "-std=c++14 -O3 -Wall" )

#Bring the headers, such as Student.h into the project
include_directories(include/tinyXML/)
include_directories(include/SFML)
include_directories(include/lua/)
include_directories(include/eventSystem/)
include_directories(include/luaApi)
include_directories(include/graphicWrapper/)
include_directories(include)
include_directories(submodules/tinyxml2_wrapper/Xml.h)
include_directories(submodules/tinyxml2_wrapper/tinyxml2/tinyxml2.h)

#For the shared library:
#set ( PROJECT_LINK_LIBS libsfml-graphics.so libsfml-window.so libsfml-system.so liblua.a)
set ( PROJECT_LINK_LIBS libsfml-graphics.dylib libsfml-window.dylib libsfml-system.dylib liblua.a)
#link_directories( /usr/lib/x86_64-linux-gnu/)
link_directories( ./lib/lua/osx/)
link_directories( ./lib/SFML/)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp" "submodules/tinyxml2_wrapper/tinyxml2/*.cpp"  "src/eventSytem/*.cpp" "src/luaApi/*.cpp"
 "src/graphicWrapper/*.cpp" "src/entities/*.cpp" )
add_executable(Engine ${SOURCES} Games/Pong/Pong.cpp Games/Pong/Pong.h include/graphicWrapper/Window.h Games/Game.h include/graphicWrapper/Sprite.h include/entities/ActorFactory.h include/entities/ActorComponent.h include/entities/Actor.h include/entities/ComponentEntity.h Games/Labyrinth/Labyrinth.cpp Games/Labyrinth/Labyrinth.h)

target_link_libraries(Engine ${PROJECT_LINK_LIBS} )
