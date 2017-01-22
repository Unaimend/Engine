

#ifndef ENGINE_PONG_H
#define ENGINE_PONG_H
/************************************
*Author:    Thomas Dost
*Datum:     20.01.2017
*Beschr.   Test Game
*Changelog:
 20.01.2017
            Erstelldatum


*TODO:
*************************************/
#include "../Game.h"
#include <iostream>

class Pong : protected Game{

public:
    Pong() : Game()
    {

    }

    virtual bool init() override
    {
        eng::Xml options(std::string(gFilePath) + "/Games/Pong/options.xml");


    }


    virtual void start() override
    {
        while (mRenderWindow->isOpen())
        {
            sf::Event event;

            eng::util::KeyChecker KeyChecker(event);
            while (mRenderWindow->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {

                }
                if (KeyChecker.keyPressed(sf::Keyboard::D))
                {

                }
                if (KeyChecker.keyPressed(sf::Keyboard::A))
                {

                }
                if (KeyChecker.keyPressed(sf::Keyboard::W))
                {
                    mRenderWindow->close();
                }
                if (KeyChecker.keyPressed(sf::Keyboard::S))
                {

                }
                if (event.type == sf::Event::MouseEntered)
                {

                }
            }


            mRenderWindow->clear();

            mRenderWindow->display();
        }
    }



};


#endif //ENGINE_PONG_H
