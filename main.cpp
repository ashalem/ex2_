#include "Card.h"
#include "Mtmchkin.h"
#include <iostream>

int main() {
    const int deckSize = 7;
    Card cards[deckSize];
    CardStats stats1(3, 40, 10, 30, 1, 20);
    cards[0] = Card(CardType::Treasure,stats1);
    cards[1] = Card(CardType::Buff,stats1);
    cards[2] = Card(CardType::Battle,stats1);
    cards[3] = Card(CardType::Heal,stats1);
    CardStats stats2(4, 20, 20, 40, 2, 40);
    cards[4] = Card(CardType::Battle,stats2);
    cards[5] = Card(CardType::Buff,stats2);
    CardStats stats3(7, 70, 70, 70, 7, 70);
    cards[6] = Card(CardType::Battle,stats3);
    Mtmchkin game("Ariel Strugo", cards, deckSize);

    if (game.getGameStatus() == GameStatus::Win){
        std::cout << "The player defeated all monsters and achieved eternal glory!";
    }


    return 0;
}