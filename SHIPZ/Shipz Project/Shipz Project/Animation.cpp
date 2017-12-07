#include "Animation.h"



Animation::Animation()
{
}

Animation::Animation(sf::Texture * text, sf::Vector2u imagecount, float animTime)
{
	imageCount = imagecount;
	switchTime = animTime;
	timer = 0.0f;

	currImage.x = 0;

	uvRect.width = text->getSize().x / (float)imageCount.x;
	uvRect.height = text->getSize().y / (float)imageCount.y;

	m_texture = text;

	m_shape.setSize(sf::Vector2f(uvRect.width, uvRect.height));
	m_shape.setTexture(text);
	m_shape.setOrigin(uvRect.width - (uvRect.width * 0.5f), uvRect.height - (uvRect.height * 0.5f));
}


Animation::~Animation()
{
}

void Animation::RenderLoop(int row, sf::RenderWindow * window, sf::Vector2f pos, float rotaion)
{
	currImage.y = row;

	uvRect.left = currImage.x * uvRect.width;
	uvRect.top = currImage.y * uvRect.height;

	m_shape.setRotation(rotaion);

	m_shape.setTextureRect(uvRect);
	m_shape.setPosition(pos);

	window->draw(m_shape);
}

void Animation::RenderLoop(int row, sf::RenderWindow * window, sf::Vector2f pos, bool faceRight, bool faceUp)
{
	currImage.y = row;

	if (faceRight)
	{
		uvRect.width = abs(uvRect.width);
		uvRect.left = currImage.x * uvRect.width;
	}
	else
	{
		uvRect.left = (currImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

	if (faceUp)
	{
		uvRect.height = abs(uvRect.height);
		uvRect.top = currImage.y * uvRect.height;
	}
	else
	{
		uvRect.top = (currImage.y + 1) * abs(uvRect.height);
		uvRect.height = -abs(uvRect.height);
	}
	
	m_shape.setTextureRect(uvRect);
	m_shape.setPosition(pos);

	window->draw(m_shape);
}

void Animation::Update(float deltaTime)
{
	timer += deltaTime;

	if (timer >= switchTime)
	{
		timer -= switchTime;
		currImage.x++;

		if (currImage.x >= imageCount.x)
		{
			currImage.x = 0;
		}	
	}

}
