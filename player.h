#include <vector>
#include <list>
#include <iostream>
#include "card.h"

using namespace std;





class Player
{
 public:
 // default constructor
 Player();
 // alternative constructor
 Player(vector<Card> ini_cards);
 // return how many cards player holds currently
 int getNumCards(vector<Card> cards_for_Player) const;
 // player plays one card from the front of cards at hand
 Card play_a_card(vector<Card> cards_for_Player);
 // when the player wins the round, this function will be called
 // player adds winning cards to the end of the cards at hand
 void addCards(vector<Card> winningCards, vector<Card> cards_for_Player);
 // when there is a tie, this function will be called
 // player drops THREE cards from the front of cards at hand
 vector<Card> dropCards(vector<Card> cards_for_Player);

 // display cards at player's hand
 void print(vector<Card> cards_for_Player) const;
 // you are allowed to add other member functions if you want
 private:
 int numCards; // how many cards in player's hand
 list<Card> cards; // sequence of cards in player's hand
};