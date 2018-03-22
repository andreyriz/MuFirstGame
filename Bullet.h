#ifndef __BULLET__
#define __BULLET__
#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include<iostream>
class Bullet:public Enemy
{
private:

public:
	Bullet(sf::String a,float x, float y,bool n);
	Bullet(sf::String a);
	Bullet(sf::String a, float x, float y, bool n, int W, int H,float SP);
	virtual void movement(float time);
	~Bullet()=default;
};
#endif