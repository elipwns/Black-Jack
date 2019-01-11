#ifndef HAND_H
#define HAND_H
#include "card.h"
#include "deck.h"
class Hand
{
public:
	Hand();
	Hand(Card *, Card *);
	~Hand();
	Hand(const Hand &);
	void ResetHand();
	void DisplayHand(int);
	void AddCard(Card*);
	int DisplayValue();
private:
	int cardCount;
	Card * cards[11];
};

#endif
