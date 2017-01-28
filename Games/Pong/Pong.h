

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
#include "../../include/entities/Entity.h"
#include "../../include/globals.h"
#include <iostream>

class Paddle
{
public:
    Paddle() = default;
    Paddle(const eng::Vector2f& pos, const eng::Vector2f& size)
    {
        mRectangle = eng::Rectangle(pos, size);
    }

    eng::Rectangle mRectangle;

    void draw(eng::Window& window)
    {
        mRectangle.draw(window.getSfRenderWindow());
    }



};




class Pong : protected Game{

public:
    Pong() : Game()
    {

    }

    virtual bool init() override
    {
        eng::Xml options(std::string(gFilePath) + "/Games/Pong/options.xml");
        mRenderWindow->setSize({std::stoi(options.rootElement()["resX"].getValue()), std::stoi(options.rootElement()["resY"].getValue())});
        return true;
    }


    Paddle leftPaddle;


    virtual void start() override
    {



        float paddleHeight = (mRenderWindow->getSize().y / 8);
        float paddleWidth =   (mRenderWindow->getSize().x / 40);
        leftPaddle = Paddle({0,(float) mRenderWindow->getSize().y - ((mRenderWindow->getSize().y/2)+(paddleHeight/2))}, {paddleWidth,paddleHeight});
        while(mRenderWindow->isOpen())
        {
            switch(mGameState)
            {
                case STATE::IN_MENUE:
                {
                    break;
                }
                case STATE::IN_GAME:
                {
                    update();
                    break;
                }
                case STATE::PAUSED:
                {
                    std::cout << "PAused" << std::endl;
                    break;
                }
            }

            event();
            update();
            render();

        }


    }


    virtual void event() override
    {
            sf::Event event;

            eng::util::KeyChecker KeyChecker(event);
            while (mRenderWindow->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    mRenderWindow->close();
                }
                if (KeyChecker.keyPressed(sf::Keyboard::D))
                {
                    std::cout << leftPaddle.mRectangle.getPosition().x <<  "   " <<  leftPaddle.mRectangle.getPosition().y<< std::endl;
                }
                if (KeyChecker.keyPressed(sf::Keyboard::Escape))
                {
                    mGameState = mGameState == STATE::PAUSED ? STATE::IN_GAME : STATE::PAUSED;
                }
                if (KeyChecker.keyPressed(sf::Keyboard::W))
                {
                    leftPaddle.mRectangle.move({0, -20});
                }
                if (KeyChecker.keyPressed(sf::Keyboard::S))
                {
                    leftPaddle.mRectangle.move({0, 20});
                }
                if (event.type == sf::Event::MouseEntered)
                {

                }
            }


    }

    virtual void render() override
    {
        mRenderWindow->clear();
        leftPaddle.draw(*mRenderWindow);
        mRenderWindow->display();
    }

    virtual void update() override
    {
//        std::cout << mRenderWindow->getSfRenderWindow().getSize().x << std::endl;
    }

};






#endif //ENGINE_PONG_H
