#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../playCards/playCards.cpp"

TEST_CASE("CardConstructor") {
    SECTION("DefaultConstructor") {
        playCards::Card card;
        REQUIRE(2 <= card.getRank());
        REQUIRE(playCards::Card::suits::diamonds <= card.getSuit());
        REQUIRE(14 >= card.getRank());
        REQUIRE(playCards::Card::suits::spades >= card.getSuit());
    }SECTION("InitConstructor") {
        playCards::Card card(14, playCards::Card::suits::hears);
        REQUIRE(card.getRank() == 14);
        REQUIRE(card.getSuit() == playCards::Card::suits::hears);
    }SECTION("TestExceptions") {
        playCards::Card card;
        REQUIRE_THROWS(card.setRank(15));
        REQUIRE_THROWS(card.setRank(-5));
    }
}


TEST_CASE("CardMethodsAndOperators", "Setters") {
    SECTION("Setters") {
        playCards::Card card;
        card.setRank(9);
        REQUIRE(card.getRank() == 9);
        card.setRank(10);
        REQUIRE(card.getRank() == 10);
        REQUIRE_THROWS(card.setRank(15));
    }SECTION("FORMAT_STRING") {
        playCards::Card card;
        card.setSuit(playCards::Card::suits::hears);
        card.setRank(10);
        REQUIRE(card.getRank() == 10);
        REQUIRE(card.getSuit() == playCards::Card::suits::hears);
        REQUIRE(card.formatString() == "10♥");
        card.setSuit(playCards::Card::suits::diamonds);
        card.setRank(11);
        REQUIRE(card.formatString() == "J♦");
        card.setSuit(playCards::Card::suits::clubs);
        card.setRank(12);
        REQUIRE(card.formatString() == "Q♣");
        card.setSuit(playCards::Card::suits::spades);
        card.setRank(13);
        REQUIRE(card.formatString() == "K♠");
        card.setSuit(playCards::Card::suits::spades);
        card.setRank(14);
        REQUIRE(card.formatString() == "A♠");
    } SECTION("SPACESHIP") {
        playCards::Card card;
        card.setSuit(playCards::Card::suits::hears);
        card.setRank(10);
        playCards::Card card1(4, playCards::Card::suits::hears);
        REQUIRE(card1.getRank() == 4);
        REQUIRE(card1.getSuit() == playCards::Card::suits::hears);
        playCards::Card card2(10, playCards::Card::suits::clubs);
        REQUIRE(card <=> card1 == std::strong_ordering::greater);
        REQUIRE(card1 <=> card == std::strong_ordering::less);
        REQUIRE((card1 == card2) == false);
        REQUIRE_THROWS(card2 <=> card);
    } SECTION("OPERATORS") {
        playCards::Card card1;
        std::cin >> card1;
        playCards::Card card2;
        card2 = !card1;
        REQUIRE(card1 == !card2);
        std::cout << card1;
    }
}