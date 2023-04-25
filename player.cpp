#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player()
{
    numCards = 0;
}

Player::Player(vector<Card> ini_cards)
{
    numCards = ini_cards.size(); //vector size is same as starting card amount
}

int Player::getNumCards() const
{
    return numCards;
}

Card Player::play_a_card()
{
    Card playCard = cards.front();
    cards.pop_front();
    numCards -= 1;
    return playCard; //return playCard
}

void Player::addCards(vector<Card> winningCards)
{
    for (int i = 0; i < winningCards.size(); i++)
    {
        cards.push_back(winningCards[i]);
        numCards += 1;
        //remove winningCard that was added to cards
        winningCards.erase(winningCards.begin() + i);
    }
}

vector<Card> Player::dropCards()
{
    //if player has 3 or more cards, drop 3 cards
    //if not drops what they have and loses game
    vector<Card> dropCards;

    if (numCards >= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            dropCards.push_back(cards.front());
            cards.pop_front();
            numCards -= 1;
        }
        return dropCards;
    }
    else
    {
        for (int i = 0; i < numCards; i++)
        {
            dropCards.push_back(cards.front());
            cards.pop_front();
            numCards -= 1;
        } 
        return dropCards;
    }



    return vector<Card>();
}

void Player::print() const
{
    for (int i = 0; i < numCards; i++)
    {
        
    }
}
