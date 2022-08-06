#include "Animation.h"

Animation::Animation(sf::Texture* i_Tex, sf::Vector2u ImageCnt, float SwitchTm)
{
	this->imageCount = ImageCnt;
	this->switchTime = SwitchTm;
	TotalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = i_Tex->getSize().x / float(imageCount.x);
	uvRect.height = i_Tex->getSize().y / float(imageCount.y);
}

void Animation::Update(int row, float Deltatime, bool isRight = true)
{
	currentImage.y = row;
	TotalTime += Deltatime;
	if (TotalTime >= switchTime)
	{
		TotalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * abs(uvRect.height);
	if (isRight)
	{
		uvRect.left = currentImage.x * abs(uvRect.width);
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}