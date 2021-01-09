#include "Menu.h"
#include <SFML/Audio.hpp>

Menu::Menu(float width, float height, Texture* sky)
{
	
	menuSound.loadFromFile("menuSound.wav");

	background.setSize(Vector2f(800.0,600.0));
	background.setPosition(Vector2f(0, 0));
	background.setTexture(sky);

	if (!font.loadFromFile("arial.ttf"))
	{

	}

	menu[0].setFont(font);

	menu[0].setFillColor(Color(122, 55, 13));
	menu[0].setString("Graj");
	menu[0].setCharacterSize(34);
	menu[0].setPosition(Vector2f(width / 5, height / (MAX_NUM_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color(179, 81, 20));
	menu[1].setString("Nowa gra");
	menu[1].setCharacterSize(24);
	menu[1].setPosition(Vector2f(width / 5, height / (MAX_NUM_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color(179, 81, 20));
	menu[2].setString("Wyjdz");
	menu[2].setCharacterSize(24);
	menu[2].setPosition(Vector2f(width / 5, height / (MAX_NUM_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow& window)
{
	window.draw(background);
	for (int i = 0; i < MAX_NUM_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		sound.setBuffer(menuSound);
		sound.play();
		menu[selectedItemIndex].setFillColor(Color(179, 81, 20));
		
		menu[selectedItemIndex].setCharacterSize(24);
		selectedItemIndex--;
		menu[selectedItemIndex].setCharacterSize(34);
		menu[selectedItemIndex].setFillColor(Color(122, 55, 13));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUM_OF_ITEMS)
	{
		sound.setBuffer(menuSound);
		sound.play();
		menu[selectedItemIndex].setFillColor(Color(179, 81, 20));
		
		menu[selectedItemIndex].setCharacterSize(24);
		selectedItemIndex++;
		
		menu[selectedItemIndex].setCharacterSize(34);
		menu[selectedItemIndex].setFillColor(Color(122, 55, 13));
	}
}
