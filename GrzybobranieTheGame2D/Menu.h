#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define MAX_NUM_OF_ITEMS 5

using namespace sf;


class Menu
{
public:
	Menu(float width, float height,Texture* sky);
	~Menu();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedItem() { return selectedItemIndex; };

private:
	Sound sound;
	SoundBuffer menuSound;
	RectangleShape background;
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUM_OF_ITEMS];

};

