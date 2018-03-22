#include "Map.h"
	Map::Map()
	{
		setSprite();
	}
	void Map::setSprite()
	{
		MapImage.loadFromFile("img/map.png");
		MapTexture.loadFromImage(MapImage);
		MapSprite.setTexture(MapTexture);
		ptr = &MapSprite;
		getptr()->setPosition(0, 0);
	}
	sf::Sprite Map::getSprite()
	{
		return MapSprite;
	}
	sf::Sprite* Map::getptr()
	{
		return ptr;
	}