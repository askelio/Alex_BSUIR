#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>
#include <sstream>
#include "Player.h"
#include "Bullet.h"



#ifndef GAME_H
#define GAME_H
class Game
{
private:
	
	
	
	
	Player* player;
	void initPlayer();

	
	sf::Event ev;
	sf::VideoMode videMode;

	void initVariables();
	void initWindow();
	void initFont();
	void initText();
	//Text
	sf::Text uiText;

	//Enemies
	sf::Sprite enemy;

	sf::Sprite enemy1;
	sf::Texture texture1;

	sf::Sprite enemy2;
	sf::Texture texture2;

	sf::Sprite enemy3;
	sf::Texture texture3;
		//enemy Bullets
		float attackCoolDown;
		float attackCoolDownMax;

	//BackGround
	sf::Sprite BackSprite;
	sf::Texture BackTexture;

	//Star
	std::vector<sf::Sprite> stars;
	sf::Sprite StarSprite;
	sf::Texture StarTexture;
	float starCoolDown;
	float starCoolDownMax;

	//Bullet
	

	sf::Texture bulTexture;
	sf::Texture bulTexture2;

	std::vector<Bullet*> bullets;

	std::vector<Bullet*> enemyBullets;

	void initEnemies();
	void initTextures();
	void initSprites();

	std::vector<sf::Sprite>enemies;


	//sf::RectangleShape enemy;
	

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	

	//std::vector<sf::RectangleShape> enemies;
	//Resources
	
	sf::Font font;	

	 
	//game logic
	int points;
	int health;

	float starSpawnTimer;
	float starSpawnTimerMax;


	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int MaxEnemies;

	bool endGame;
	float EnemySpeed;


public:

	sf::RenderWindow* window;

	Game();
	~Game();
	bool gameOver = false;
	

	const bool running() const;

	void spawnEnemy();

	void GameOverText();

	void update();
	
	void updateEnemies();
	void updateText();
	void updateBullets();
	void EnemyUpdateAttack();
	const bool EnemyCanAttack();

	void spawnStar();
	void updateStar();
	
	void renderStar(sf::RenderTarget& target);
	void renderBackGround(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void render();
	void renederEnemies(sf::RenderTarget& target);
	void pollEnents();

	void updateGameInput();

};


#endif 



