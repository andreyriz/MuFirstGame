#include <SFML/Graphics.hpp>
#include<Windows.h>
#include <vector>
#include<iostream>
#include "Hero.h"
#include "Map.h"
#include "Bullet.h"
#include "StandartAlienEN.h"
#include "Hearth.h"
std::vector<Bullet*> itBall;//все пули 
std::vector<Enemy*> enemy;//все противники
int HowManyEnemy = 0;//количество врагов
void menu(sf::RenderWindow & window)
{
	sf::Texture GoGame, GoExit, menuBackground;
	GoGame.loadFromFile("img/menu/GoGame.png");
	GoExit.loadFromFile("img/menu/Esc.png");
	menuBackground.loadFromFile("img/background.png");
	sf::Sprite game(GoGame), exit(GoExit), back(menuBackground);//графика

	game.setScale(0.5, 0.5);//размер кнопок
	exit.setScale(0.2, 0.2);

	bool isMenu = true;

	game.setPosition(100, 30);
	exit.setPosition(100, 500);
	back.setPosition(0, 0);//позиционирование 

	while (isMenu)
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		game.setColor(sf::Color::White);
		exit.setColor(sf::Color::White);
		window.clear();
		if (sf::IntRect(100, 30, 349, 349).contains(sf::Mouse::getPosition(window)))//наведение на кнопку
		{
			game.setColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//при нажатии выйти из меню
			{
				isMenu = false;
			}
		}
		if (sf::IntRect(100, 500, 349, 349).contains(sf::Mouse::getPosition(window)))
		{
			exit.setColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window.close();
			}
		}
		window.draw(back);
		window.draw(game);
		window.draw(exit);
		window.display();
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	//****************************Инициализация звуков**********************//
	sf::SoundBuffer buffer;
	buffer.loadFromFile("img/piu.ogg");
	sf::Sound sound;//звук выстрела
	sound.setBuffer(buffer);
	sound.setVolume(100);
	sf::Music music;
	music.openFromFile("img/music.ogg");//музыка на фоне
	music.setLoop(true);
	//*********************************************************************//

	enemy.push_back(new StandartAlienEN("img/hero/5.png", 3, 1, 1, 1, 98, 171, 0.5, 0, true));
	HowManyEnemy++;
	sf::Int64 time;//переменная для приязки игры ко времени 
	bool win = true;//условие победы

	int X = GetSystemMetrics(SM_CXSCREEN);//размеры окна 
	int Y = GetSystemMetrics(SM_CYSCREEN);

	enemy.push_back(new StandartAlienEN("img/hero/5.png", 3, 1, X - 98, 1, 98, 171, 0.5, 0, false));
	HowManyEnemy++;
	sf::RenderWindow window(sf::VideoMode(X, Y), "myGame", sf::Style::Fullscreen);
	//sf::RenderWindow window(sf::VideoMode(1200, 800), "mygame"); X = 1200; Y = 800;

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);//настройки самой игры 
	window.setKeyRepeatEnabled(false);

	menu(window);
	Map it;
	sf::Clock clock;
	Hero one("img/hero/1.png", 3, 1, X / 2, Y - 135, 124, 135, 0.8, 0);
	std::vector<Hearth*> myHearth;//графический способ отображения жизней
	bool pause = false;
	while (myHearth.size() < one.getHealth())
	{
		static int pozX = 0;
		myHearth.push_back(new Hearth("img/hearth.png", 116, 102, 0 + pozX, (Y - 116)));
		pozX += 102;
	}
	music.play();
	while (window.isOpen() && one.getHealth() > 0 && enemy.size() != 0)
	{
		if (!pause)
		{
			time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 1800;
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					/*window.close();*/
					win = false;
					one.setHealth(0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))//пауза 
				{
					pause = true;
				}
			}
			one.movement(time);
			if (one.getMyShot() == true)//добавление пуль героя
			{
				one.setWhatAboutShot(one.getWhatAboutShot() + 1);
				one.setMyShot(false);
				itBall.push_back(new Bullet("img/shot/shotHero.png", one.getKx(), one.getKy(), one.getDir(), 87, 128, 2));
				sound.play();
			}
			//**************************правила попадения пуль и ранение героя и противников****************************//
			for (size_t i = 0; i < itBall.size(); i++)
			{
				for (size_t z = 0; z < enemy.size(); z++)
				{
					if (itBall[i]->getRect().intersects(enemy[z]->getRect()) && itBall[i]->getDir() == true ||
						itBall[i]->getRect().intersects(one.getRect()) && itBall[i]->getDir() == false)
					{
						if (itBall[i]->getRect().intersects(enemy[z]->getRect()) && itBall[i]->getDir() == true)
						{
							if (enemy[z]->getHealth() > 0)
							{
								enemy[z]->setHealth(enemy[z]->getHealth() - one.getDamage());
							}
							if (i < itBall.size())
							{
								itBall.erase(itBall.begin() + i);
								one.setWhatAboutShot(one.getWhatAboutShot() - 1);
							}
							else
							{
								break;
							}
						}
						else
							if (itBall[i]->getRect().intersects(one.getRect()) && itBall[i]->getDir() == false)
							{
								if (one.getHealth() > 0)
								{
									one.setHealth(one.getHealth() - enemy[z]->getDamage());
									myHearth.erase(myHearth.begin() + myHearth.size() - 1);
								}
								if (i < itBall.size())
								{
									itBall.erase(itBall.begin() + i);
									enemy[z]->setWhatAboutShot(enemy[z]->getWhatAboutShot() - 1);
								}
								else
								{
									break;
								}
							}
					}
					else
						if (itBall[i]->getKy() < 0 - itBall[i]->getHeight()
							|| itBall[i]->getKy() > Y + itBall[i]->getHeight())
							//если пуля вышла то добавим ее обратно в обойму 
						{
							if (itBall[i]->getKy() > Y)
							{
								enemy[z]->setWhatAboutShot(enemy[z]->getWhatAboutShot() - 1);
							}
							if (itBall[i]->getKy() < Y)
							{
								one.setWhatAboutShot(one.getWhatAboutShot() - 1);
							}
							itBall.erase(itBall.begin() + i);
						}
						else
						{
							itBall[i]->movement(time);
						}
				}
			}
			//********************************************************************//
			for (size_t z = 0; z < enemy.size(); z++)
			{
				enemy[z]->movement(time);
			}
			window.draw(it.getSprite());
			for (size_t z = 0; z < enemy.size(); z++)
			{
				if (enemy[z]->getHealth() <= 0)
				{
					enemy.erase(enemy.begin() + z);
					/*for (size_t i = 0; i < itBall.size(); i++)
					{
						if (itBall[i]->getDir() == false)
						{
							itBall.erase(itBall.begin() + i);
						}
					}*/
				}
				else
					window.draw(enemy[z]->getSprite());
			}
			for (size_t i = 0; i < myHearth.size(); i++)
			{
				window.draw(myHearth[i]->getSprite());
			}
			for (size_t i = 0; i < itBall.size(); i++)
			{
				window.draw(itBall[i]->getSprite());
			}
			window.draw(one.getSprite());
			window.display();
			window.clear();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			pause = false;
			clock.restart();
		}
	}
	sf::Image winI;//картинка победы 

	if (win && one.getHealth() > 0)
	{
		winI.loadFromFile("img/win/win.png");
	}
	else
	{
		winI.loadFromFile("img/win/loss.png");
	}

	sf::Texture winT;
	winT.loadFromImage(winI);
	sf::Sprite winS;//картинка победы
	winS.setTexture(winT);

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		window.draw(winS);
		window.display();
		window.clear();
	}
	window.close();
	return 0;
}