#ifndef CARD_H
#define CARD_H
//#include "deck.h"
#include "iostream"
using std::cout;

const int NUM_RANKS = 13;
const int NUM_SUITS = 4;
//static const char* Suit[NUM_SUITS] = {"Club", "Diamond", "Heart", "Spade"};
const char Suit[ 4 ] = { 0x05, 0x04, 0x03, 0x06 };
static const char * Rank[NUM_RANKS] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
/************************************************************************
* Class: card
*
* Constructors:	
*	card(int , int)
*		rank and suit initialized to value passed in
	private copy ctor
		to prevent cheating
*
* Mutators:
*	void setvalue(int)
		set a value to a card for a points game
*
* Methods:		
*	int GetRank();  returns ranks
	int GetSuit();  returns suit
	int Getvalue();  returns value
	void Card::Display(); displays suit and rank
*************************************************************************/

class Card
{
	friend bool Equal(const Card & lhs, const Card & rhs);

public:
	int GetRank();
	int GetSuit();
	int Getvalue();
	void SetValue(int value);
	~Card()
	{
	}
	Card(int suit, int rank, int value = 0)
		:m_suit(suit), m_rank(rank), m_value(value)
	{
	}

	void Display();
private:
	Card(const Card & in)
		:m_rank(in.m_rank), m_suit(in.m_suit)
	{
	}
	const int m_suit;
	const int m_rank;
	int m_value;
};


#endif