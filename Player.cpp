#include "Player.h"
#include "Resources.h"
#include "Utils.h"
#include "Network.h"
#include <cmath>

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1)),
    network(game)
{
    mapInput();
    state = START_MENU;
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addMouseMapping(sf::Mouse::Button::Left);
}
        
void Player::update(float deltaTime) {
    switch(state) {

    case START_MENU:
        startMenu(deltaTime);
        break;
    case SELECT_BEAST:
        selectBeast(deltaTime);
        break;
    case UPGRADE_BEAST:
        upgradeBeast(deltaTime);
        break;
    case CITIES_INITIALITZATION:
        citiesInitialitzation(deltaTime);
        break;
    case BEFORE_CITY_SELECTION:
        beforeCitySelection(deltaTime);
        break;
    case CITY_SELECTION:
        citySelection(deltaTime);
        break;
    case AFTER_CITY_SELECTION:
        afterCitySelection(deltaTime);
        break;
    case MOVE_NEXT_CITY:
        moveNextCity(deltaTime);
        break;
    case MOVING_ANIMATION:
        movingAnimation(deltaTime);
        break;
    case IN_BATTLE:
        inBattle(deltaTime);
        break;
    case BATTLE_ANIMATION:
        battleAnimation(deltaTime);
        break;
    case BATTLE_RESULT:
        battleResult(deltaTime);
        break;
    case ROUND_RESULT:
        roundResult(deltaTime);
        break;
    default:
        break;
    }

}

void Player::startMenu(float deltaTime) {

}

void Player::selectBeast(float deltaTime) {
    numBeasts = 10;
    beasts = Beasts(numBeasts, 10, 10, 10, 10, 10);
}

void Player::upgradeBeast(float deltaTime) {

}

void Player::citiesInitialitzation(float deltaTime) {

}

void Player::beforeCitySelection(float deltaTime) {

}

void Player::citySelection(float deltaTime) {

}

void Player::afterCitySelection(float deltaTime) {

}

void Player::moveNextCity(float deltaTime) {
    numCityBeasts = 100;
    cityBeasts = Beasts(numCityBeasts, 100, 100, 100, 100, 100);
}

void Player::movingAnimation(float deltaTime) {

}

void Player::inBattle(float deltaTime) {
    BattleManager::resolveBattle(&beasts, &cityBeasts);
    state = BATTLE_ANIMATION;
}

/**
 * Decrements numBeasts and numCityBeasts until they
 * reach the respective beasts.size()
 */
void Player::battleAnimation(float deltaTime) {
     timer += deltaTime;
     
     if (timer > 0.2) {
         timer = 0;
         int deltaBeasts = (int)std::ceil((numBeasts - beasts.beasts.size())/7.0);
         int deltaCityBeasts = (int)std::ceil((numCityBeasts - cityBeasts.beasts.size())/7.0);
         
         numBeasts -= deltaBeasts;
         numCityBeasts -= deltaCityBeasts;

         if(deltaBeasts == 0 && deltaCityBeasts == 0) {
             state == BATTLE_RESULT;
         }
     }
}

void Player::battleResult(float deltaTime) {
    if(beasts.beasts.size() <= 0) {
        state = ROUND_RESULT;
    } else {
        state = MOVE_NEXT_CITY;
    }
}

void Player::roundResult(float deltaTime) {
}
