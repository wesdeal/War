#include <vector>
#include <list>
#include <iostream>
#include "player.h"
#include "card.h"
#include "Lab10.cpp"
#include "deck.h"

Player::Player() {

}

Player::Player(vector<Card> ini_cards){

}

int Player::getNumCards(vector<Card> cards_for_Player) const {
   
    // return how many cards player holds currently 
    int numCards = cards_for_Player.size();

    return numCards;
}


Card Player::play_a_card(vector<Card> cards_for_Player) {
    
    //take from top of cards_for_Player
    Card card;
    card = cards_for_Player.front();

    cards_for_Player.erase(cards_for_Player.begin());
 
    return Card(card);
}

void Player::addCards(vector<Card> winningCards, vector<Card> cards_for_Player) {

    //add all elements of winningCards to players hand
    //then remove those elements from winning cards

    for (int i = 0; i < winningCards.size(); i++) {

        cards_for_Player.push_back(winningCards.front());
        winningCards.erase(winningCards.begin());
    }


}

vector<Card> Player::dropCards(vector<Card> cards_for_Player) {
    
    vector<Card> droppedCards;

    for (int i = 0; i < 3; i++) {
        droppedCards.push_back(cards_for_Player.back());
        cards_for_Player.pop_back();
    }
    return vector<Card>(droppedCards);
}

void Player::print(vector<Card> cards_for_Player) const {

    for (int i = 0; i < cards_for_Player.size(); i++) {
        Card point = cards_for_Player[i];
        point.print();

    }
}

/* 

deck -> cards
hand -> deck
player -> hand

cards held in a vector called deck, which is the deck



 */