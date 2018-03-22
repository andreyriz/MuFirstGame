#include "Enemy.h"
Enemy::Enemy(sf::String it, int a, int b, float c, float d, int H, int W, float SP,int Shot)
{ 
	setHealth(a);
	setDamage(b);
	setKx(c);
	setKy(d);
	setImage(it);
	setTexture();
	setSprite();
	setptr();
	setHeight(H);
	setWidth(W);
	setSpeed(SP);
}
Enemy::Enemy(sf::String a)
{
	setImage(a);
	setTexture();
	setSprite();
	setptr();
}
Enemy::Enemy(sf::String a, float x, float y,bool n)
{
	setImage(a);
	setTexture();
	setSprite();
	setptr();
	setKx(x);
	setKy(y);
	setDir(n);
}
void Enemy::setSpeed(const float a)
{
	speed = a;
}
float Enemy::getSpeed()
{
	return speed;
}
void Enemy::setMyShot(const bool a)
{
	Myshot = a;
}
bool Enemy::getMyShot()
{
	return Myshot;
}
void Enemy::setHeight(const int a)
{
	height = a;
}
int Enemy::getHeight()
{
	return height;
}
void Enemy::setWidth(const int a)
{
	width = a;
}
int Enemy::getWidth()
{
	return width;
}
sf::Sprite* Enemy::getptr()
{
	return ptr;
}
void Enemy::setptr()
{
	ptr = &itSprite;
}
sf::Sprite Enemy::getSprite()
{
	return itSprite;
}
sf::Image Enemy::getImage()
{
	return itImg;
}
sf::Texture Enemy::getTexture()
{
	return itTexture;
}
void Enemy::setSprite()
{
	itSprite.setTexture(itTexture);
	
}
void Enemy::setImage(sf::String a)
{
	itImg.loadFromFile(a);
}
void Enemy::setTexture()
{
	itTexture.loadFromImage(itImg);
}
void Enemy::setHealth(const int a)
{
	health = a;
}
int Enemy::getHealth()
{
	return health;
}
void Enemy::setDamage(const int a)
{
	damage = a;
}
int Enemy::getDamage()
{
	return damage;
}
void Enemy::setKx(const float a)
{
	kx = a;
}
float Enemy::getKx()
{
	return kx;
}
void Enemy::setKy(const float a)
{
	ky = a;
}
float Enemy::getKy()
{
	return ky;
}
void Enemy::setDir(const bool a)
{
	direction = a;
}
bool Enemy::getDir()
{
	return direction;
}

void Enemy::setWhatAboutShot(const int a)
{
	WhatAboutShot = a;
}

int Enemy::getWhatAboutShot()
{
	return WhatAboutShot;
}

void Enemy::movement(const float time) {}

sf::FloatRect Enemy::getRect()
{
	return sf::FloatRect(getKx(), getKy(), getWidth(), getHeight());
}