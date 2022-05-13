//
// Created by Ariel_Shalem on 13/05/2022.
//

#include <string>
#include <stdbool.h>
#include "Player.h"
#include "utilities.h"

Player::Player(std::string& name, int hp, int force) :
    m_name(name),
    m_HP(hp),
    m_force(force) {}

void Player::printInfo() const {
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp() {
    if (this->m_level < maxLevel) {
        this->m_level++;
    }
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int buffPoints) {
    this->m_force += buffPoints;
    if (this->m_force < 0) {
        // In case we got a debuf, force should still not be a negative
        this->m_force = 0;
    }
}

void Player::heal(int healPoints) {
    this->m_HP += healPoints;
    this->m_HP = this->m_HP < this->m_maxHp ? this->m_HP : this->m_maxHp;
}

void Player::damage(int damagePoints) {
    this->m_HP -= damagePoints;
    this->m_HP = this->m_HP > 0 ? this->m_HP : 0;
}

bool Player::isKnockedOut() const {
    return this->m_HP == 0;
}

void Player::addCoins(int coinsToAdd) {
    this->m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay) {
    if (this->m_coins < coinsToPay) {
        return false;
    }

    this->m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}