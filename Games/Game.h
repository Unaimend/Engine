/************************************
*Author:    Thomas Dost
*Datum:     20.01.2017
*Beschr.    Interface zur Engine
*Changelog:
 20.01.2017
            Erstelldatum
 21.01.2017
            setHeight(int32 height), setWidth(int32 width), int32 getHeigth(), int32 getWidth() hizugefuegt

*TODO:
*************************************/
#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "../include/xmlWrapper/Xml.h"
#include "../include/graphicWrapper/Window.h"


class Game {
public:
    Game()
    {
        mRenderWindow = new eng::Window();
    }

    virtual bool init(){} ;
    virtual void start(){} ;
//    virtual void update() ;


    eng::Window* mRenderWindow;

};


#endif //ENGINE_GAME_H
