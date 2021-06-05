#include <iostream>



#include "Game.h"
#include "Player.h"
#include "Button.h"



void start_game();
void GetMenu();


//Game object
Game* game = new Game;


//Background music
sf::Music* Bmusic = new Music;
bool isMusic = true;

int main()
{
	srand(static_cast<unsigned>( time(NULL)));
	
	GetMenu();
	


	
}

void start_game()
{
	
	//game loop

	while (game->running())
	{
		if (!game->gameOver)
		{
			//Update
			game->update();

			//Render 


			game->render();
			
		}
		else{

			game->GameOverText();
			
			//game.render();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && game->gameOver)
		{
			
			Bmusic->stop();
			game->window->close();
			game = new Game();
			
			GetMenu();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !game->gameOver)
		{
			
			//system("Clear");
			Bmusic->stop();			
			GetMenu();
		}

		
	}
}



void GetMenu() {
	
	
	
	//Load music
	Bmusic->openFromFile("Music/Dark Side.ogg");
	
	//Create menu 
	RenderWindow menu;
	Vector2i position;
	int X, Y;
	menu.create(VideoMode(300, 300), "Menu");
	Texture texture_menu_black;
	texture_menu_black.loadFromFile("Sprites/Menuback.jpg");
	
	
	Sprite menuBackGRBlack(texture_menu_black);
	Button play(100, 50, "Play");
	Button music(100, 100, "Music ON");
	Button black(100, 150, "Dark OFF");
	Button exit(100, 200, "Exit");
	if (isMusic) music.setText("Music ON");
	if (!isMusic) music.setText("Music OFF");
	
	bool isMenuOpen = true;

	while (menu.isOpen())
	{
		

		menu.clear(Color::White);
		
		position = Mouse::getPosition(menu);
		Event e;
		Vector2i mouse;
		while (menu.pollEvent(e))
		{
			mouse = Mouse::getPosition(menu);
			play.contain(mouse); music.contain(mouse); black.contain(mouse); exit.contain(mouse);
			if (e.type == Event::Closed)
			{
				menu.close();
				isMenuOpen = false;
			}
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					if (play.select(mouse))
					{						
							menu.close();
							isMenuOpen = false;
							if (isMusic) { Bmusic->play(); }
							
							start_game();
							
					}					

					
					if (music.select(mouse))
					{
						if (isMusic) {
							music.setText("Music OFF");
							isMusic = false;
						}
						else if (!isMusic) {
							music.setText("Music ON");
							isMusic = true;
						}


					}
					
					
					if (exit.select(mouse))
					{
						game->window->close();
						menu.close();
						
						return;
					}
				}
			}
		}
		
		menu.draw(menuBackGRBlack);

		play.display(menu);
		music.display(menu);
		
		exit.display(menu);
		menu.display();
	}
}