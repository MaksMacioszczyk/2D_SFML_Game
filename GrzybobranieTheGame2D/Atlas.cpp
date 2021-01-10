#include "Atlas.h"
#include <SFML/Graphics.hpp>

Atlas::Atlas(float width, float height, Texture* sky)
{
	background.setSize(Vector2f(800.0, 600.0));
	background.setPosition(Vector2f(0, 0));
	background.setTexture(sky);

	if (!font.loadFromFile("arial.ttf"))
	{

	}
	
	nazwa.setFont(font);
	opis.setFont(font);

	nazwa.setFillColor(Color::Red);
	nazwa.setString("HELP");
	nazwa.setPosition(Vector2f(width / 3, 50));

	opis.setFillColor(Color::Black);
	opis.setString("W,S,A,D - sterowanie\n E - podnies grzyba\n Gra polega na zebraniu odpowieniej ilosci punktow \nilosc punktow jest generowana losowo. \nPo uzyskaniu odpowiedniej ilosci punktow \nuzytkownik moze stworzyc nowy poziom \n");
	opis.setPosition(Vector2f(width / 10, 100));
}

Atlas::~Atlas()
{
}

void Atlas::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(nazwa);
	window.draw(opis);
}
