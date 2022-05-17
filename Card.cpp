#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include "utilities.h"
#include "Player.h"
#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;

Card::Card(CardType type, const CardStats &stats)
{
    this->m_effect = type;
    this->m_stats = stats;
}

static void battleEncounter(Player &player, const CardStats &cardStats)
{
    bool hasWonBattle = (player.getAttackStrength() >= cardStats.force);
    printBattleResult(hasWonBattle);

    if (hasWonBattle) {
        player.levelUp();
        player.addCoins(cardStats.loot);
    } else {
        player.damage(cardStats.hpLossOnDefeat);
    }
}

static void buffEncounter(Player &player, const CardStats &cardStats)
{
    if (player.pay(cardStats.cost)) {
        player.buff(cardStats.buff);
    }
}

static void healEncounter(Player &player, const CardStats &cardStats)
{
    if (player.pay(cardStats.cost)) {
        player.heal(cardStats.heal);
    }
}

static void treasureEncounter(Player &player, const CardStats &cardStats)
{
    player.addCoins(cardStats.loot);
}

void Card::printInfo() const
{
    switch (this->m_effect) {
    case CardType::Battle:
        printBattleCardInfo(this->m_stats);
        break;
    case CardType::Buff:
        printBuffCardInfo(this->m_stats);
        break;
    case CardType::Heal:
        printHealCardInfo(this->m_stats);
        break;
    case CardType::Treasure:
        printTreasureCardInfo(this->m_stats);
        break;
    default:
        break;
    }
}

void Card::applyEncounter(Player &player) const
{
    switch (this->m_effect) {
    case CardType::Battle:
        battleEncounter(player, this->m_stats);
        break;
    case CardType::Buff:
        buffEncounter(player, this->m_stats);
        break;
    case CardType::Heal:
        healEncounter(player, this->m_stats);
        break;
    case CardType::Treasure:
        treasureEncounter(player, this->m_stats);
        break;
    }
}
