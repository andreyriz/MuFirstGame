#include "Hero.h"
Hero::Hero(sf::String it, int hp = 1, int dmg = 1, float x = 1, float y = 1, int H = 0, int W = 0, float SP=0.5,int Shot=0) 
	: Enemy(it, hp, dmg, x, y, H, W,SP,Shot)
{
	setHealth(hp);
	setDamage(dmg);
	setKx(x);
	setKy(y);
	setImage(it);
	setTexture();
	setSprite();
	setptr();
	setHeight(W);
	setWidth(H);
	getptr()->setPosition(getKx(), getKy());
	setDir(true);
	setSpeed(SP);
	setWhatAboutShot(Shot);
}
void Hero::movement(float time)//движение героя 
{
	if (getHealth() > 0)
	{
		int X = GetSystemMetrics(SM_CXSCREEN);

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && getKx() > 0)
		{
			setKx(getKx() - getSpeed()*time);
			getptr()->setPosition(getKx(), getKy());
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && getKx() < X - getWidth())
		{
			setKx(getKx() + getSpeed()*time);
			getptr()->setPosition(getKx(), getKy());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (getWhatAboutShot()<3)//если обойма не пуста то стреляем 
			{
			setMyShot(true);
			}
		}
	}
}