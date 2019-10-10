#ifndef _Sprite_
#define _Sprite_

#include <SDL2/SDL.h>

class Sprite
{
public:
	Sprite(SDL_Renderer* _renderer, char* _file, int _x, int _y,
		int _w, int _h);
	~Sprite();

	void drawSprite(SDL_Renderer* _renderer);
	void setSprite(SDL_Texture* _tex);

private:

	//creating renderer
	SDL_Renderer* m_renderer;

	//creating texture to use as image;
	SDL_Texture* m_text;

	//sufface to load image into
	SDL_Surface* m_surf;

	SDL_Rect m_position;

};

#endif // !_Sprite_
