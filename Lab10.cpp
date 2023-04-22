/*
 * Course: CS215-00x
 * Project: Lab 10 (as first part of Project 3)
 * Purpose: Demonstrate how to use Card class and Deck class
 *          First, it creates 52 cards on deck
 *          Second, it deals 26 cards for each of two players
 *          Then it displays cards in player1's hand and in player2's hand respectively
 *          Test running the program under two different cases:
 *          Case 1: comment out // playDeck.shuffleDeck(); at line number 28
 *          Case 2: activate statement at line number 28
 */

/* 

1. Each player gets dealt half the deck, 26 cards, and the cards are put face down
in the pile in front of the players.

2. Both players turn their top card face up at the same time. The person with the
higher card wins the draw and takes both the cards. They are put to the bottom
of the pile, which the player can continue using cards on his/her pile. Aces are
high, and suits are ignored.

3. If the two cards played are of equal value, then there is a "war". Both players
place the next three cards face down and then another card face-up. The owner
of the higher face-up card wins the “war” and adds all the cards on the table to
the bottom of the winner’s pile. If the face-up cards are again equal, then the
battle repeats with another set of face-down/up cards. This repeats until one
player's face-up card is higher than his/her opponent's or one player does not
have enough cards to finish the war then loses immediately.

4. First player to finish all his/her cards loses the game.

5. If a player finishes his/her cards during a “war” without having enough cards to
finish the “war” then loses immediately */









#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
    // Avoid magic numbers
    const int HANDS = 26;    // each player holds half cards (52 cards / 2 = 26 cards) to begin the game

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // then shuffle the cards
    Deck playDeck;
    playDeck.createDeck();
    //playDeck.shuffleDeck();

    Card yourCards[HANDS]; //arrays with size of 26
    Card myCards[HANDS]; // ''

    for (int i = 0; i < HANDS; i++)
    {
        yourCards[i] = playDeck.deal_a_card();
        myCards[i] = playDeck.deal_a_card();
    }

    cout << endl << "The cards in your hand are: " << endl;
    for (int i = 0; i < HANDS; i++)
    {
        yourCards[i].print();
        cout << "\t";
    }

    cout << endl << endl << "The cards in my hand are: " << endl;
    for (int i = 0; i < HANDS; i++)
    {
        myCards[i].print();
        cout << "\t";
    }

    //Start rest of program with each turn etc.


    // bool valid = True
    /* 
    while valid....
    play_a_card()

    if myCards[i] == yourCards[i] {
        cout << "It is a tie...for this round!" << endl;
        cout << "Each player drops three cards (face down) on the pile, then" << endl;
        cout << "play one more card (face up)" << endl;

        dropCards();
    } else {

        if compareTo(Card other) < 0


    }

    
    
    
    
     */



    return 0;
}
