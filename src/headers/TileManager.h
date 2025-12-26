#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "TileConst.h"

class TileManager
{
private:
    sf::Texture texture;

public:
    TileManager();

    [[nodiscard]] bool loadTileTexture(const std::string& filename);

    const sf::Texture& getTexture() const;

    static sf::IntRect getTileRect(TileColor color);

    void setSpriteTile(sf::Sprite& sprite, TileColor color) const;

    sf::Sprite createSprite(TileColor color) const;

    static auto moveRelativeTo(sf::Sprite& sourceSprite, const sf::Sprite& relateSprite, TileDirection direction) -> void;
};