#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>




class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture bulTexture;


	void initTexture();
	void initSprite();
	
	
	void initVaroables();
	
	
	float attackCoolDown;
	float attackCoolDownMax;


	float movementSpeed;

public:




	Player(float x = 500.f, float y = 300.f);
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;

	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget * target);

	void updateAttack();
	const bool canAttack();

	void updateWindowBoundsCollision(const sf::RenderTarget* target);

	void updateInput();

	const sf::FloatRect getBounds() const;

};

