#pragma once
#include <SDL2/SDL.h>
#include "sprite.hpp"

class WitheredFoxy {
    public:
        WitheredFoxy();

        ~WitheredFoxy() = default;

        void update(double delta_time);

        void render(SDL_Surface* window_surface);

        int get_sprite_column() const { return m_sprite_column; }

        void set_sprite_column(int column) { m_sprite_column = column; }

        SDL_Rect* get_position() { return &m_position; }

    private:
        SpriteSheet m_sprite_sheet;

        int m_sprite_column;

        SDL_Rect m_position;

        double m_animation_timer;
};