//
// Created by Thomas Dost on 05.03.17.
//

#ifndef ENGINE_COMPONENTENTITY_H
#define ENGINE_COMPONENTENTITY_H

#include <Vector.h>
#include "../utility.h"
using namespace eng::util;

//class PhysComponent
//{
//public:
//    void update(ComponentEntity& ent)
//    {
//        bjorn.x += bjorn.velocity;
//    }
//};
//class ComponentEntity;


//class InputComponent
//{
//
//public:
//    InputComponent
//
//    void update(ComponentEntity& ent )
//    {
//        if(KeyChecker::keyPressed(sf::Keyboard::Key::Up))
//        {
//            std::cout << "Up Pressed" << std::endl;
//        }
//
//        if(KeyChecker::keyPressed(sf::Keyboard::Key::Down))
//        {
//            std::cout << "Down Pressed" << std::endl;
//        }
//    }
//};





//class GraphicsComponent
//{
//public:
//    GraphicsComponent();
//
//
//    void init(ComponentEntity& ent, filepath pathToTexture)
//    {
//        //TODO SetSprite implementieren
////        mTexture.loadFromFile(pathToTexture);
////        mSprite.setTexture(mTexture);
////        mSprite.setPosition({100,100});
//
//        mSprite = new eng::Sprite(pathToTexture);
//    }
//    void render(ComponentEntity& ent,eng::Window& window)
//    {
//        //Eigentlich wuerde hier die position des Sprites gesetzt werden
//
//        window.draw(mSprite->getSprite());
//
//
//        //TODO DIes zu callen fuehrt zu einen Crash
////        mSprite->draw(window.getSfRenderWindow());
//    }


//
//private:
//    eng::Sprite* mSprite;
////    sf::Sprite mSprite;
////    sf::Texture mTexture;
//};
/*


class ComponentEntity;

class InputComponent
{
public:
    virtual ~InputComponent() {}
    virtual void update(ComponentEntity& ent) = 0;
};

class PlayerInputComponent;

class ComponentEntity
{
public:

    ComponentEntity(PlayerInputComponent* input)
            : mInput(input)
    {}



    eng::Vector2f mVelocity{10,10};
    eng::Vector2f mPosition{0,0};

    void update()
    {
        mInput->update(*this);
        std::cout << mPosition.x << " " << mPosition.y << std::endl;
    }

    PlayerInputComponent* mInput;
};


class PlayerInputComponent : public InputComponent
{

public:
    virtual void update(ComponentEntity& ent) override
    {
        if(KeyChecker::keyPressed(sf::Keyboard::Key::Up))
        {
//            ent.mPosition  = ent.mPosition + sf::Vector2f{0,50};
        }
        if(KeyChecker::keyPressed(sf::Keyboard::Key::Down))
        {
//            ent.mPosition  = ent.mPosition + sf::Vector2f{0,-50};
        }
    }

};


*/

#endif //ENGINE_COMPONENTENTITY_H
