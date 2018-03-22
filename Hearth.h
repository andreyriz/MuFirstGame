#ifndef __Hearth__
#define __Hearth__
#include <SFML/Graphics.hpp>
#include <vector>
class Hearth
{
	//**********Графика*************//
	sf::Image img;
	sf::Texture text;
	sf::Sprite *ptr;
	sf::Sprite spr;
	//**************************//
	int width;
	int height;
	//**********позиция********//
	int kx;
	int ky;
	//************************//
public:
	Hearth();
	Hearth(sf::String img, int W, int H, int x, int y);
	void setHeight(int a);
	void setWidth(int a);
	void setKx(int a);
	void setKy(int a);
	void setImage(sf::String a);
	void setTexture();
	void setSprite();
	void setptr();
	int getHeight();
	int getWidth();
	int getKx();
	int getKy();
	sf::Sprite* getptr();
	sf::Image getImage();
	sf::Texture getTexture();
	sf::Sprite getSprite();
	~Hearth();
};
#endif
