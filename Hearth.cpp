#include "Hearth.h"



Hearth::Hearth()
{
}
Hearth::Hearth(sf::String img, int W, int H, int x, int y)
{
	setImage(img);
	setTexture();
	setSprite();
	setWidth(W);
	setHeight(H);
	setptr();
	setKx(x);
	setKy(y);
	getptr()->setPosition(getKx(), getKy());
}

void Hearth::setImage(sf::String a)
{
	img.loadFromFile(a);
}

void Hearth::setTexture()
{
	text.loadFromImage(img);
}

void Hearth::setSprite()
{
	spr.setTexture(text);
}
void Hearth::setKx(int a)
{
	kx = a;
}

void Hearth::setKy(int a)
{
	ky = a;
}

int Hearth::getKx()
{
	return kx;
}

int Hearth::getKy()
{
	return ky;
}

void Hearth::setHeight(int a)
{
	height = a;
}

void Hearth::setWidth(int a)
{
	width = a;
}

void Hearth::setptr()
{
	ptr = &spr;
}

sf::Sprite* Hearth::getptr()
{
	return ptr;
}

sf::Image Hearth::getImage()
{
	return img;
}

sf::Texture Hearth::getTexture()
{
	return text;
}

sf::Sprite Hearth::getSprite()
{
	return spr;
}


int Hearth::getHeight()
{
	return height;
}

int Hearth::getWidth()
{
	return width;
}


Hearth::~Hearth()
{
}
