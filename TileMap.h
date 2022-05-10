#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class TileMap : public sf::Drawable, sf::Transformable      // this class is taken from sfml learning website! LINK IN THE END
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

public:
    void load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};

// https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php