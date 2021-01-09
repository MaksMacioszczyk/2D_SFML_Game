#include "Zakonczenie.h"

Zakonczenie::Zakonczenie(float width, float height, Texture* sky)
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
	nazwa.setString("Wygrales!");
	nazwa.setPosition(Vector2f(width / 2.5, 50));

	opis.setFillColor(Color::Black);
	opis.setString("            Gra ukonczona!\nNacisnij ENTER, aby kontynuoowac");
	opis.setPosition(Vector2f(width / 4, 100));
}

Zakonczenie::~Zakonczenie()
{
}

void Zakonczenie::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(nazwa);
	window.draw(opis);
}
