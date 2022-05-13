#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include "utilities.h"
#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;

Card::Card(CardType type, const CardStats& stats){
//C'tor of Card class.

  this->m_effect = type;
  this ->m_stats = stats;
  
}

void applyEncounter(Player& player) const{
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
      
    case CardType::Tresure:
      tresureEncounter(player, this->m_stats);
      break;

  }
}

static void battleEncounter(Player& player, const CardStats& stats) const{
//Plays an encounter of the player with a battle card.

  assert(player && stats);
  bool isWonBattle = player.force >= stats.force;
  utilities::printBattleResult(isWonBattle);

  if(isWonBattle){
      player.levelup();
      player.addcoins(stats.loot);
  }

  else{
      player.damage(stats.hpLoss);
  }
}

static void buffEncounter(Player& player, const CardStats& stats) const{
//Plays an encounter of the player with a buff card.

  assert(player && stats);
  bool isEnoughMoney = player.pay(stats.cost);
  if(isEnoughMoney){
      player.buff(stats.buff);
  }
}

static void buffEncounter(Player& player, const CardStats& stats) const{
  //Plays an encounter of the player with a heal card.

    assert(player && stats);
    bool isEnoughMoney = player.pay(stats.cost);

    if(isEnoughMoney){
        player.heal(stats.heal);
    }
}

static void tresureEncounter(Player& player, const CardStats& stats) const{
  //Plays an encounter of the player with a tresure card.

    assert(player && stats);
    player.addcoins(stats.coins);
}

void printInfo() const{
//Plays an encounter of the player with a random card.
  
  assert(player);
  switch(this->m_effect){
  
    case CardType::Battle:
      utilities::printBattleCardInfo(stats);
      break;

       
    case CardType::Buff:
      utilities::printBuffCardInfo(stats);
      break;
      
    case CardType::Heal:
      utilities::printHealCardInfo(stats);
      break;
      
    case CardType::Tresure:
      utilities::printTreasureCardInfo(stats);
      break;

  }
}