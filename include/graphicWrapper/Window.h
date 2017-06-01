/************************************
*Author:    Thomas Dost
*Datum:     20.01.2017
*Beschr.    Wrapper uml sf::RenderWindow
*Changelog:
 20.01.2017
            Erstelldatum
 21.01.2017
           setSize(eng::Vector2i), und eng::Vector2i getSize() hinzugefuegt
31.01.2017
            setFullscreen(bool) addded
            View

*TODO:
 * Irgenwie werden 2 Fenster geoffnet WTF!!!
*************************************/
#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H
#include <SFML/Graphics.hpp>


#include "../globals.h"
#include "Vector.h"



namespace eng
{
    class Window {
    public:
#ifdef SFML

        Window(const std::string &title, const int32 width, const int32 height)
                : mTitle(title), mWidth(width), mHeight(height)
        {
            mWindow = new sf::RenderWindow(sf::VideoMode(mWidth, mHeight), mTitle);
        }

        Window(const std::string &title, eng::Vector2i size)
                : Window(title, size.x, size.y)
        {
            mWindow = new sf::RenderWindow(sf::VideoMode(mWidth, mHeight), mTitle);
        }



        /******************************
        * SFML WRAPPER
        *******************************/
        bool isOpen() { return mWindow->isOpen(); }
        void setFramerateLimit(int32 limit) { mWindow->setFramerateLimit(limit); }
        void clear() { mWindow->clear(); }
        void display() { mWindow->display(); }
        void draw(const sf::Drawable &drawable) const
        {
            mWindow->draw(drawable);
        }
        void close() { mWindow->close(); }
        bool pollEvent(sf::Event &event) { return mWindow->pollEvent(event); }
        void setToFullscreen()
        {
            //2048x1536
            mWindow->create(sf::VideoMode(2048,1536 ,32), "TEST", sf::Style::Fullscreen  );
        }
        void setSize(const eng::Vector2i size)
        {
            mWindow->setSize(sf::Vector2u(size.x, size.y));
        }
        const sf::RenderWindow &getSfRenderWindow() const {
            return *mWindow;
        }

         sf::RenderWindow &getSfRenderWindow() {
            return *mWindow;
        }
#endif
        eng::Vector2i getSize() const
        {
            return eng::Vector2i(mWidth, mHeight);
        }
    private:
        std::string mTitle;
        int32 mWidth;
        int32 mHeight;

#ifdef SFML
        sf::RenderWindow* mWindow;
#endif

    };
}
#endif //ENGINE_WINDOW_H
