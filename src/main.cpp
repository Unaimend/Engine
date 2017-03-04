#include "../include/lua/lua.hpp"
#include <iostream>
#include <Variant.h>
#include "../include/ResourceManager.h"
#include "../include/Texture.h"
#include "../include/eventSystem/Event.h"
#include "../include/globals.h"
#include "../include/graphicWrapper/Rectangle.h"
#include "../submodules/tinyxml2_wrapper/Xml.h"
#include "../include/entities/Entity.h"
#include "../include/graphicWrapper/Window.h"
#define MAC


#include "../Games/Pong/Pong.h"






char gFilePath[100];
namespace eng {
    EventQueue gEventQueue;
}

lua::LuaState gLuaState("./data/main.lua");






eng::Event* onWindowClicked = new eng::Event
{   "onWindowClicked",
    {"Text"},
    { {eng::Variant::Type::INTEGER, 55} }
};



int main(int argc, char** argv) {
#ifdef LINUX
    std::cout << "Engine runs on Linux" << std::endl;
#elif defined WINDOWS
    std::cout << "Engine runs on Windows" << std::endl;
#elif defined MAC
    std::cout << "Engine runs on Mac" << std::endl;
#endif


#ifdef LINUX
    if(readlink("/proc/self/exe", gFilePath, 100) == -1)
    {
        std::cerr << "Error: Dateipfad konnte nicht ermittelt werden" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Pfad zur Datei:" << gFilePath << std::endl;
    }
#elif defined WINDOWS

#elif defined MAC
    strcpy(gFilePath, "/Users/thomasdost/Documents/dev/Engine");
#endif


    {
        //TEST GAME AREA
        Pong a{};
        a.init();
        a.start();
        a.render();
    }


/*
sf::Texture text;
text.loadFromFile("/Users/thomasdost/Documents/dev/Engine/data/textures/test.png");
sf::Sprite sprite1;
sprite1.setTexture(text);


eng::Rectangle rect{50,50};
eng::Sprite sprite{"/Users/thomasdost/Documents/dev/Engine/data/textures/test.png"};
sprite.setPosition({60,60});




sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

// run the program as long as the window is open
while (window.isOpen())
{
// check all the window's events that were triggered since the last iteration of the loop
sf::Event event;
while (window.pollEvent(event))
{
// "close requested" event: we close the window
if (event.type == sf::Event::Closed)
window.close();
}

// clear the window with black color
window.clear(sf::Color::Black);

// draw everything here...
// window.draw(...);
window.draw(sprite1);

window.draw(sprite.getSprite());

// end the current frame
window.display();
}

*/





//
//
//
//    //Options Xml laden, hier steht alles wichtige drinnen.
//    eng::Xml xml{std::string(gFilePath) + "/data/options.xml"};
//    eng::XmlElement resX = xml.rootElement()["resX"];
//    eng::XmlElement resY = xml.rootElement()["resY"];
//
//
//
//
//
//
//    gLuaState["resX"] = resX.getValue().c_str();
//    gLuaState["resY"] = resY.getValue().c_str();
//    gLuaState["filepath"] = gFilePath;
//
//
////    eng::RecEntity* ent = new eng::RecEntity({50,50}, gLuaState, xml);
////
//
//
//    eng::Window window("HALLO", 1920,1200);
//
//    window.setFramerateLimit(60);
//

//
//
////    gLuaState.runFile();
////
////
////
////
////    lua_getglobal(gLuaState.mState, "startUp");
//
//    while (window.isOpen())
//    {
////
////        auto frame_start_time = std::chrono::high_resolution_clock::now();
//        sf::Event event;
////
////        eng::util::KeyChecker KeyChecker(event);
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
////            if (KeyChecker.keyPressed(sf::Keyboard::D))
////            {
////                ent->mRec.move({20,0});
////            }
////            if (KeyChecker.keyPressed(sf::Keyboard::A))
////            {
////                ent->mRec.move({-20,0});
////            }
////            if (KeyChecker.keyPressed(sf::Keyboard::W))
////            {
////                ent->mRec.move({0,-20});
////            }
////            if (KeyChecker.keyPressed(sf::Keyboard::S))
////            {
////                ent->mRec.move({0,20});
////            }
//            if (event.type == sf::Event::MouseEntered)
//            {
//               // gLuaState.runFile();
//                eng::gEventQueue.addEvent(onWindowClicked);
//            }
//        }
//////        auto event_start_time = std::chrono::high_resolution_clock::now();
////        for(const auto& it : eng::gEventQueue.mEvents)
////        {
////            if(it->getHash() == eng::util::toHash("EntitiyDead"))
////            {
////                std::cout << "Entitie died" << it->mArgs["TEXT"].mValue.mAsInteger << std::endl;
////
////
////            }
////            //HIER WERDEN EVENTS UEBERGEBEN
////        }
////        eng::gEventQueue.mEvents.clear();
//////        auto event_end_time = std::chrono::high_resolution_clock::now();
//////        std::cout << ":EventQueueTime:"<<std::chrono::duration_cast<std::chrono::microseconds>(event_end_time - event_start_time).count() << std::endl;
////
////
////        //LUA UPDATE CALL
////        lua_getglobal(gLuaState.mState, "update");
////        if(!lua_isfunction(gLuaState.mState,-1))
////        {
////            std::cout << "Keine Lua update Funktion" << std::endl;
////            exit(-1);
////        }
////        lua_pcall(gLuaState.mState, 0, 0, 0);
////
////
////
////        //LUA RENDER CALL
////        lua_getglobal(gLuaState.mState, "draw");
////        if(!lua_isfunction(gLuaState.mState,-1))
////        {
////            std::cout << "Keine Lua draw Funktion" << std::endl;
////            exit(-1);
////        }
////         gLuaState.callFunction();
//
//
//        window.clear();
//        rect.draw(window);
//        sprite.draw(window.getSfRenderWindow());
////        ent->update(20);
////        ent->draw(window.getSfRenderWindow());
//        window.display();
////        auto frame_end_time = std::chrono::high_resolution_clock::now();
//    }
//
////
////    gLuaState.push(1,2,3, "HI");
////    gLuaState.runFile();
////
////
////
////
////    lua_getglobal(gLuaState.mState, "shutDown");
////    gLuaState.callFunction();
//
//
//
//    return 0;
}




