/************************************
Author:     Thomas Dost
Datum:      27.01.2017
Beschr.
            Wrapper um sf::Sprite
Changelog:
27.01.2017
            Erstelldatum
*TODO:
*************************************/

#ifndef ENGINE_SPRITE_H
#define ENGINE_SPRITE_H
#include "../globals.h" //SFML
#include "../graphicWrapper/Vector.h"

#include <iostream>


namespace eng
{
    class Sprite
    {

    public:
        Sprite(filepath pathToSprite)
        {
            if(mTexture.loadFromFile(pathToSprite))
            {
                mSprite.setTexture(mTexture);
            }
            else
            {
                std::cerr << "Texture aus " + pathToSprite + " konnte nicht geladen werden" << std::endl;
            }
        }


#ifdef SFML

        /**********************************************
        *Descr:     Bewegt das Sprite um offset
        *Param1:    offset um den bewwegt werden soll
        ***********************************************/
        void move(const eng::Vector2f const& offset)
        {
            mSprite.move(offset.x, offset.y);
        }


        /************************
        *           SETTER
        **************************/
        void setPosition(const eng::Vector2f& pos)
        {
            mSprite.setPosition(pos.x, pos.y)
        }

        void setScale(const eng::Vector2f& scale)
        {
            mSprite.setScale(scale.x, scale.y);
        }


        /************************
        *           GETTER
        **************************/
        const sf::Vector2f& getPosition() const
        {
            return mSprite.getPosition();
        }

        const sf::Vector2f& getScale() const
        {
            return mSprite.getScale();
        }

        const sf::Texture& getTexture() const
        {
            return mTexture;
        }
        
        const sf::Sprite& getSprite() const
        {
            return mSprite;
        }
#endif

    private:
#ifdef SFML
        sf::Texture mTexture;
        sf::Sprite mSprite;
#endif
    };

};



#endif //ENGINE_SPRITE_H
