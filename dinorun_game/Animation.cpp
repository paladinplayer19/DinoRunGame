#include "Animation.h"

Animation::Animation()
	: frames()
	, sprite(nullptr)
	, playBackSpeed(15.0f)
	, loop(true)
	, nextFrameChange()
	, currentFrame(0)
	, playing(true)
{
}

void Animation::AddFrame(sf::Texture* newFrame)	
{
	if (newFrame)
	{
		frames.push_back(newFrame);
	}
}

void Animation::SetSprite(sf::Sprite* newSprite)
{
	sprite = newSprite;
}

void Animation::SetPlayBackSpeed(float newPlayBackSpeed)
{
	playBackSpeed = newPlayBackSpeed;
}

void Animation::SetLoop(bool newLoop)
{
	loop = newLoop;
}

bool Animation::GetPlaying()
{
	return playing;
}

void Animation::Update(sf::Time frameTime)
{
	if (playing)
	{

		nextFrameChange -= frameTime;

		if (nextFrameChange.asSeconds() <= 0)
		{
			++currentFrame;

			if (currentFrame >= frames.size())
			{
				if (loop)
				{
					currentFrame = 0;
				}
				else
				{
					currentFrame = frames.size() - 1;
					playing = false;
				}

			}

			if (sprite)
			{
				sprite->setTexture(*frames[currentFrame]);
			}

			float timeToChange = 1.0f / playBackSpeed;
			nextFrameChange = sf::seconds(timeToChange);
		}
	}
}

void Animation::Play()
{
	playing = true;

	if (sprite)
	{
		sprite->setTexture(*frames[currentFrame]);
	}
}

void Animation::Pause()
{
	playing = false;
}

void Animation::Stop()
{
	playing = false;
	currentFrame = 0;

	if (sprite)
	{
		sprite->setTexture(*frames[currentFrame]);
	}

	float timeToChange = 1.0f / playBackSpeed;
	nextFrameChange = sf::seconds(timeToChange);
}