/************************************
*Author:    Thomas Dost
*Datum:     22.12.2015
*Beschr.    
*Changelog:
*TODO:
*************************************/

/**********************************************
*Descr:
*Param1:
*Return:
***********************************************/



/******************TEST AREA**********************************/
//eng::Variant a{"Error: Dateipfad konnte nicht ermittelt werden"};
// std::cout << a.mValue.mAsStringId << std::endl;

//eng::Event* onExplode = new eng::Event
//        {   "onExplode",
//            {"radius", "damage", "explosiveType"},
//            { {eng::Variant::Type::INTEGER, 20},{eng::Variant::Type::DOUBLE, 2000},{"Grenade"} }
//        };

/*   eng::Event onExplode2
       {   "onExplode",
           {"radius"},
           { {eng::Variant::Type::INTEGER, 22} }
       };


         for(int i = 0; i < 100; ++i)
         {


         }

    for(int i = 0; i < 100; ++i)
        {
           size_t& temp =gEventQueue.mEvents[i]->mEventName;

           if(temp == 123243243)
           {
                   ;
           }
           else if (temp == 43532432)
           {
               ;
           }
           else if (temp == 324234324324)
           {
               ;
           }
           else if (temp == 234325)
           {
               ;
           }
           else if (temp == 124432542532)
           {
               ;
           }
           else
           {
               ;
           }


        }


 */










//    for(auto it = mRec.begin(); it != mRec.end();)
//    {
//
//        (*it)->mRec.move({0,20});
//        if ((*it)->mRec.getPosition().y > 500)
//        {
//            delete *it;
//
//            it = mRec.erase(it);
//        }
//        else{it++;}
//    }

//    std::cout << VAR(gLuaState) << std::endl;
//

// gLuaState.push(1,2,3);
//gLuaState.runFile();


// gLuaState.openLibs();

//    lua_getglobal(gLuaState.mState,"Main");

//    lua_getfield(gLuaState.mState, -1, "update");
//  if (lua_pcall(gLuaState.mState, 0, 0, 0))
//        bail(gLuaState.mState, "lua_pcall() failed");
//    lua_pcall(gLuaState.mState, 0, 0, 0);


//    lua_getglobal(gLuaState.mState, "update"); // or get 'banana' from person:Eat()
//    //lua_getfield(gLuaState.mState, -1, "chew");
//
//    if(!lua_isfunction(gLuaState.mState,-1))
//    {
//        std::cout << "WHY" << std::endl;
//    }
//
//    gLuaState.push(5);
//    gLuaState.push(1);
//
//    /* do the call (2 arguments, 1 result) */
//    if (lua_pcall(gLuaState.mState, 2, 1, 0) != 0) {
//        printf("error running function `f': %s\n",lua_tostring(gLuaState.mState, -1));
//        return -1;
//    }
//    lua_pcall(gLuaState.mState, 1, 0, 0);
//
//
//    lua_getglobal(gLuaState.mState, "tellme");
//    lua_pushinteger(gLuaState.mState, 22);
//    lua_pcall(gLuaState.mState, 1, 0, 0);


/*
 
 
 // create new Lua state
 lua_State *lua_state;
 lua_state = luaL_newstate();
 
 // load Lua libraries
 static const luaL_Reg lualibs[] =
 {
 { "base", luaopen_base },
 { NULL, NULL}
 };
 
 const luaL_Reg *lib = lualibs;
 for(; lib->func != NULL; lib++)
 {
 lib->func(lua_state);
 lua_settop(lua_state, 0);
 }
 
 // run the Lua script
 luaL_dofile(lua_state, "hello.lua");
 
 // close the Lua state
 lua_close(lua_state);
 */







