#include "Sprite.h"

Sprite::Sprite(SDL_Renderer * _renderer, char * _file, int _x, int _y, int _w, int _h)
{
	//need to do loading of image from img_load

	//set image from surface

	//free up surface
	m_position.x = _x;
	m_position.y = _y;
	m_position.w = _w;
	m_position.h = _h;

	m_renderer = _renderer;
}

Sprite::~Sprite()
{
	if (m_text)
	{
		SDL_DestroyTexture(m_text);

	}

	SDL_DestroyRenderer(m_renderer);

}

void Sprite::drawSprite(SDL_Renderer * _renderer)
{
	if (m_text)
	{
		SDL_RenderCopy(_renderer, m_text, NULL, &m_position);
	}
}

void Sprite::setSprite(SDL_Texture * _tex)
{
	//use of this is set a image to be different texture,
	//e.g. grass and dirt for map.

	m_text = _tex;
}


