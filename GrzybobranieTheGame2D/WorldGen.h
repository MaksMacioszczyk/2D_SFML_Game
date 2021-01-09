#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class WorldGen
{
public:
	WorldGen(int NumberOfTreesPub);
	RectangleShape *drzewo;
	RectangleShape* grzyb;
	RectangleShape* muchomor;
	void generateTrees(int width, int height);
	void Draw(RenderWindow &window);
	int isIntersecting(Player& player);
	Texture teksturaDrzewa;
	Texture teksturaGrzyba;
	Texture teksturaMuchomora;
private:
	
	int numberOfTrees;
	int *jakiGrzyb;
	int* jakiMuchomor;
};

