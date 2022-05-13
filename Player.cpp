//
// Created by Ariel_Shalem on 13/05/2022.
//

#include <string>
#include <stdbool.h>
#include <assert.h>
#include "Player.h"
#include "utilities.h"

Player::Player(std::string& name, int maxHp, int force) :
    m_name(name),
    m_maxHp(maxHp),
    m_force(force),
    m_HP(maxHp),
    m_level(startingLevel),
    m_coins(startingCoins) {
    }

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
    assert(healPoints > 0);
    if (healPoints <= 0) {
        return;
    }

    this->m_HP += healPoints;
    this->m_HP = this->m_HP < this->m_maxHp ? this->m_HP : this->m_maxHp;
}

void Player::damage(int damagePoints) {
    assert(damagePoints > 0);
    if (damagePoints <= 0) {
        return;
    }

    this->m_HP -= damagePoints;
    this->m_HP = this->m_HP > 0 ? this->m_HP : 0;
}

bool Player::isKnockedOut() const {
    return this->m_HP == 0;
}

void Player::addCoins(int coinsToAdd) {
    assert(coinsToAdd > 0);
    if (coinsToAdd <= 0) {
        return;
    }

    this->m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay) {
    assert(coinsToPay > 0);
    if (coinsToPay <= 0) {
        return false;
    }

    if (this->m_coins < coinsToPay) {
        return false;
    }

    this->m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}