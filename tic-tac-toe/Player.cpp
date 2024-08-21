#include "Player.h"

Player::Player(char symbol) : symbol(symbol) {}

char Player::getSymbol() const {
    return symbol;
}
