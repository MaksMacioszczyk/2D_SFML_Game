#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zakonczenie
{
public:
	Zakonczenie(float width, float height, Texture* sky);
	~Zakonczenie();

	void draw(RenderWindow& window);
private:
	RectangleShape background;
	Font font;
	Text nazwa, opis;
};

