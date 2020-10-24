#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;
using namespace std;

int main()
{
    float playerSpeed = 0.05f;


    RenderWindow window(VideoMode(800, 600), "Grzybobranie 2D",Style::Close | Style::Resize);
   
    Texture playerTexture;
    playerTexture.loadFromFile("Male 14-1.png");


    Player player(&playerTexture, Vector2u(3, 4), 0.3f, 100.0f);

    float deltaTime = 0.0f;
    Clock clock;
  
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                cout <<"New window width:" << evnt.size.width <<" New window height:"<< evnt.size.height << endl;
                break;
            case Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }
               
            }

            if (evnt.type == evnt.Closed)
            {
                window.close();
            }
        }
        /*
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            player.move(-playerSpeed, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            player.move(playerSpeed, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            player.move(0.0f, -playerSpeed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            player.move(0.0f, playerSpeed);
        }
        */
        
        player.Update(deltaTime);

        window.clear(Color::Green);
        player.Draw(window);
        window.display();
    }

    return 0;
}