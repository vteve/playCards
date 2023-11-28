#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../playDeckDynamic/deck.cpp"
#include "../playCards/playCards.cpp"


TEST_CASE("DeckStaticConstructor") {
    SECTION("DefaultConstructor") {
        playDeckDynamic::Deck deck;
        REQUIRE(deck.getCountCards() == 52);
        playDeckDynamic::Deck deck1(1);
        deck1[0].setSuit(playCards::Card::suits::diamonds);
        deck1[0].setRank(2);
        REQUIRE(deck.checkAvailabilityCard(2, playCards::Card::suits::diamonds, 1) == true);
        REQUIRE(deck.checkAvailabilityCard(2, playCards::Card::suits::hears, 1) == false);
    }SECTION("InitConstructor") {
        playDeckDynamic::Deck deck(15);
        REQUIRE(deck.getCountCards() == 15);
    }SECTION("COPY CONSTRUCTOR") {
        playDeckDynamic::Deck deck1(20);
        playDeckDynamic::Deck deck2{deck1};
        REQUIRE(deck1.getCountCards() == deck2.getCountCards());
        for (int i = 0; i < 20; ++i) {
            REQUIRE(deck1[i] == deck2[i]);
        }
    }SECTION("MOVE CONSTRUCTOR") {
        playDeckDynamic::Deck deck1(20);
        playDeckDynamic::Deck deck2 = std::move(deck1);
        REQUIRE(deck1.getCountCards() == 0);
        REQUIRE(deck1.getDeck() == nullptr);
        REQUIRE(deck2.getCountCards() == 20);
    }
}

TEST_CASE("DeckStaticOperators") {
    SECTION("IND >>") {
        playDeckDynamic::Deck dc1(10);
        playDeckDynamic::Deck dc2(10);
        dc1 >> dc2;
        REQUIRE(dc1.getCountCards() == 9);
        REQUIRE(dc2.getCountCards() == 11);
        playDeckDynamic::Deck dc3;
        dc1 >> dc3;
        playDeckDynamic::Deck dc0(1);
        dc0.deleteCard(0);
        REQUIRE_THROWS(dc0 >> dc2);
    } SECTION("+") {
        playDeckDynamic::Deck dc(10);
        playDeckDynamic::Deck dc1(13);
        playDeckDynamic::Deck dc2 = dc + dc1;
        REQUIRE(dc2.getCountCards() == 23);
    }SECTION("<< AND >>") {
        playDeckDynamic::Deck deck;
        std::cin >> deck;
        std::cout << deck;
    } SECTION("= COPY") {
        playDeckDynamic::Deck deck1(20);
        playDeckDynamic::Deck deck2;
        deck2 = deck1;
        for (int i = 0; i < 20; ++i) {
            REQUIRE(deck1[i] == deck2[i]);
        }
    }SECTION("= MOVE") {
        playDeckDynamic::Deck deck1(15);
        playDeckDynamic::Deck deck2;
        deck2 = std::move(deck1);
        REQUIRE(deck1.getCountCards() == 0);
        REQUIRE(deck1.getDeck() == nullptr);
        REQUIRE(deck2.getCountCards() == 15);
    }SECTION("++") {
        playDeckDynamic::Deck deck(15);
        ++deck;
        deck++;
        REQUIRE(deck.getCountCards() == 17);
    }SECTION("+=") {
        playDeckDynamic::Deck deck1(20);
        playDeckDynamic::Deck deck2(15);
        deck1 += deck2;
        REQUIRE(deck1.getCountCards() == 35);
        REQUIRE(deck2.getCountCards() == 15);
    }
}


TEST_CASE("DeckStaticMethods", "Setters") {
    SECTION("ADD DELETE CARD") {
        playDeckDynamic::Deck deck;
        deck.addRandomCard();
        deck.addCard(12, playCards::Card::suits::hears);
        deck.deleteCard(12);
        REQUIRE(deck.getCountCards() == 53);
        REQUIRE_THROWS(deck.deleteCard(4124));
    }SECTION("ARRANGING DECK") {
        playDeckDynamic::Deck deck(52);
        deck.arrangingDeck();
        REQUIRE(deck[0].getSuit() == playCards::Card::suits::diamonds);
        REQUIRE(deck[0].getRank() == 2);
        REQUIRE(deck[51].getSuit() == playCards::Card::suits::spades);
        REQUIRE(deck[51].getRank() == 14);
    }SECTION("MIXING") {
        playDeckDynamic::Deck deck1(10);
        playDeckDynamic::Deck deck2(10);
        for (int i = 0; i < 10; ++i) {
            deck2[2] = deck1[i];
        }
        deck1.mixingDeck();
    } SECTION("ONESUIT") {
        playDeckDynamic::Deck dc(30);
        playDeckDynamic::Deck dc1 = dc.newDeckBySuit(playCards::Card::suits::hears);
    } SECTION("GETTERS AND SETTERS") {
        playDeckDynamic::Deck deck(20);
        deck.setCountCards(15);
    }
}