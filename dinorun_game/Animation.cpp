#include "Animation.h"

Animation::Animation()
	: frames()
	, sprite()
	, playBackSpeed()
	, loop()
	, nextFrameChange()
	, currentFrame()
	, playing()
{
}

void Animation::AddFrame(sf::Texture* newFrame)
{
}

void Animation::SetSprite(sf::Sprite* newSprite)
{
}

void Animation::SetPlayBackSpeed(float newPlayBackSpeed)
{
}

void Animation::SetLoop(bool newLoop)
{
}

void Animation::GetPlaying()
{
}

void Animation::Update(sf::Time frameTime)
{
}

void Animation::Play()
{
}

void Animation::Pause()
{
}

void Animation::Stop()
{
}
