#ifndef __StandartAlienEN__
#define __StandartAlienEN__
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include "Bullet.h"
class StandartAlienEN:public Enemy
{
private:
	bool motionRight;//переменная для движения 
	bool plusEn;//переменная для добавления противников
public:
	StandartAlienEN(sf::String a,int hp, int dmg, float x, float y,int H,int W,float SP,int Shot,bool right);
	bool getmotionRight();
	void setmotionRight(bool a);
	virtual void movement(float time);
};
#endif