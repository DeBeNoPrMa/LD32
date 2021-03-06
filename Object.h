#ifndef __SFMLS_OBJECT_H__
#define __SFMLS_OBJECT_H__

#include "InputManager.h"
#include "Utils.h"

class Game;
class Object
{
public:
    Object();
    Object(Game* g, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount);
    ~Object();

    virtual void update(float deltaTime);
    virtual void mapInput();
    void draw();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getCenteredPosition();
    void setCenteredPosition(sf::Vector2f pos);
    sf::Vector2f getSize();

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture text;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    InputManager* inputManager;
    void moveSpriteIndex(Dir d);
    Game* game;
};

#endif
