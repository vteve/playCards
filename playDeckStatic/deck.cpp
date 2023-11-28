#include <iostream>
#include "../playCards/playCards.h"
#include "deck.h"
#include <cstdlib>

namespace playDeckStatic {

    Deck::Deck(int count) {
        if (count <= 0 || count > MAXDECKSIZE) throw std::invalid_argument("Wrong count");
        createRandomDeck(count);
        countCards = count;
    }

    void Deck::createRandomDeck(int count) {
        int currentSize = 0, i = 0, rank;
        playCards::Card::suits suit;
        int intSuit;
        while (i < count) {
            intSuit = rand() % 4;
            if (intSuit == 0) suit = playCards::Card::suits::diamonds;
            else if (intSuit == 1) suit = playCards::Card::suits::hears;
            else if (intSuit == 2) suit = playCards::Card::suits::clubs;
            else suit = playCards::Card::suits::spades;
            if (!checkAvailabilityCard(rank = rand() % 13 + 2, suit, currentSize)) {
                deck[i].setSuit(suit);
                deck[i].setRank(rank);
                i++;
                currentSize++;
            }
        }
    }

    bool Deck::checkAvailabilityCard(int rank, playCards::Card::suits suit, int currentSize) {
        for (int i = 0; i < currentSize; ++i) {
            if (deck[i].getSuit() == suit && deck[i].getRank() == rank) {
                return true;
            }
        }
        return false;
    }

