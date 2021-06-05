#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>


void Game::initPlayer()
{
	this->player = new Player();

}

void Game::initVariables()
{
	this->window = nullptr;

	//game logic
	this-> points=0;
	this->health = 10;

	this->starSpawnTimer = this->starSpawnTimerMax;
	this->starSpawnTimerMax = 1000.f;

	this->enemySpawnTimer=this->enemySpawnTimerMax;
	this->enemySpawnTimerMax=70.f;
	this->MaxEnemies=5;
	this->EnemySpeed = 1.f;

	this->endGame = false;

	this->attackCoolDownMax = 100.f;
	this->attackCoolDown = this->attackCoolDownMax;
	
	this->starCoolDownMax = 1000.f;
	this->starCoolDown = this->attackCoolDownMax;

}

void Game::initWindow()
{
	this->videMode.height = 600;
	this->videMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "AirAssault", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void Game::initFont()
{
	if (!(this->font.loadFromFile("Fonts/Dosis-Light.ttf"))) 
	{
		std::cout << "ERROR:GAME:INITFONTFS: Failed to load the fonts ! \n";
	};
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(30);
	
	
	this->uiText.setFillColor(sf::Color::White);
	
	
	
	
}

void Game::initEnemies()
{
	
	initTextures();
	initSprites();

	
}

void Game::initTextures()
{

	if (!this->texture1.loadFromFile("Sprites/plane2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	if (!this->texture2.loadFromFile("Sprites/plane5.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	if (!this->texture3.loadFromFile("Sprites/plane5.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}

	if (!this->bulTexture.loadFromFile("Sprites/bullet1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	if (!this->BackTexture.loadFromFile("Sprites/Back.jpg"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	if (!this->bulTexture2.loadFromFile("Sprites/bullet2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}
	if (!this->StarTexture.loadFromFile("Sprites/star.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file \n";
	}

	
	

	
}

void Game::initSprites()
{
	
	
	this->enemy1.setTexture(this->texture1);

	//Resize the sprite
	this->enemy1.setScale(-1.5, -1.5);

	this->enemy2.setTexture(this->texture2);

	//Resize the sprite
	this->enemy2.setScale(-1.5, -1.5);

	this->enemy3.setTexture(this->texture3);

	
	
	//Resize the sprite
	this->enemy3.setScale(-1.5, -1.5);


	//Star
	
	this->StarSprite.setTexture(this->StarTexture);
	this->StarSprite.setScale(1.5, 1.5);

	//BackGround
	this->BackSprite.setTexture(this->BackTexture);
	BackSprite.setScale(1.1f, 1.f);

}



Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
	

	this->initTextures();
	this->initEnemies();
	

	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	for(auto *i :this->bullets)
	{
		delete i;
	}
	for (auto* i : this->enemyBullets)
	{
		delete i;
	}
}




const bool Game::running() const
{	
	return this->window->isOpen();
}

void Game::spawnEnemy()
{
	//Spawns enemies and sets their position 
	// Random position , randowm adds enemy to vector
	//Sets enemies types
	
	//Randomize enemy type
	int type = rand() % 3;
	switch (type)
	{
	case 0:
		this->enemy = enemy1;
		
		break;
	case 1:
		this->enemy = enemy2;
		break;
	case 2:
		this->enemy = enemy3;
		break;
	default:
		break;
	}
	

	this->enemy.setPosition(
		static_cast<float>(rand()% static_cast<int>(this->window->getSize().x - this->enemy.getGlobalBounds().width)+100),
		0.f
	);
	
	
	
	
	
	this->enemies.push_back(this->enemy);
	

}

void Game::GameOverText()
{
	
	
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(70);


	this->uiText.setFillColor(sf::Color::Red);

	this->uiText.setPosition(380.f , 300.f);
	
	std::stringstream ss;

	ss << "GAME OVER";

	this->uiText.setString(ss.str());
	
	this->window->clear();
	this->renderBackGround(*this->window);
	
		
	pollEnents();
	this->window->draw(this->uiText);
	this->window->display();
	
	
	
	
}

void Game::update()
{
	
	
	this->pollEnents();
	
	//this->updateStar();
	this->updateEnemies();
	this->updateText();
	this->updateGameInput();
	this->updateBullets();
	this->player->update(this->window);
	this->EnemyUpdateAttack();
	this->updateStar();
	if (this->health<= 0 )
	{
		gameOver = true;
	}
	
}


void Game::updateEnemies()
{
	
	
	//Updating the timer for enemy spawning 
	if (this->enemies.size() < this->MaxEnemies)
	{
		//Spawn the enemy and reset the timer 

		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}

	//Removes enemies 

	 
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;
		
		
		this->enemies[i].move(0.f, this->EnemySpeed);
		if (this->enemies[i].getTexture()==&this->texture1 && this->EnemyCanAttack())
		{
			this->enemyBullets.push_back(new Bullet(&this->bulTexture2, this->enemies[i].getPosition().x-20, this->enemies[i].getPosition().y, 0.f, +1.f, this->EnemySpeed+1));
			this->enemyBullets.push_back(new Bullet(&this->bulTexture2, this->enemies[i].getPosition().x-150, this->enemies[i].getPosition().y, 0.f, +1.f, this->EnemySpeed + 1));
		}
				
		for (size_t k = 0; k < bullets.size() && !deleted; k++)
		{
			if (this->bullets[k]->getBounds().intersects(this->enemies[i].getGlobalBounds()))
			{
				this->bullets.erase(this->bullets.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);
				points += 10;
				EnemySpeed += 0.02;
				deleted = true;
				
			}
		}
		for (size_t k = 0; k < enemyBullets.size() && !deleted; k++)
		{
			
			if (this->enemyBullets[k]->getBounds().intersects(this->player->getBounds()))
			{
				this->enemyBullets.erase(this->enemyBullets.begin() + k);
				health -= 1;
								
				deleted = true;

			}
		}
		
		//if the enemy is passed the bottom of the screen 
		if (!deleted )
		{
			if (this->enemies[i].getPosition().y > this->window->getSize().y)
			{
				this->health -= 1;
				this->enemies.erase(this->enemies.begin() + i);
				deleted = true;
				
			}
		}
		

		
	}


}

void Game::updateText()
{
	
	
		std::stringstream ss;

		ss << "Points: " << this->points << "\n" << "Health: " << this->health ;

		this->uiText.setString(ss.str());
	
	
	

}

void Game::updateBullets()
{
	unsigned counter = 0;
	unsigned counter2 = 0;
	
	for (auto* i : this->bullets)
	{
		i->update();
		


		if (i->getBounds().top + i->getBounds().height <=0.f )
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

		}

		++counter;
	}

	for (auto* i : this->enemyBullets)
	{
		i->update();



		if (i->getBounds().top + i->getBounds().height <= 0.f)
		{
			delete this->enemyBullets.at(counter);
			this->enemyBullets.erase(this->enemyBullets.begin() + counter);
			--counter2;

		}

		++counter2;
	}
	
	
}



void Game::renderStar(sf::RenderTarget& target)
{
	for (auto& e : this->stars)
	{
		target.draw(e);
	}
}

void Game::renderBackGround(sf::RenderTarget& target)
{
	target.draw(this->BackSprite);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::render()
{
	
	
	this->window->clear();
//BackGround
	this->renderBackGround(*this->window);

//Render the player
	this->player->render(this->window);

//Draw game objects
	this->renederEnemies(*this->window);
	this->renderText(*this->window);
	this->renderStar(*this->window);


//Bullets
	for (auto *i : this->bullets)
	{
		i->render(this->window);
	}
	for (auto* i : this->enemyBullets)
	{
		i->render(this->window);
	}

	


//Star
	//this->renderStar(*this->window);

	this->window->display();

	
}

void Game::renederEnemies(sf::RenderTarget& target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}

void Game::pollEnents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::updateGameInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(&this->bulTexture, this->player->getPos().x, this->player->getPos().y, 0.f ,-1.f ,3));
	}
}


void Game::EnemyUpdateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
	{
		this->attackCoolDown += 0.5f;
	}


}

const bool Game::EnemyCanAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 0.f;
		return true;
	}

	return false;
}

void Game::spawnStar()
{
	this->StarSprite.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getGlobalBounds().width) + 100),
		0.f
	);
	this->stars.push_back(this->StarSprite);
}

void Game::updateStar()
{
	
		//Spawn the star and reset the timer 

		if (this->starCoolDown >= this->starCoolDownMax)
		{
			this->spawnStar();
			this->starCoolDown = 0.f;
		}
		else
		{
			this->starCoolDown += 1.f;
		}
	

	//Removes stars 


	for (int i = 0; i < this->stars.size(); i++)
	{
		bool deleted = false;


		this->stars[i].move(0.f, this->EnemySpeed);
		

		for (size_t k = 0; k < stars.size() && !deleted; k++)
		{
			 
			sf::Sprite a = this->stars[k];
			if (a.getGlobalBounds().intersects(this->player->getBounds()))
			{
				this->stars.erase(this->stars.begin() +i);
				
				health += 5;
				
				deleted = true;

			}
		}

		//if the star is passed the bottom of the screen 
		if (!deleted)
		{
			if (this->stars[i].getPosition().y > this->window->getSize().y)
			{
				
				this->stars.erase(this->stars.begin() + i);
				deleted = true;

			}
		}



	}
}
