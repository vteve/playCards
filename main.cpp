#include <iostream>
#include "playCards/playCards.h"
//#include "playDeckStatic/deck.h"
#include "playDeckDynamic/deck.h"


int main() {
    system("chcp 65001");
    srand(time(0));
    playCards::Card card1(11, playCards::Card::suits::hears);
    playCards::Card card2(14, playCards::Card::suits::hears);
    playCards::Card card3;
//    card1.print(std::cout);
//    card2.print(std::cout);
//    card3.print(std::cout);
    std::cout << card1;
    std::cout << card2;
    std::cout << card3;
//    card1.operator<<(std::cout);
    std::cout << (card1 == card2) << std::endl;
    std::cout << (card1 > card2) << std::endl;
    std::cout << (card1 < card2) << std::endl;
    std::cout << (card1 >= card2) << std::endl;
    std::cout << (card1 <= card2) << std::endl;
    std::cout << (card1 != card2) << std::endl;
    playDeckDynamic::Deck deck1000(20);
    deck1000.setCountCards(15);
    std::cout << deck1000.getCountCards() << std::endl;
//    card1.setSuit(playCards::Card::suits::hears);
//    int rankCard2 = card2.getRank();
//    card2.setRank(2);
//    playCards::Card::suits suitCard3 = card3.getSuit();
//    playCards::Card card;
//    std::cin >> card;
//    std::cout << card;
//    playCards::Card card4 = !card;
//    std::cout << card4;
//    playDeckStatic::Deck deck1(20);
//    playCards::Card *cards1 = deck1.getDeck();
//    for (int i = 0; i < deck1.getCountCards(); ++i) {
//        std::cout << i << " " << cards1[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    playDeckStatic::Deck deck2(25);
//    playCards::Card *cards2 = deck2.getDeck();
//    for (int i = 0; i < deck2.getCountCards(); ++i) {
//        std::cout << i << " " << cards2[i];
//    }
//    deck1>>deck2;
//    std::cout << "==================--------===================" << std::endl;
//    playCards::Card *cards3 = deck1.getDeck();
//    for (int i = 0; i < deck1.getCountCards(); ++i) {
//        std::cout << i << " " << cards3[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    playCards::Card *cards4 = deck2.getDeck();
//    deck2.addRandomCard();
//    deck2.deleteCard(1);
//    for (int i = 0; i < deck2.getCountCards(); ++i) {
//        std::cout << i << " " << cards4[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    deck2.arrangingDeck();
//    playCards::Card *cards5 = deck2.getDeck();
//    for (int i = 0; i < deck2.getCountCards(); ++i) {
//        std::cout << i << " " << cards5[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    deck2.mixingDeck();
//    playCards::Card *cards6 = deck2.getDeck();
//    for (int i = 0; i < deck2.getCountCards(); ++i) {
//        std::cout << i << " " << cards6[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    playDeckStatic::Deck newDeck = deck2.newDeckBySuit(playCards::Card::suits::clubs);
//    playCards::Card *cards7 = newDeck.getDeck();
//    for (int i = 0; i < newDeck.getCountCards(); ++i) {
//        std::cout << i << " " << cards7[i];
//    }
//    std::cout << "=====================================" << std::endl;
//    playDeckStatic::Deck newDeck2 = deck1 + deck2;
//    playCards::Card *cards8 = newDeck2.getDeck();
//    for (int i = 0; i < newDeck2.getCountCards(); ++i) {
//        std::cout << i << " " << cards8[i];
//    }
//    std::cout << newDeck2[3] << std::endl;
//    std::cout << "=====================================" << std::endl;
//    std::cout << newDeck2;
//    playDeckStatic::Deck newDeck3(10);
//    std::cin >> newDeck3;
//    std::cout << newDeck3;
//    std::cout << newDeck3[4] << std::endl;
//    playDeckStatic::Deck deck101;
//    std::cout << deck101;
//    playDeckStatic::Deck deck102(25);
//    std::cout << deck102;
//    deck101 = deck102;
//    std::cout << deck101;
//    playDeckStatic::Deck deck103;
//    ++deck103;
//    deck103++;
//    std::cout << deck103;
//    playDeckStatic::Deck deck104(20);
//    std::cout << deck104;
//    deck103 += deck104;
//    std::cout << deck103;
//    playCards::Card card100;
//    std::cout << card100;
//    playCards::Card card101 = !card100;
//    std::cout << card100;
//    std::cout << card101;
//    playDeckDynamic::Deck deck;
//    std::cout << deck;
//    deck.addRandomCard();
//    std::cout << deck;
//    deck.deleteCard(20);
//    std::cout << deck;
//    playDeckDynamic::Deck deck200(52);
//    std::cout << deck200;
//    deck200.arrangingDeck();
//    std::cout << deck200;
//    playDeckDynamic::Deck deck201;
//    playDeckDynamic::Deck deck202 = deck201.newDeckBySuit(playCards::Card::suits::hears);
//    std::cout << deck202;
//    deck202.mixingDeck();
//    std::cout << deck202;
//    playDeckDynamic::Deck deck203;
//    std::cin >> deck203;
//    std::cout << deck203;
//    playDeckDynamic::Deck deck204(20);
//    playDeckDynamic::Deck deck205;
//    std::cout << deck204;
//    std::cout << deck205;
//    deck204 >> deck205;
//    std::cout << deck204;
//    std::cout << deck205;
//    playDeckDynamic::Deck deck206(20);
//    playDeckDynamic::Deck deck207(15);
//    playDeckDynamic::Deck deck208 = deck206 + deck207;
//    std::cout << deck206;
//    std::cout << deck207;
//    std::cout << deck208;
//    playDeckDynamic::Deck deck209(25);
//    playDeckDynamic::Deck deck210 = deck209;
//    std::cout << deck209;
//    std::cout << deck210;
//    playDeckDynamic::Deck deck211(30);
//    std::cout << deck211;
//    deck211++;
//    ++deck211;
//    std::cout << deck211;
//    playDeckDynamic::Deck deck212(15);
//    std::cout << deck212;
//    playDeckDynamic::Deck deck213(10);
//    deck212 += deck213;
//    std::cout << deck213;
//    std::cout << deck212;
//    playDeckDynamic::Deck deck214(51);
//    std::cout << deck214;
//    playDeckDynamic::Deck deck215(20);
//    playDeckDynamic::Deck deck216{deck215};
//    std::cout << deck215;
//    std::cout << deck216;
//    playDeckDynamic::Deck deck217(15);
//    playDeckDynamic::Deck deck218 = std::move(deck217);
//    std::cout << deck217;
//    std::cout << deck218;
//    playDeckDynamic::Deck deck219(25);
//    playDeckDynamic::Deck deck220;
//    deck220 = std::move(deck219);
//    std::cout << deck219;
//    std::cout << deck220;
}
