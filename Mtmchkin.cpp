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

Mtmchkin::Mtmchkin(const Mtmchkin& other) :
    m_player(other.m_player),
    m_deck(new Card[other.m_deckSize]),
    m_deckSize(other.m_deckSize),
    m_cardIndex(other.m_cardIndex),
    m_gameStatus(other.m_gameStatus) {
    for (int i = 0; i < this->m_deckSize; i++) {
        this->m_deck[i] = other.m_deck[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other) {
    Card *newDeck = new Card[other.m_deckSize];
    for (int i = 0; i < other.m_deckSize; i++) {
        newDeck[i] = other.m_deck[i];
    }
    this->m_deckSize = other.m_deckSize;
    delete[] this->m_deck;
    this->m_deck = newDeck;

    this->m_player = other.m_player;
    this->m_cardIndex = other.m_cardIndex;
    this->m_gameStatus = other.m_gameStatus;
    return *this;
}

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_gameStatus;
}

void Mtmchkin::advanceCardIndex() {
    if (this->m_cardIndex == this->m_deckSize - 1) {
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

Mtmchkin::~Mtmchkin() {
    delete[] this->m_deck;
}
