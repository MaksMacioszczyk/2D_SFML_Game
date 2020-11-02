#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Menu.h"

using namespace sf;
using namespace std;

int main()
{
    float playerSpeed = 0.05f;
    bool isMenuOpen = true;
    
    RenderWindow window(VideoMode(800, 600), "Grzybobranie 2D",Style::Close | Style::Resize);
    RectangleShape background;
    background.setSize(Vector2f(800, 600));
   
    Menu menu(window.getSize().x, window.getSize().y);

    Texture playerTexture;
    playerTexture.loadFromFile("Male 14-1.png");

    Texture background_texture;
    background_texture.loadFromFile("grassTexture.jpg",IntRect(0,0,800,600));
    
    background_texture.setRepeated(true);
   
    background.setTexture(&background_texture);

    Player player(&playerTexture, Vector2u(3, 4), 0.3f, 100.0f);

    float deltaTime = 0.0f;
    Clock clock;
  
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                if(isMenuOpen == true)
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case Keyboard::Down:
                        menu.MoveDown();
                        break;
                    case Keyboard::Return:
                        switch (menu.getPressedItem())
                        {
                        case 0:
                            cout << "Play button" << endl;
                            isMenuOpen = false;
                            break;
                        case 1:
                            cout << "New game button" << endl;
                            player.resetPlayer(Vector2f(20,20));
                            isMenuOpen = false;
                            break;
                        case 2:
                            cout << "Quit button" << endl;
                            window.close();
                            break;
                        }
                        break;
                    case Keyboard::Escape:
                        isMenuOpen = false;
                        break;
                    }
                }
                else
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Escape:
                        isMenuOpen = true;
                        break;
                
                    }
                }
                break;
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                cout <<"New window width:" << event.size.width <<" New window height:"<< event.size.height << endl;
                break;
            case Event::TextEntered:
                if (event.text.unicode < 128)
                {
                    printf("%c", event.text.unicode);
                }
               
            }

            if (event.type == event.Closed)
            {
                window.close();
            }
        }
        
       

        if (isMenuOpen == true)
        {
            
            window.clear(Color::Black);
            menu.draw(window);
        }
        else
        {
            window.clear(Color::Green);
            window.draw(background);
            player.Update(deltaTime);       
            player.Draw(window);
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
        
        
        window.display();
    }

    return 0;
}