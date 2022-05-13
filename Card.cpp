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

Card::Card(CardType type, const CardStats& stats){
//C'tor of Card class.

  this->m_effect = type;
  this ->m_stats = stats;
  
}

static void battleEncounter(Player& player, const CardStats& stats) {
//Plays an encounter of the player with a battle card.

  assert(player && stats);
  bool isWonBattle = player.getAttackStrength() >= stats.force;
  printBattleResult(isWonBattle);

  if(isWonBattle){
      player.levelUp();
      player.addCoins(stats.loot);
  }

  else{
      player.damage(stats.hpLossOnDefeat);
  }
}

static void buffEncounter(Player& player, const CardStats& stats) {
//Plays an encounter of the player with a buff card.

  assert(player && stats);
  bool isEnoughMoney = player.pay(stats.cost);
  if(isEnoughMoney){
      player.buff(stats.buff);
  }
}

static void healEncounter(Player& player, const CardStats& stats) {
  //Plays an encounter of the player with a heal card.

    assert(player && stats);
    bool isEnoughMoney = player.pay(stats.cost);

    if(isEnoughMoney){
        player.heal(stats.heal);
    }
}

static void treasureEncounter(Player& player, const CardStats& stats) {
  //Plays an encounter of the player with a treasure card.

    assert(player && stats);
    player.addCoins(stats.cost);
}

void Card::printInfo() const{
//Plays an encounter of the player with a random card.
  
  assert(player);
  switch(this->m_effect){
  
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

  }
}

void Card::applyEncounter(Player& player) const{
//Plays an encounter of the player with a random card.
  
  assert(player);
  switch(this->m_effect){
  
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

