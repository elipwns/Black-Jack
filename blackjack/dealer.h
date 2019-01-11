#ifndef DEALER_H
#define DEALER_H
#include "hand.h"

class Dealer
{
public:
	Dealer();
	~Dealer();
	Dealer(const Dealer &);
	void SetHand(Card *, Card *);
	void DisplayMyHand(int);
	int GetHandValue();
	void Hit(Card*);
	void ResetSetHand();

private:
	Hand myHand;
};

#endif
