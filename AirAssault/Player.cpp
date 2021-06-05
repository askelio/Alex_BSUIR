#include "Player.h"
#include <iostream>


Player::Player(float x, float y)
{
	
	this->sprite.setPosition(x, y);
	

	initVaroables();
	
	initTexture();
	initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::update(const sf::RenderTarget* target)
{
	


	this->updateInput();
	this->updateAttack();
	//Window bounds collision
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->sprite);
}

void Player::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
	{
		this->attackCoolDown += 0.5f;
	}
	

}

const bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 0.f;
		return true;
	}

	return false;
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left 
	sf::FloatRect playerBounds = this->sprite.getGlobalBounds(); 

	if (playerBounds.left <= 0.f)
	{
		this->sprite.setPosition(0.f, playerBounds.top);
	}
	//Right
	else if (playerBounds.left  + playerBounds.width >= target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x -playerBounds.width,playerBounds.top );
	}
	//Top
	 if (playerBounds.top <= 0.f)
	{
		this->sprite.setPosition(playerBounds.left, 0.f);
	}
	//Bottom
	else if (playerBounds.top + playerBounds.height >= target->getSize().y)
	{
		this->sprite.setPosition(playerBounds.left,target->getSize().y - playerBounds.height);
	}

}

void Player::updateInput()
{
	//Keyboard input

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, this->movementSpeed);
	}
	
}


void Player::initTexture()
{
	if(!this->texture.loadFromFile("Sprites/plane1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	
	
	
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.setScale(1.5, 1.5);

}

void Player::initVaroables()
{
	this->movementSpeed = 5.f;
	this->attackCoolDownMax = 10.f;
	this->attackCoolDown = this->attackCoolDownMax;
}


const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

