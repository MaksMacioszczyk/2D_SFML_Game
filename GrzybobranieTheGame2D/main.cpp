#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Menu.h"
#include "WorldGen.h"
#include "Atlas.h"
#include "Zakonczenie.h"
#include <string>

using namespace sf;
using namespace std;

int main()
{
    int numOfWinningPoints = 30;
    float playerSpeed = 0.05f;
    bool isMenuOpen = true, isPlaying = false, isAtlasOpen = false, isZakonczenieOpen = false;
    int punkty = 0;

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {

    }

    Text punkty_tekst;
    punkty_tekst.setFont(font);
    punkty_tekst.setFillColor(Color(58, 182, 189));
    punkty_tekst.setString("Punkty: " + to_string(punkty)+" / "+to_string(numOfWinningPoints));
    punkty_tekst.setPosition(Vector2f(30,30));
    
    SoundBuffer winSound;
    winSound.loadFromFile("winSound.wav");

    SoundBuffer pickup_sound;
    pickup_sound.loadFromFile("pickup_sound.wav");

    SoundBuffer menuMusic;
    menuMusic.loadFromFile("menu.wav");

    SoundBuffer gameMusic;
    gameMusic.loadFromFile("gra.wav");

    RenderWindow window(VideoMode(800, 600), "Grzybobranie 2D",Style::Close | Style::Resize);
    RectangleShape background;
    background.setSize(Vector2f(800, 600));
 
    Texture sky;
    sky.loadFromFile("sky.jpg");

    Atlas atlas(window.getSize().x, window.getSize().y, &sky);
    Menu menu(window.getSize().x, window.getSize().y,&sky);
    Zakonczenie zakonczenie(window.getSize().x, window.getSize().y, &sky);

    Texture playerTexture;
    playerTexture.loadFromFile("Male 14-1.png");

    Texture background_texture;
    background_texture.loadFromFile("grassTexture.jpg",IntRect(0,0,800,600));
    
    WorldGen world(30);

    background_texture.setRepeated(true);
   
    background.setTexture(&background_texture);

    Player player(&playerTexture, Vector2u(3, 4), 0.3f, 100.0f);

    float deltaTime = 0.0f;
    Clock clock;
    
    Sound sound;
    sound.setVolume(2);
    sound.setBuffer(menuMusic);
    sound.play();
    Sound backSound;


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
                            if(isPlaying == false)
                            {
                                
                                break;
                            }
                            cout << "Play button" << endl;
                            sound.setBuffer(gameMusic);
                            sound.play();
                            isMenuOpen = false;
                            break;
                        case 1:
                            cout << "New game button" << endl;
                            player.resetPlayer(Vector2f(20,20));
                            isPlaying = true;
                            punkty = 0;
                            punkty_tekst.setString("Punkty: " + to_string(punkty) + " / " + to_string(numOfWinningPoints));
                            sound.setBuffer(gameMusic);
                            sound.play();
                            world.generateTrees(window.getSize().x, window.getSize().y);
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
                else if (isAtlasOpen == true)
                {
                    switch (event.key.code)
                    {
                    case Keyboard::P:
                        isAtlasOpen = false;
                        break;
                    }
                }
                else if (isZakonczenieOpen == true)
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Return:
                        isZakonczenieOpen = false;
                        isMenuOpen = true;
                        isPlaying = false;
                        punkty = 0;
                        sound.setBuffer(menuMusic);
                        sound.play();
                        break;
                    }
                }
                else
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Escape:
                        isMenuOpen = true;
                        sound.setBuffer(menuMusic);
                        sound.play();
                        break;
                    case Keyboard::E:
                        if (world.isIntersecting(player))
                        {
                            punkty += 10;
                            punkty_tekst.setString("Punkty: " + to_string(punkty) + " / " + to_string(numOfWinningPoints));
                            backSound.setBuffer(pickup_sound);
                            backSound.play();

                            cout << "Punkty: " << punkty << endl;
                        }
                        if (punkty == numOfWinningPoints)
                        {
                            
                            isZakonczenieOpen = true;
                            backSound.setBuffer(winSound);
                            backSound.play();
                        }
                        break;
                    case Keyboard::P:
                        isAtlasOpen = true;
                        break;
                    }
                }
                break;
            case Event::Closed:
                window.close();
                break;                     
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
        else if (isAtlasOpen == true)
        {
            window.clear(Color::Blue);
            atlas.draw(window);
        }
        else if(isZakonczenieOpen == true)
        {
            window.clear(Color::Blue);
            zakonczenie.draw(window);
        }
        else
        {
            window.clear(Color::Green);
            window.draw(background);
            player.Update(deltaTime);       
            player.Draw(window);
            world.Draw(window);
            window.draw(punkty_tekst);
        }

        
        
        
        window.display();
    }

    return 0;
}