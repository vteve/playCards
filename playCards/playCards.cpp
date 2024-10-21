#include <iostream>
#include <stdexcept>
#include "playCards.h"

namespace playCards {

    static const std::string arrRank[] = {"2", "3", "4", "5", "6", "7",
                                          "8", "9", "10", "J", "Q", "K", "A"};
    static const std::string arrSuit[] = {"\u2666", "\u2665", "\u2663", "\u2660"};

    // ♦         // ♥         // ♣         // ♠
    Card::Card(int rank, suits suit) {
        if (rank < MINRANK || rank > MAXRANK) throw std::invalid_argument("Wrong rank");
        this->rank = rank;
        this->suit = suit;
    }


    Card::Card() {
        rank = rand() % 13 + 2;
        suit = Card::suits{rand() % 4};
    }


    Card &Card::setRank(int nRank) {
        if (nRank < MINRANK || nRank > MAXRANK) throw std::invalid_argument("Wrong rank");
        rank = nRank;
        return *this;
    }

    Card &Card::setSuit(suits nSuit) {
        suit = nSuit;
        return *this;
    }

    std::string Card::formatString() const {
        std::string result;
        result += playCards::arrRank[rank - MINRANK];
        result += playCards::arrSuit[(int) suit];
        return result;
    }

//    std::ostream &Card::print(std::ostream &outStream) const {
//        return outStream << formatString() << " " << std::endl;
//    }

    std::strong_ordering Card::operator<=>(const Card &secondCard) const {
        if (suit != secondCard.getSuit()) throw std::invalid_argument("Different suits!");
        return rank <=> secondCard.rank;
    }

    bool Card::operator==(const Card &secondCard) const {
        if (suit == secondCard.suit) {
            return rank == secondCard.rank;
        } else {
            return false;
        }
    }

    std::ostream &operator<<(std::ostream &outStream, const Card &card) {
        return outStream << card.formatString() << std::endl;
    }

    void dialogueFunc1() {
        std::cout << "Enter rank:" << std::endl;
    }

    void dialogueFunc2() {
        std::cout << "Enter suit:" << std::endl;
    }

    std::istream &operator>>(std::istream &inStream, Card &card) {
        int rank, intSuit;
        Card::suits suit;
        dialogueFunc2();
        inStream >> intSuit;
        if (intSuit > 4 || intSuit < 1) throw std::invalid_argument("Wrong suit!");
        suit = Card::suits{intSuit - 1};
        dialogueFunc1();
        inStream >> rank;
        if (rank > Card::MAXRANK || rank < Card::MINRANK) throw std::invalid_argument("Wrong rank!");
        card.setSuit(suit);
        card.setRank(rank);
        return inStream;
    }

    Card Card::operator!() const {
        Card newCard;
        newCard.setSuit(Card::suits{MINRANK + 1 - (int) this->suit});
        newCard.setRank(MAXRANK + 2 - this->getRank());
        return newCard;
    }


//    std::ostream &Card::operator<<(std::ostream &os) const{
//        return os << formatString() << std::endl;
//    }

}
