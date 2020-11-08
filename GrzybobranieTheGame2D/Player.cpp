#include "Player.h"

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture,imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(Vector2f(32.0f, 32.0f));
	body.setPosition(Vector2f(200.0f, 200.0f));

	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A))
		movement.x -= speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::D))
		movement.x += speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::W))
		movement.y -= speed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::S))
		movement.y += speed * deltaTime;


	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		row = 2;
	}
	else if(movement.x != 0.0f)
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = false;	
		else
			faceRight = true;
		
	}
	else if (movement.y < 0.0f)
	{
		row = 3;
	}
	else if (movement.y > 0.0f)
	{
		row = 0;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}

void Player::resetPlayer(Vector2f newPosition)
{
	body.setPosition(newPosition);
}

FloatRect Player::getBounds()
{
	return body.getGlobalBounds();
}
