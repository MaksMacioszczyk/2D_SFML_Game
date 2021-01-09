#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Atlas
{
public:
	Atlas(float width, float height, Texture* sky);
	~Atlas();

	void draw(RenderWindow& window);
private:
	RectangleShape background;
	Font font;
	Text nazwa, opis;
};

