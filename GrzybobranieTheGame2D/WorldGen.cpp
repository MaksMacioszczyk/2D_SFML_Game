#include "WorldGen.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace sf;
using namespace std;


WorldGen::WorldGen(int NumberOfTreesPub)
{
	grzyb = new RectangleShape[NumberOfTreesPub / 2];
	drzewo = new RectangleShape[NumberOfTreesPub];
	muchomor = new RectangleShape[NumberOfTreesPub / 5];
	jakiGrzyb = new int[NumberOfTreesPub / 2];
	jakiMuchomor = new int[NumberOfTreesPub / 5];
	numberOfTrees = NumberOfTreesPub;
	
	teksturaDrzewa.loadFromFile("drzewo.png");
	teksturaGrzyba.loadFromFile("grzyb.png");
	teksturaMuchomora.loadFromFile("muchomor.png");
}

void WorldGen::generateTrees(int width, int height)
{
	
	
	srand(time(NULL));
	for (int i = 0; i < numberOfTrees; i++)
	{
		
		drzewo[i].setPosition(Vector2f(rand()%width,rand()%height));
		drzewo[i].setSize(Vector2f(87, 92));
		drzewo[i].setTexture(&teksturaDrzewa);
		
	}
	for (int i = 0; i < numberOfTrees / 2; i++)
	{

		grzyb[i].setPosition(Vector2f(rand() % width, rand() % height));
		grzyb[i].setSize(Vector2f(30, 30));
		grzyb[i].setTexture(&teksturaGrzyba);
		
	}
	for (int i = 0; i < numberOfTrees / 5; i++)
	{

		muchomor[i].setPosition(Vector2f(rand() % width, rand() % height));
		muchomor[i].setSize(Vector2f(30, 30));
		muchomor[i].setTexture(&teksturaMuchomora);

	}
}

void WorldGen::Draw(RenderWindow& window)
{
	for (int i = 0; i < numberOfTrees / 2; i++)
	{
		if (jakiGrzyb[i] == i)
		{
			continue;
		}
		window.draw(grzyb[i]);
	}
	for (int i = 0; i < numberOfTrees / 5; i++)
	{
		if (jakiMuchomor[i] == i)
		{
			continue;
		}
		window.draw(muchomor[i]);
	}
	for (int i = 0; i < numberOfTrees; i++)
	{
		window.draw(drzewo[i]);
	}
	

	
}

int WorldGen::isIntersecting(Player& player)
{
	for (int i = 0; i < numberOfTrees / 2; i++)
	{
		if (grzyb[i].getGlobalBounds().intersects(player.getBounds()) && jakiGrzyb[i] != i)
		{
			jakiGrzyb[i] = i;
			return 1;
		}
	}
	for (int i = 0; i < numberOfTrees / 5; i++)
	{
		if (muchomor[i].getGlobalBounds().intersects(player.getBounds()) && jakiMuchomor[i] != i)
		{
			jakiMuchomor[i] = i;
			return 2;
		}
	}
	return 0;
}


