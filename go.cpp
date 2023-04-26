#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main() {

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
    finish the “war” then loses immediately
     */
    
    const int HANDS = 26;    // each player holds 52/2 = 26 cards to begin the game

    Deck Deck;
    Deck.createDeck();

    vector<Card> cards_for_Player1;
    vector<Card> cards_for_Player2;
    vector<Card> pile;

    for (int i = 0; i < HANDS; i++) {
        cards_for_Player1.push_back(Deck.deal_a_card());
        cards_for_Player2.push_back(Deck.deal_a_card());
    }

    Player Player1Deck(cards_for_Player1);
    Player Player2Deck(cards_for_Player2);

    cout << "Player 1's cards: " << endl;
    Player1Deck.print();

    cout << "Player 2's cards: " << endl;
    Player2Deck.print();
    string gameOn = "";

    while ((gameOn != "N") || (gameOn != "n")) {
        Card Player1Card = Player1Deck.play_a_card(); //object
        Card Player2Card = Player2Deck.play_a_card();

        //add both cards to pile
        pile.push_back(Player1Card); //vector
        pile.push_back(Player2Card);

        //WES, you left off here, you added cards to the pile.
        //things to figure out, while loop to continuously print there are blank cards on pile?
        //


        cout << "Player 1 plays: ";
        Player1Card.print();
        cout << endl;
        cout << "Player 2 plays: ";
        Player2Card.print();
        cout << endl;

        cout << "----------------------------------------------" << endl;
        cout << "    There are " << pile.size() << " cards on the pile!           " << endl;
        cout << "----------------------------------------------" << endl;

        cout << "Player has " << Player1Deck.getNumCards() << " cards in hand." << endl;
        cout << "Player has " << Player2Deck.getNumCards() << " cards in hand." << endl;

        //compare cards, add if tie, should be an if ifelse else statement
        if (Player1Card.compareTo(Player2Card) == 1) {
            //Player 1 wins
            cout << "Player 1 wins the round!" << endl;
            //add cards to Player 1's deck
            Player1Deck.addCards(pile);
            pile.clear();
            gameOn = "";
            cout << "Do you want to continue? Y or N" << endl;
            cin >> gameOn;

            

        } else if (Player1Card.compareTo(Player2Card) == -1) {
            //Player 2 wins
            cout << "Player 2 wins the round!" << endl;
            //add cards to Player 2's deck
            Player2Deck.addCards(pile);
            pile.clear();
            gameOn = "";
            cout << "Do you want to continue? Y or N" << endl;
            cin >> gameOn;


        } else {
            //tie
            cout << "It's a tie!" << endl;
            //keep cards in pile
            //both players draw 3 cards
            //then play 1 more card and compare those cards (4th cards)
            //if tie, repeat
            vector<Card> Player1TieCards = Player1Deck.dropCards();
            vector<Card> Player2TieCards = Player2Deck.dropCards();

            //merge both vectors into pile
            pile.insert(pile.end(), Player1TieCards.begin(), Player1TieCards.end());
            pile.insert(pile.end(), Player2TieCards.begin(), Player2TieCards.end());
            //print new pile
            cout << "----------------------------------------------" << endl;
            cout << "    There are " << pile.size() << " cards on the pile!           " << endl;
            cout << "----------------------------------------------" << endl;
            cout << "Both play one more card" << endl;
            

        }

        if (Player1Deck.getNumCards() == 0) {
            cout << "Player 1 has no more cards! Player 2 wins!" << endl;
            break;
        } else if (Player2Deck.getNumCards() == 0) {
            cout << "Player 2 has no more cards! Player 1 wins!" << endl;
            break;
        }

        

        if ((Player1Deck.getNumCards() == 0) && (Player2Deck.getNumCards() == 0)) {
            cout << "Both players have no more cards! It's a tie!" << endl;
            break;
        }
    }

}