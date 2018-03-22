#ifndef __Hero__
#define __Hero__
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <Windows.h>
class Hero :public Enemy
{
public:
	Hero(sf::String it, int hp, int dmg, float, float, int, int,float,int);
	virtual void movement(float time);
	~Hero()=default;
};
#endif