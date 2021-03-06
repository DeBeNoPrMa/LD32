#include "Utils.h"
#include <math.h>

sf::Vector2f normalizeWithLength(sf::Vector2f vec, float length) {
    sf::Vector2f result = vec;
    float size = sqrt(vec.x*vec.x + vec.y*vec.y);
    vec /= size;
    vec *= length;

    return result;
}

sf::Vector2f limitVector2f(sf::Vector2f vec, sf::Vector2f limits) {
    if (vec.x > limits.x)
        vec.x = limits.x;
    else if (vec.x < - limits.x)
        vec.x = -limits.x;
    if (vec.y > limits.y)
        vec.y = limits.y;
    else if (vec.y < -limits.y)
        vec.y = -limits.y;
    return vec;
}

sf::Vector2f limitToScreen(sf::Vector2f vec, sf::Vector2f size) {
    if (vec.x > 1500 - size.x)
        vec.x = 1500 - size.x;
    else if (vec.x < 0)
        vec.x = 0;
    if (vec.y > 1000 - size.y)
        vec.y = 1000 - size.y;
    else if (vec.y < 0)
        vec.y = 0;
    return vec;
}

bool isPointInsideRectangle(sf::Vector2f vec, sf::FloatRect rect) {
    if (vec.x >= rect.left &&
        vec.x <= rect.left + rect.width &&
        vec.y >= rect.top &&
        vec.y <= rect.top + rect.height) {
        return true;
    }
    return false;
}