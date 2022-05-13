//
// Created by Ariel_Shalem on 13/05/2022.
//
#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include <stdbool.h>
#include "utilities.h"

class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param hp - The max hp of player.
     * @param force - The starting force of player.
     * @return
     *      A new instance of Player.
    */
    Player(const std::string& name, const int hp = 100, const int force = 5);


    /*
     * Printing player info
     *
     * @return
     *      void
    */
    void printInfo() const;
    
    /*
     * Levels up a player
     *
     * @return
     *      void
    */
    void levelUp();

    /*
     * Returns Levels of the player
     *
     * @return
     *      int, the player's level
    */
    int getLevel() const;

    /*
     * Increase player force
     *
     * @return
     *      void
    */
    void buff(const int buffPoints);

    /*
     * Increase player current hp
     *
     * @return
     *      void
    */
    void heal(const int healPoints);

    /*
     * Decrease player current hp
     *
     * @return
     *      void
    */
    void damage(const int damagePoints);

    /*
     * Checks if Player's life reached zero
     *
     * @return
     *      bool - true if player hp is zero
    */
    bool isKnockedOut() const;

    /*
     * Increase player coins
     *
     * @return
     *      void
    */
    void addCoins(const int coinsToAdd);

    /*
     * Decrease player coins
     *
     * @return
     *      bool - True if payment was made
    */
    bool pay(const int coinsToPay);

    /*
     * Returns player overall strength
     *
     * @return
     *      int - The player's strength
    */
    int getAttackStrength() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    static const int maxLevel = 10;

private:
    static const int startingLevel = 1;
    static const int startingCoins = 0;

    std::string m_name;
    int m_maxHp;
    int m_force;
    int m_HP;
    int m_level;
    int m_coins;
};


#endif //EX2_Player_H
