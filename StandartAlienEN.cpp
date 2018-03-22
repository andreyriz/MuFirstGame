#include "StandartAlienEN.h"
extern std::vector<Bullet*> itBall;
extern std::vector<Enemy*> enemy;
extern int HowManyEnemy;
StandartAlienEN::StandartAlienEN(sf::String it = "0", int hp = 1, int dmg = 1, float x = 1, float y = 1, int W = 1,
	int H = 1, float SP = 0.5, int Shot = 0, bool right = true) : Enemy(it, hp, dmg, x, y, W, H, SP, Shot)
{
	setHealth(hp);
	setDamage(dmg);
	setKx(x);
	setKy(y);
	setImage(it);
	setTexture();
	setSprite();
	setptr();
	setHeight(H);
	setWidth(W);
	setDir(false);
	setWhatAboutShot(Shot);
	setSpeed(SP);
	setmotionRight(right);
}
void StandartAlienEN::setmotionRight(bool a)
{
	motionRight = a;
}
bool StandartAlienEN::getmotionRight()
{
	return motionRight;
}

void StandartAlienEN::movement(float time)
{
	static	int X = GetSystemMetrics(SM_CXSCREEN);
	static bool WhereEn = true;
	if (getHealth() > 0)//движение 
	{
		if (getmotionRight())
		{
			if (getKx() >= X - getWidth())
			{
				setmotionRight(!getmotionRight());
				setKy(getKy() + getSpeed()*time);
			}
			else
			{
				setKx(getKx() + getSpeed()*time);
				getptr()->setPosition(getKx(), getKy());
			}
		}
		else
		{
			if (getKx() <= 0)
			{
				setmotionRight(!getmotionRight());
				setKy(getKy() + getSpeed()*time);
			}
			else
			{
				setKx(getKx() - getSpeed()*time);
				getptr()->setPosition(getKx(), getKy());
			}
		}
		if (getWhatAboutShot() < 3)//выыстрел
		{
			setWhatAboutShot(getWhatAboutShot() + 1);
			itBall.push_back(new Bullet("img/shot/screen.png", this->getKx(), this->getKy(), getDir(), 28, 91, 2));
		}
	}
	else
		if (HowManyEnemy <= 7)
		{
			if (HowManyEnemy == 7)
			{
				enemy.push_back(new StandartAlienEN("img/hero/3B.png", 12, 1, X - 182, 1, 182, 248, 0.3, -10, false));//босс 
				HowManyEnemy++;
			}
			else
			{
				if (WhereEn)
				{
					enemy.push_back(new StandartAlienEN("img/hero/5.png", 3, 1, 1, 1, 98, 171, 0.5, 0,true));
					HowManyEnemy++;
					WhereEn = !WhereEn;
				}
				else
				{
					enemy.push_back(new StandartAlienEN("img/hero/5.png", 3, 1, X-98, 1, 98, 171, 0.5, 0, false));
					HowManyEnemy++;
					WhereEn = !WhereEn;
				}
			}
		}
}