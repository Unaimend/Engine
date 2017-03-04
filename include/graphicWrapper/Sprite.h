/************************************
Author:     Thomas Dost
Datum:      27.01.2017
Beschr.
            Wrapper um sf::Sprite
Changelog:
27.01.2017
            Erstelldatum
04.03.2017
            const& getSize zu const getSize geändert
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
        Sprite() = default;

        Sprite(filepath pathToSprite)
        {
            //@TODO Hier setSprite benutzen
            bool isLoaded = mTexture.loadFromFile(pathToSprite);
            if(isLoaded)
            {
                mSprite.setTexture(mTexture);
                std::cout <<  "Texture aus " + pathToSprite + " konnte ERFOLGREICH geladen werden" << std::endl;
            }
            else
            {
                std::cerr << "Texture aus " + pathToSprite + " konnte nicht geladen werden" << std::endl;
                exit(-1);
            }
        }


#ifdef SFML

        /**********************************************
        *Descr:     Bewegt das Sprite um offset
        *Param1:    offset um den bewwegt werden soll
        ***********************************************/
        void move(const eng::Vector2f& offset)
        {
            mSprite.move(offset.x, offset.y);
        }


        void draw(const sf::RenderWindow& window) const
        {
            //@TODO Herrausfinden ob das safe ist
           const_cast<sf::RenderWindow&>(window).draw(mSprite);
        }

        void draw(const eng::Window& window) const
        {
            window.draw(mSprite);
        }


        /************************
        *           SETTER
        **************************/
        void setPosition(const eng::Vector2f& pos)
        {
            mSprite.setPosition(pos.x, pos.y);
        }

        void setScale(const eng::Vector2f& scale)
        {
            mSprite.setScale(scale.x, scale.y);
        }

        void setSprite(filepath pathToSprite)
        {
            bool isLoaded = mTexture.loadFromFile(pathToSprite);
            if(isLoaded)
            {
                mSprite.setTexture(mTexture);
            }
            else
            {
                std::cout <<  "Texture aus " + pathToSprite + " konnte ERFOLGREICH geladen werden" << std::endl;
                std::cerr << "Texture aus " + pathToSprite + " konnte nicht geladen werden" << std::endl;
                exit(-1);
            }

        }


        /************************
        *           GETTER
        **************************/
        const sf::Vector2u getSize()
        {
            return mTexture.getSize();
        }

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


        //@TODO Warum darf der Return keine Referenz sein
        const sf::Sprite getSprite() const
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
