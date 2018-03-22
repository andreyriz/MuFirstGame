#ifndef __ENEMY__
#define __ENEMY__
#include "SFML/Graphics.hpp"
class Enemy
{
private:
	float speed;//скорость движения 
	int WhatAboutShot;//количество выстрелов в обойме 
	bool direction;//направление выстрела 
	
	int height;//размер 
	int width;

	int health;//жизнь урон 
	int damage;
	
	float kx;//позиция 
	float ky;

	bool Myshot;//выстрел
	//***************графика*********************//
	sf::Sprite itSprite;
	sf::Image itImg;
	sf::Texture itTexture;
	sf::Sprite *ptr;
	//*****************************************//
public:
	Enemy()=default;
	Enemy(sf::String a);
	Enemy(sf::String it,int a, int b, float c, float d,int W, int H, float SP, int Shot);
	Enemy(sf::String a, float x, float y,bool n);
	void setSpeed(const float a);
	float getSpeed();
	void setDir(const bool a);
	bool getDir();
	void setMyShot(const bool a);
	bool getMyShot();
	void setHeight(const int a);
	int getHeight();
	void setWidth(const int a);
	int getWidth();
	sf::Sprite *getptr();
	void setptr();
	sf::Sprite getSprite();
	sf::Image getImage();
	sf::Texture getTexture();
	void setSprite();
	void setImage(sf::String a);
	void setTexture();
	void setHealth(const int a);
	int getHealth();
	void setDamage(const int a);
	int getDamage();
	void setKx(const float a);
	float getKx();
	void setKy(const float a);
	float getKy();
	void setWhatAboutShot(const int a);
	int getWhatAboutShot();
	virtual void movement(const float time);//передвижение 
	sf::FloatRect getRect();
	~Enemy()=default;
};
#endif