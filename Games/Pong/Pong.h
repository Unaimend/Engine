

#ifndef ENGINE_PONG_H
#define ENGINE_PONG_H
///************************************
//*Author:    Thomas Dost
//*Datum:     20.01.2017
//*Beschr.   Test Game
//*Changelog:
// 20.01.2017
//            Erstelldatum
//
//
//*TODO:
//*************************************/
#include "../Game.h"
#include "../../include/entities/Entity.h"
#include "../../include/globals.h"
#include <iostream>

typedef uint_fast32_t uint32;
typedef const std::string& filepath;

class Paddle : public eng::Entity
{
public:
    Paddle(const eng::Vector2f& pos) : Entity(pos)
    {
        mSprite.setSprite("/Users/thomasdost/Documents/dev/Engine/data/textures/test.png");

    }


    eng::Vector2f mSpeed{0,20};

    virtual void move(eng::distance x, eng::distance y) override {mSprite.move({x,y});}
    virtual void update(float frametime) override {;}
    virtual void eng_event(const eng::Event &event)override {;}





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
        mRenderWindow->setFramerateLimit(mFps);

//        std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
//        for (std::size_t i = 0; i < modes.size(); ++i)
//        {
//            sf::VideoMode mode = modes[i];
//            std::cout << "Mode #" << i << ": "
//                      << mode.width << "x" << mode.height << " - "
//                      << mode.bitsPerPixel << " bpp" << std::endl;
//        }
//
//        if(options.rootElement()["fullscreen"].getValue() == "true")
//        {
//
//        }
        return true;
    }


    Paddle leftPaddle{{0.0,50}};
    Paddle rightPaddle{{0.0, 50}};
    double mFps = 60;
    double mFrameTime = 1000/mFps;



    virtual void start() override
    {
        leftPaddle.setScale({1,2});
        rightPaddle.setScale({1,2});
        float paddleHeight = leftPaddle.getSprite().getTexture()->getSize().y * leftPaddle.getSprite().getScale().y;
        float paddleWidth =   leftPaddle.getSprite().getTexture()->getSize().x* leftPaddle.getSprite().getScale().x;

        float newPaddelHeight =  (mRenderWindow->getSize().y / 6)/paddleHeight;
        float newPaddelWidth =  (mRenderWindow->getSize().y / 6)/paddleWidth;

        std::cout<< mRenderWindow->getSize().y - ((mRenderWindow->getSize().y/2)+(newPaddelHeight/2)) << std::endl;


        leftPaddle.setPosition({0,(float) mRenderWindow->getSize().y - ((mRenderWindow->getSize().y/2)+(newPaddelHeight/2))});
        rightPaddle.setPosition({mRenderWindow->getSize().x - paddleWidth,(float) mRenderWindow->getSize().y - ((mRenderWindow->getSize().y/2)+(newPaddelHeight/2))});

        while(mRenderWindow->isOpen())
        {
            event();
            switch(mGameState)
            {
                case STATE::IN_GAME:
                {
                    update();
                    break;
                }
                case STATE::PAUSED:
                {
                    break;
                }
            }
            render();
        }
    }


    virtual void event() override
    {
        sf::Event event;
        while (mRenderWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mRenderWindow->close();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                mGameState = mGameState == STATE::PAUSED ? STATE::IN_GAME : STATE::PAUSED;
            }
        }
    }
    virtual void render() override
    {
        mRenderWindow->clear();
        leftPaddle.draw(*mRenderWindow);
        rightPaddle.draw(*mRenderWindow);
        mRenderWindow->display();
    }

    virtual void update() override
    {
        using namespace  eng::util;

        //TODO Ersetzen durch isKeyPressed setXMove = true, isKeyNotPRessed setXMove = false;
        if (KeyChecker::keyPressed(sf::Keyboard::D))
        {
//            std::cout << leftPaddle.mRectangle.getPosition().x << "   " << leftPaddle.mRectangle.getPosition().y  << std::endl;
        }

        if (KeyChecker::keyPressed(sf::Keyboard::W))
        {
            leftPaddle.move(0,-1 * leftPaddle.mSpeed.y);
        }
        if (KeyChecker::keyPressed(sf::Keyboard::S))
        {

            leftPaddle.move(0, 1 * leftPaddle.mSpeed.y);
        }
        if (KeyChecker::keyPressed(sf::Keyboard::Up))
        {
            rightPaddle.move(0, -20);
            std::cout << "RightPaddel: move up " <<  rightPaddle.getSprite().getPosition().y << " : " <<  rightPaddle.getPosition().y <<   std::endl;
            std::cout << "RightPaddel: move up " <<  rightPaddle.getSprite().getPosition().y << " : " <<  rightPaddle.getPosition().y <<   std::endl;
        }
        if (KeyChecker::keyPressed(sf::Keyboard::Down))
        {
            rightPaddle.move(0, 20);
        }

    }

};






#endif //ENGINE_PONG_H
