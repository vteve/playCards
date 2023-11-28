#include <iostream>
#include "../playCards/playCards.h"

#ifndef DECK_H
#define DECK_H

namespace playDeckStatic {
    class Deck {
    private:
        int countCards;
        static const int MAXDECKSIZE = 52;
        playCards::Card deck[MAXDECKSIZE];

        static int compare(const void *a, const void *b);

        void createRandomDeck(int count);

    public:

        /*!
         *
         * @param count create deck with this count of cards
         * @throws std::invalid_argument if (count < 0 || count >= MAXDECKSIZE)
         */
        explicit Deck(int count);

        /*!
         * create deck with 52 cards sorted by rank and suit
         */
        Deck();

        /*!
         *
         * @param rank rank of card which we will to look for in deck
         * @param suit suit of card which we will to look for in deck
         * @param currentSize size of deck in moment when this function is calling
         * @returns true if card is found, false if isn't
         */
        bool checkAvailabilityCard(int rank, playCards::Card::suits suit, int currentSize);

        /*!
         *
         * @return deck(array) in type playCards:Card
         */
        playCards::Card *getDeck() {
            return deck;
        }

        /*!
         *
         * @param count setter for field countCards
         */
        void setCountCards(int count);

        /*!
         * getter for countCards
         * @returns field countCards
         */
        [[nodiscard]] int getCountCards() const;

        /*!
         * adding random card in deck
         * @throws std::runtime_error if countCards >= MAXDECKSIZE
         */
        void addRandomCard();

        /*!
         *
         * @param rank add card in the deck with this rank
         * @param suit add card in the deck with this wuit
         * @throws std::runtime_error if countCards >= MAXDECKSIZE
         */
        void addCard(int rank, playCards::Card::suits suit);

        /*!
         *
         * @param number delete card with this number
         * @throws std::invalid_argument if (number < 0 || number >= countCards || countCards <= 0)
         */
        void deleteCard(int number);

        /*!
         * arranging of the deck
         */
        void arrangingDeck();

        /*!
         *
         * @param suit is suit of new deck
         * @returns new deck with only one suit(in parameters)
         */
        Deck newDeckBySuit(playCards::Card::suits suit);

        /*!
         * mixing of the deck
         */
        void mixingDeck();

        /*!
         *
         * @param secondDeck deck where card will go
         * @throws std::invalid_argument if (secondDeck.countCards >= MAXDECKSIZE || countCards == 0))
         */
        void operator>>(Deck &secondDeck);

        /*!
         *
         * @param index index of card of the deck
         * @returns card from deck(from array of type playCards::Card)
         * @throws std::invalid_argument if (index < 0 || index >= countCards)
         */
        playCards::Card &operator[](int index);
        /*!
         *
         * @param index index of card of the deck
         * @returns card from deck(from array of type playCards::Card)
         * @throws std::invalid_argument if (index < 0 || index >= countCards)
         */
        const playCards::Card &operator[](int index) const;

        /*!
         *
         * @param secondDeck is the second argument in sum operation
         * @returns new deck which is sum of our object and secondDeck
         * @throws std::invalid_argument if (countCards + secondDeck.countCards > MAXDECKSIZE)
         */
        Deck operator+(Deck const &secondDeck) const;

        /*!
         *
         * @param outStream output values are written here
         * @param deck1 object which we want to output
         * @returns outStream - output stream
         */
        friend std::ostream &operator<<(std::ostream &outStream, const Deck &deck1);

        /*!
         *
         * @param inStream input values are written here
         * @param deck1 object which we want to input
         * @returns inStream - input stream
         * @throws std::invalid_argument if suit is wrong
         */
        friend std::istream &operator>>(std::istream &inStream, Deck &deck1);

        /*!
         *
         * @param secondDeck deck from where we will copy our object
         * @returns object (*this)
         */
        Deck &operator=(const Deck &secondDeck);

        /*!
         *
         * @returns this deck with new card
         * @throws std::invalid_argument if (countCards >= MAXDECKSIZE)
         */
        Deck &operator++();

        /*!
         *
         * @returns copy of this deck without new card
         * @throws std::invalid_argument if (countCards >= MAXDECKSIZE)
         */
        Deck operator++(int);

        /*!
         *
         * @param deck1 we will to plus it deck to our object
         * @returns this deck(object)(this) with deck1
         * @throws std::invalid_argument if (countCards + deck1.countCards > MAXDECKSIZE)
         */
        Deck &operator+=(const Deck &deck1);

    };
}


#endif