#pragma once
#include <SFML\Graphics.hpp>
#include "Animacja.h"

using namespace sf;

class Player
{
public:
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);


	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void resetPlayer(Vector2f newPosition);


private:
	RectangleShape body;
	Animacja animation;
	unsigned int row;
	float speed;
	bool faceRight;

};

