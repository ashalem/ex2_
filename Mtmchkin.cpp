#include "Card.h"
#include "Mtmchkin.h"
#include <iostream>
#include <assert.h>

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player(playerName),
    m_deck(new Card[numOfCards]),
    m_deckSize(numOfCards),
    m_cardIndex(0),
    m_gameStatus(GameStatus::MidGame) {
    assert(playerName);    
    assert(cardsArray);
    if (cardsArray) {
        for (int i = 0; i < numOfCards; i++) {
            this->m_deck[i] = cardsArray[i];
        }
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_gameStatus;
}

void Mtmchkin::advanceCardIndex() {
    if (this->m_cardIndex == this->m_deckSize) {
        this->m_cardIndex = 0;
    } else {
        this->m_cardIndex++;
    }
}

void Mtmchkin::updateGameStaus() {
    if (Player::maxLevel == this->m_player.getLevel()) {
        this->m_gameStatus = GameStatus::Win;
    } else if (this->m_player.isKnockedOut()) {
        this->m_gameStatus = GameStatus::Loss;
    }
}

void Mtmchkin::playNextCard() {
    const Card& currentCard = this->m_deck[this->m_cardIndex];
    this->advanceCardIndex();
    currentCard.printInfo();
    currentCard.applyEncounter(this->m_player);
    this->m_player.printInfo();

    this->updateGameStaus();
}

bool Mtmchkin::isOver() const {
    return (this->m_gameStatus == GameStatus::Loss || this->m_gameStatus == GameStatus::Win);
}
