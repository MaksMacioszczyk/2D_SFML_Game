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
	nazwa.setString("Muchomor");
	nazwa.setPosition(Vector2f(width / 3, 50));

	opis.setFillColor(Color::Black);
	opis.setString("Dorosly muchomor czerwony ma okolo 20 cm\n wysokosci trzonka i tyle samo srednicy kapelusza.\n Kapelusz u mlodych okazow ma ksztalt kuli, \npotem stopniowo siê splaszcza, az \ndo wglebionej formy przypominajacej nieco polmisek. \nBlaszki sa bladozolte, wpadaj¹ce w biel.\n Cechuja sie gestym rozmieszczeniem i sa \nwolne, tzn. nie sa przymocowane do trzonka.");
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
