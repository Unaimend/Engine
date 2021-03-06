/************************************
*Author:    Thomas Dost
*Datum:     20.01.2017
*Beschr.    Interface zur Engine
*Changelog:
 20.01.2017
            Erstelldatum
 21.01.2017
            setHeight(int32 height), setWidth(int32 width), int32 getHeigth(), int32 getWidth() hizugefuegt
 04.03.2017
            IN_MENUE aus dem STATE-Enum geloescht da PAUSES genau das gleiche ist

*TODO:
*************************************/
#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "../submodules/tinyxml2_wrapper/Xml.h"
#include "../include/graphicWrapper/Window.h"

#include <thread>

enum class STATE {PAUSED, IN_GAME };
class Game {



public:
    Game()
    {

    }

    virtual bool init(){return true;} ;
    virtual void start(){} ;
protected:
    //Diese beide Methoden sind abstrakt da SFML sie benötigt um normal zu funktionieren
    virtual void event() = 0;
    virtual void render() = 0;
    virtual void update() {} ;

public:
    eng::Window* mRenderWindow;
    STATE mGameState = STATE::IN_GAME;

    const static int DEFAULT_FPS = 60;


};


#endif //ENGINE_GAME_H
