#include "framework.h"
#include "ShootingGame.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	   :GameObject(tag, name, active, px, py)
{
	image.width  = 0;
	image.height = 0;
	image.argb	 = nullptr;
}

Sprite::~Sprite()
{
	if (image.argb != nullptr)
	{
		delete[] image.argb;
	}
}

void Sprite::setImage(const char* fileName)
{
	BMP::readBMP(fileName, &image);
}

void Sprite::draw()
{
	//�̹���(���ö���Ʈ)�׸���
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image);
}