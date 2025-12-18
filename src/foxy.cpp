#include "foxy.hpp"
#include "stdio.h"

WitheredFoxy::WitheredFoxy(): m_sprite_sheet("assets/FoxyJumpscare.bmp", 14, 1), m_sprite_column(0), m_animation_timer(0.0) {
    m_position.x = 0;
    m_position.y = 0;
    m_position.w = m_sprite_sheet.getSpriteWidthHeight().w; //this will be scaled to the resolution later
    m_position.h = m_sprite_sheet.getSpriteWidthHeight().h;

    m_sprite_sheet.selectSprite(0, 0);
}

void WitheredFoxy::update(double delta_time) {
    m_animation_timer += delta_time;
    if (m_animation_timer >= 0.05) {
        m_animation_timer = 0.0;
        m_sprite_column = (m_sprite_column + 1) % 14; // Counts 14 frames in a single image
        m_sprite_sheet.selectSprite(0,m_sprite_column);
#ifdef DEBUG
        printf("Sprite Column: %d\n", m_sprite_column);
#endif
    }
}

void WitheredFoxy::render(SDL_Surface* window_surface) {
    m_sprite_sheet.renderSprite(window_surface, &m_position);
    SDL_Delay(45); // Small delay to visualize rendering
}
