#pragma once

#include <map>
#include "Directions.h"

using Animations = std::map<std::string, Anim_Base*>;

class SpriteSheet {
    public:
    SpriteSheet(TextureManager* l_textMgr);
    ~SpriteSheet();
    void CropSprite(const sf::IntRect& l_rect);
    bool LoadSheet(const std::string& l_file);
    void ReleaseSheet();
    Anim_Base* GetCurrentAnim();
    bool SetAnimation(const std::string& l_name, const bool& l_play = false, const bool& l_loop = false);
    void Update(const float& l_dT);
    void Draw(sf::RenderWindow* l_wnd);

    private:
    std::string m_texture;
    sf::Sprite m_sprite;
    sf::Vector2i m_spriteSize;
    sf::Vector2f m_spriteScale;
    Direction m_direction;
    std::string m_animType;
    Animations m_animations;
    Anim_Base* m_animationCurrent;
    TextureManager* m_textureManager;
};
