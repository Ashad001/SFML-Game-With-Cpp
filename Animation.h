#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float TotalTime;
	float switchTime;

public:
	sf::IntRect uvRect;
	Animation(sf::Texture* i_Tex, sf::Vector2u ImageCnt, float SwitchTm);
	void Update(int row, float Deltatime);
};

