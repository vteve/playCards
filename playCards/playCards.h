#include <iostream>

#ifndef PLAYCARDS_H
#define PLAYCARDS_H

namespace playCards {
    class Card {
    public:
        enum class suits {
            diamonds, hears, clubs, spades
        };
    private:
        int rank;
        suits suit;
        static const int MINRANK = 2, MAXRANK = 14;
        static const std::string arrRank[];
        static const std::string arrSuit[];
    public:

        Card(int rank, suits suit1);

        explicit Card();

        /*!
         *
         * @returns rank of this card
         */
        [[nodiscard]] int getRank() const { return rank; }

        /*!
         *
         * @returns suit of this card
         */
        [[nodiscard]] suits getSuit() const { return suit; }

        /*!
         *
         * @param rank set rank to field of object
         * @returns link to object to do chain calls
         * @throws std::invalid_argument if rank is wrong
         */
        Card &setRank(int rank);
        /*!
         *
         * @param nSuit set suit to field of object
         * @returns link to object to do chain calls
         */
        Card &setSuit(suits nSuit);

        /*!
         *
         * @returns card as a beautiful string
         */
        [[nodiscard]] std::string formatString() const;

//        std::ostream &print(std::ostream &outStream) const;

        /*!
         *
         * @param outStream output values are written here
         * @param card object which we want to output
         * @returns outStream - output stream
         */
        friend std::ostream &operator<<(std::ostream &outStream, const Card &card);
        /*!
         *
         * @param inStream input values are written here
         * @param card object which we want to input
         * @returns inStream - input stream
         * @throws std::invalid_argument if suit is wrong
         */
        friend std::istream &operator>>(std::istream &inStream, Card &card);

//        std::ostream &operator<<(std::ostream &os) const;

        /*!
         *
         * @param secondCard second argument for comparison operation
         * @returns result of comparison operation (0 - false, 1 - true)
         * @throws std::invalid_argument if suits are different
         */
        std::strong_ordering operator<=>(const Card &secondCard) const;

        /*!
         *
         * @param rhs second argument for comparison operation ==
         * @returns result of comparison operation (0 - false, 1 - true)
         */
        bool operator==(const Card &rhs) const;

        /*!
         *
         * @returns diametrically opposite card
         * for suit 1 is 4, for suit 2 is 3, for rank is (16 - rank)
         */
        Card operator!() const;

    };
}

#endif
