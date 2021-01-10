#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define MAX_NUM_OF_ITEMS 3

using namespace sf;


class PoziomTrudnosci
{
public:
	PoziomTrudnosci(float width, float height, Texture* sky);
	

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

