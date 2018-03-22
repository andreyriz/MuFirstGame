#include "Bullet.h"
#include <Windows.h>
Bullet::Bullet(sf::String a, float x, float y, bool n) :Enemy(a, x, y, n)
{
	setImage(a);
	setTexture();
	setSprite();
	setptr();
	setKx(x);
	setKy(y);
	setHealth(1);
	setDir(n);
	getptr()->setPosition(getKx(), getKy());
}
Bullet::Bullet(sf::String a) :Enemy(a)
{
	setImage(a);
	setTexture();
	setSprite();
	setptr();
	setHealth(1);
	getptr()->setPosition(getKx(), getKy());
}
Bullet::Bullet(sf::String a, float x, float y, bool n, int W, int H, float SP=0.5)
{
	setImage(a);
	setTexture();
	setSprite();
	setptr();
	setKx(x);
	setKy(y);
	setHealth(1);
	setDir(n);
	setWidth(W);
	setHeight(H);
	setSpeed(SP);
	getptr()->setPosition(getKx(), getKy());
}
void Bullet::movement(float time)//передвижение 
{
	static	int X = GetSystemMetrics(SM_CXSCREEN);
	static	int Y = GetSystemMetrics(SM_CYSCREEN);

		if (getDir())//стреляет перс 
		{
			setKy(getKy() - getSpeed()*time);
			getptr()->setPosition(getKx(), getKy());
		}
		else
			if (!getDir())//стреляет противник 
			{
				setKy(getKy() + getSpeed()*time);
				getptr()->setPosition(getKx(), getKy());
			}
}