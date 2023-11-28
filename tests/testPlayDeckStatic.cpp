#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../playDeckStatic/deck.cpp"
#include "../playCards/playCards.cpp"


TEST_CASE("DeckStaticConstructor") {
    SECTION("DefaultConstructor") {
        playDeckStatic::Deck deck;
        REQUIRE(deck.getCountCards() == 52);
        playDeckStatic::Deck deck1(1);
        deck1[0].setSuit(playCards::Card::suits::diamonds);
        deck1[0].setRank(2);
        REQUIRE(deck.checkAvailabilityCard(2, playCards::Card::suits::diamonds, 1) == true);
        REQUIRE(deck.checkAvailabilityCard(2, playCards::Card::suits::hears, 1) == false);
    }SECTION("InitConstructor") {
        playDeckStatic::Deck deck(15);
        REQUIRE(deck.getCountCards() == 15);
    }SECTION("TestException") {
        playDeckStatic::Deck deck;
        REQUIRE_THROWS(deck.setCountCards(10000));
    }
}

TEST_CASE("DeckStaticOperators") {
    SECTION("IND >>") {
        playDeckStatic::Deck dc1(10);
        playDeckStatic::Deck dc2(10);
        dc1 >> dc2;
        REQUIRE(dc1.getCountCards() == 9);
        REQUIRE(dc2.getCountCards() == 11);
        playDeckStatic::Deck dc3;
        REQUIRE_THROWS(dc1 >> dc3);
        playDeckStatic::Deck dc0(1);
        dc0.deleteCard(0);
        REQUIRE_THROWS(dc0 >> dc2);
    } SECTION("+") {
        playDeckStatic::Deck dc(10);
        playDeckStatic::Deck dc1(13);
        playDeckStatic::Deck dc2 = dc + dc1;
        REQUIRE(dc2.getCountCards() == 23);
    }SECTION("<< AND >>") {
        playDeckStatic::Deck deck;
        std::cin >> deck;
        std::cout << deck;
    } SECTION("=") {
        playDeckStatic::Deck deck1(20);
        playDeckStatic::Deck deck2;
        deck2 = deck1;
        for (int i = 0; i < 20; ++i) {
            REQUIRE(deck1[i] == deck2[i]);
        }
    }SECTION("++") {
        playDeckStatic::Deck deck(15);
        ++deck;
        deck++;
        REQUIRE(deck.getCountCards() == 17);
    }SECTION("+=") {
        playDeckStatic::Deck deck1(20);
        playDeckStatic::Deck deck2(15);
        deck1 += deck2;
        REQUIRE(deck1.getCountCards() == 35);
        REQUIRE(deck2.getCountCards() == 15);
    }
}


TEST_CASE("DeckStaticMethods", "Setters") {
    SECTION("ADD DELETE CARD") {
        playDeckStatic::Deck deck(25);
        deck.addRandomCard();
        deck.addCard(13, playCards::Card::suits::hears);
        deck.deleteCard(12);
        REQUIRE(deck.getCountCards() == 26);
        REQUIRE_THROWS(deck.deleteCard(4124));
    }SECTION("ARRANGING DECK") {
        playDeckStatic::Deck deck(52);
        deck.arrangingDeck();
        REQUIRE(deck[0].getSuit() == playCards::Card::suits::diamonds);
        REQUIRE(deck[0].getRank() == 2);
        REQUIRE(deck[51].getSuit() == playCards::Card::suits::spades);
        REQUIRE(deck[51].getRank() == 14);
    }SECTION("MIXING") {
        playDeckStatic::Deck deck1(10);
        playDeckStatic::Deck deck2(10);
        for (int i = 0; i < 10; ++i) {
            deck2[2] = deck1[i];
        }
        deck1.mixingDeck();
        REQUIRE((deck1[5] == deck2[5]) == false);
    } SECTION("ONESUIT") {
        playDeckStatic::Deck dc(30);
        playDeckStatic::Deck dc1 = dc.newDeckBySuit(playCards::Card::suits::hears);
    } SECTION("GETTERS AND SETTERS") {
        playDeckStatic::Deck deck(20);
        deck.setCountCards(15);
    }
}