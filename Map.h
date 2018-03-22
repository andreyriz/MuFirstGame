#ifndef __MAP__
#define __MAP__
#include <SFML/Graphics.hpp>
class Map
{
private:

const int width = 40;
const int height = 25;
//*******картинки для карты********//
sf::String MapTile;
sf::Image MapImage;
sf::Texture MapTexture;
sf::Sprite MapSprite;
sf::Sprite *ptr;
//********************************//
public:
	Map();
	void setSprite();
	sf::Sprite getSprite();
	sf::Sprite* getptr();
};
#endif