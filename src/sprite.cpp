#include "sprite.hpp"
#include "stdio.h"

SpriteSheet::SpriteSheet(char const *path, int row, int column)
{
    m_spritesheet_image = SDL_LoadBMP(path);

    m_clip.w = m_spritesheet_image->w / column;
    m_clip.h = m_spritesheet_image->h / row;
}

SpriteSheet::~SpriteSheet()
{
    SDL_FreeSurface(m_spritesheet_image);
}

void SpriteSheet::selectSprite(int x, int y)
{
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void SpriteSheet::renderSprite(SDL_Surface *window_surface, SDL_Rect *position)
{
    //SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
    SDL_BlitScaled(m_spritesheet_image, &m_clip, window_surface, position);
}