    Deck::Deck() {
        int index = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                deck[index].setRank(j + 2);
                if (i == 0) deck[index].setSuit(playCards::Card::suits::diamonds);
                else if (i == 1) deck[index].setSuit(playCards::Card::suits::hears);
                else if (i == 2) deck[index].setSuit(playCards::Card::suits::clubs);
                else deck[index].setSuit(playCards::Card::suits::spades);
                index++;
            }
        }
        countCards = 52;
    }

    void Deck::setCountCards(int count) {
        if (count <= 0 || count > MAXDECKSIZE)  throw std::invalid_argument("Wrong count");
        countCards = count;
    }

    int Deck::getCountCards() const {
        return countCards;
    }

    void Deck::operator>>(Deck &secondDeck) {
        if (secondDeck.countCards >= MAXDECKSIZE) throw std::invalid_argument("Second deck is crowded!");
        if (countCards == 0) throw std::invalid_argument("First deck is empty!");
        secondDeck.deck[secondDeck.countCards++] = deck[--countCards];
    }

    void Deck::addRandomCard() {
        if (countCards >= MAXDECKSIZE) throw std::runtime_error("Deck is crowded!");
        playCards::Card card;
        deck[countCards++] = card;
    }

    void Deck::addCard(int rank, playCards::Card::suits suit) {
        if (countCards >= MAXDECKSIZE) throw std::runtime_error("Deck is crowded!");
        playCards::Card card(rank, suit);
        deck[countCards++] = card;
    }

    void Deck::deleteCard(int number) {
        if (number < 0 || number >= countCards) throw std::invalid_argument("Wrong number!");
        if (countCards <= 0) throw std::invalid_argument("Deck is empty!");
        for (int i = number; i < countCards; ++i) {
            deck[i] = deck[i + 1];
        }
        countCards--;
    }

    void Deck::arrangingDeck() {
        qsort(deck, countCards, sizeof(playCards::Card), compare);
    }


    int Deck::compare(const void *a, const void *b) {
        const auto *r1 = static_cast<const playCards::Card *>(a);
        const auto *r2 = static_cast<const playCards::Card *>(b);
        if (r1->getSuit() > r2->getSuit()) {
            return 1;
        } else if (r1->getSuit() < r2->getSuit()) {
            return -1;
        } else if (r1->getSuit() == r2->getSuit() && r1->getRank() > r2->getRank()) {
            return 1;
        } else if (r1->getSuit() == r2->getSuit() && r1->getRank() < r2->getRank()) {
            return -1;
        } else if (r1->getSuit() == r2->getSuit() && r1->getRank() == r2->getRank()) {
            return 0;
        }
        return 0;
    }

    void swap(playCards::Card &card1, playCards::Card &card2) {
        playCards::Card card3 = card2;
        card2 = card1;
        card1 = card3;
    }

    void Deck::mixingDeck() {
        for (int i = 0; i < rand() % 100 + 50; ++i) {
            swap(deck[rand() % countCards], deck[rand() % countCards]);
        }
    }

    Deck Deck::newDeckBySuit(playCards::Card::suits suit) {
        Deck newDeck;
        int countCardsNewDeck = 0;
        newDeck.setCountCards(1);
        for (int i = 0; i < countCards; ++i) {
            if (deck[i].getSuit() == suit) {
                newDeck.addCard(deck[i].getRank(), deck[i].getSuit());
                countCardsNewDeck++;
            }
        }
        newDeck.setCountCards(countCardsNewDeck);
        return newDeck;
    }

    Deck Deck::operator+(const Deck &secondDeck) const {
        if (countCards + secondDeck.countCards > MAXDECKSIZE) throw std::invalid_argument("Too big decks");
        Deck newDeck;
        newDeck.countCards = countCards + secondDeck.countCards;
        for (int i = 0; i < newDeck.countCards; i++) {
            if (i < countCards) {
                newDeck.deck[i].setRank(deck[i].getRank());
                newDeck.deck[i].setSuit(deck[i].getSuit());
            } else {
                newDeck.deck[i].setRank(secondDeck.deck[i - countCards].getRank());
                newDeck.deck[i].setSuit(secondDeck.deck[i - countCards].getSuit());
            }
        }
        return newDeck;
    }

    playCards::Card &Deck::operator[](int index) {
        if (index < 0 || index >= countCards) throw std::invalid_argument("Wrong index!");
        return deck[index];
    }

    const playCards::Card &Deck::operator[](int index) const {
        if (index < 0 || index >= countCards) throw std::invalid_argument("Wrong index!");
        return deck[index];
    }

    std::ostream &operator<<(std::ostream &outStream, const Deck &deck1) {
        for (int i = 0; i < deck1.countCards; ++i) {
            outStream << deck1.deck[i].formatString() << " ";
        }
        outStream << std::endl;
        outStream
                << "========================================================================================================================";
        return outStream;
    }

    std::istream &operator>>(std::istream &inStream, Deck &deck1) {
        std::cout << "Enter count of cards" << std::endl;
        int count;
        std::cin >> count;
        deck1.countCards = count;
        for (int i = 0; i < count; ++i) {
            inStream >> deck1[i];
        }
        return inStream;
    }

    Deck &Deck::operator=(const Deck &secondDeck) {
        if (this != &secondDeck) {
            countCards = secondDeck.countCards;
            for (int i = 0; i < countCards; ++i) {
                deck[i].setRank(secondDeck[i].getRank());
                deck[i].setSuit(secondDeck[i].getSuit());
            }
        }
        return *this;
    }

    Deck &Deck::operator++() {
        if (countCards >= MAXDECKSIZE) throw std::invalid_argument("Deck is crowded");
        this->addRandomCard();
        return *this;
    }

    Deck Deck::operator++(int) {
        if (countCards >= MAXDECKSIZE) throw std::invalid_argument("Deck is crowded");
        Deck newDeck = *this;
        this->addRandomCard();
        return newDeck;
    }

    Deck &Deck::operator+=(const Deck &deck1) {
        if (countCards + deck1.countCards > MAXDECKSIZE) throw std::invalid_argument("Too big decks");
        int count = countCards;
        for (int i = count; i < count + deck1.countCards; ++i) {
            this->addCard(deck1[i - count].getRank(),
                          deck1[i - count].getSuit());
        }
        return *this;
    }

}