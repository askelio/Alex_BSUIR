#include "Bullet.h"

Bullet::Bullet()
{
}


Bullet::Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_x, float dir_y, float movementSpeed)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(1.5f, 1.5f);
	this->shape.setPosition(pos_x, pos_y);

	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movementSpeed;

}

 const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//Movenent
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
