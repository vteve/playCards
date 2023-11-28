#include <iostream>
#include "../playCards/playCards.h"
#include "deck.h"
#include <cstdlib>

namespace playDeckDynamic {

    Deck::Deck(int count) {
        if (count < 0 || count > 52) throw std::invalid_argument("Count must be > 0 and < 52");
        createRandomDeck(count);
        countCards = count;
    }

    void Deck::createRandomDeck(int count) {
        int currentSize = 0, i = 0, rank;
        deck = new playCards::Card[count];
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
        countCards = 52;
        deck = new playCards::Card[countCards];
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
    }

    //копирующий
    Deck::Deck(const Deck &secondDeck) {
        countCards = secondDeck.countCards;
        deck = new playCards::Card[countCards];
        for (int i = 0; i < countCards; ++i) {
            deck[i] = secondDeck[i];
        }
    }

    //перемещающий
    Deck::Deck(Deck &&secondDeck) noexcept {
        countCards = secondDeck.countCards;
        deck = secondDeck.deck;
        secondDeck.deck = nullptr;
        secondDeck.countCards = 0;
    }

    void Deck::setCountCards(int count) {
        countCards = count;
    }

    int Deck::getCountCards() const {
        return countCards;
    }

    void Deck::addRandomCard() {
        if (countCards >= MAXDECKSIZE) {
            resize(countCards, countCards + 1);
        }
        playCards::Card card;
        auto *newDeck = new playCards::Card[countCards + 1];
        for (int i = 0; i < countCards; ++i) {
            newDeck[i] = deck[i];
        }
        delete[] deck;
        newDeck[countCards++] = card;
        deck = newDeck;
    }

    void Deck::addCard(int rank, playCards::Card::suits suit) {
        if (countCards >= MAXDECKSIZE) {
            resize(countCards, countCards + 1);
        }
        playCards::Card card(rank, suit);
        auto *newDeck = new playCards::Card[countCards + 1];
        for (int i = 0; i < countCards; ++i) {
            newDeck[i] = deck[i];
        }
//        std::move(deck, sizeof(playCards::Card)*countCards, newDeck);
        delete[] deck;
        newDeck[countCards++] = card;
        deck = newDeck;
    }

    void Deck::deleteCard(int number) {
        if (number < 0 || number >= countCards) throw std::invalid_argument("Wrong number!");
        if (countCards <= 0) throw std::invalid_argument("Deck is empty!");
        auto *newDeck = new playCards::Card[countCards - 1];
        for (int i = 0; i < countCards; ++i) {
            if (i < number) {
                newDeck[i] = deck[i];
            } else if (i == number) {

            } else {
                newDeck[i - 1] = deck[i];
            }
        }
        delete[] deck;
        deck = newDeck;
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

    Deck Deck::newDeckBySuit(playCards::Card::suits suit) {
        Deck newDeck;
        newDeck.deck = new playCards::Card[countCards];
        int countCardsNewDeck = 0;
        newDeck.setCountCards(countCardsNewDeck);
        for (int i = 0; i < countCards; ++i) {
            if (deck[i].getSuit() == suit) {
                newDeck.addCard(deck[i].getRank(), deck[i].getSuit());
                countCardsNewDeck++;
            }
        }
        auto *newCards = new playCards::Card[countCardsNewDeck];
        for (int i = 0; i < countCardsNewDeck; ++i) {
            newCards[i] = newDeck.deck[i];
        }
        delete[] newDeck.deck;
        newDeck.deck = newCards;
        newDeck.setCountCards(countCardsNewDeck);
        return newDeck;
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

    std::ostream &operator<<(std::ostream &outStream, const Deck &deck1) {
        for (int i = 0; i < deck1.countCards; ++i) {
            outStream << deck1.deck[i].formatString() << " ";
        }
        outStream << std::endl;
        outStream << "============================================================"
                     "============================================================";
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

    void Deck::operator>>(Deck &secondDeck) {
        if (secondDeck.countCards >= MAXDECKSIZE) {
            auto *newDeck = new playCards::Card[2 * secondDeck.countCards];
            for (int i = 0; i < secondDeck.countCards; ++i) {
                newDeck[i] = secondDeck[i];
            }
            delete[] secondDeck.deck;
            secondDeck.deck = newDeck;
        }
        if (countCards == 0) throw std::invalid_argument("First deck is empty!");
        auto *newCards = new playCards::Card[secondDeck.countCards + 1];
        for (int i = 0; i < secondDeck.countCards; ++i) {
            newCards[i] = secondDeck[i];
        }
        delete[] secondDeck.deck;
        newCards[secondDeck.countCards++] = deck[countCards - 1];
        secondDeck.deck = newCards;
        auto *newDeck = new playCards::Card[countCards--];
        for (int i = 0; i < countCards; ++i) {
            newDeck[i] = deck[i];
        }
        delete[] deck;
        deck = newDeck;
    }

    playCards::Card &Deck::operator[](int index) {
        if (index < 0 || index >= countCards) throw std::invalid_argument("Wrong index!");
        return deck[index];
    }

    const playCards::Card &Deck::operator[](int index) const {
        if (index < 0 || index >= countCards) throw std::invalid_argument("Wrong index!");
        return deck[index];
    }

    Deck Deck::operator+(const Deck &secondDeck) const {
        Deck newDeck;
        newDeck.countCards = countCards + secondDeck.countCards;
        newDeck.deck = new playCards::Card[newDeck.countCards];
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

    //копирующий
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

    //перемещающий
    Deck &Deck::operator=(Deck &&secondDeck) noexcept {
        if (this != &secondDeck) {
            countCards = secondDeck.countCards;
            delete[] deck;
            deck = secondDeck.deck;
            secondDeck.deck = nullptr;
            secondDeck.countCards = 0;
        }
        return *this;
    }

    Deck &Deck::operator++() {
        if (countCards >= MAXDECKSIZE) {
            resize(countCards, countCards + 1);
        }
        this->addRandomCard();
        return *this;
    }

    Deck Deck::operator++(int) {
        if (countCards >= MAXDECKSIZE) {
            resize(countCards, countCards + 1);
        }
        Deck newDeck;
        newDeck.countCards = countCards;
        newDeck.deck = new playCards::Card[countCards];
        for (int i = 0; i < countCards; ++i) {
            newDeck.deck[i] = deck[i];
        }
        this->addRandomCard();
        return newDeck;
    }

    Deck Deck::operator+=(const Deck &deck1) {
        int count = countCards;
        auto *newDeck = new playCards::Card[count + deck1.countCards];
        for (int i = 0; i < count; ++i) {
            newDeck[i] = deck[i];
        }
        delete[] deck;
        for (int i = count; i < count + deck1.countCards; ++i) {
            newDeck[i].setRank(deck1[i - count].getRank());
            newDeck[i].setSuit(deck1[i - count].getSuit());
        }
        countCards = count + deck1.countCards;
        deck = newDeck;
        return *this;
    }

    void Deck::resize(int oldLength, int newLength) {
        auto *newDeck = new playCards::Card[newLength];
        for (int i = 0; i < oldLength; ++i) {
            newDeck[i] = deck[i];
        }
        delete[] deck;
        deck = newDeck;
    }


}


