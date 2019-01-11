#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"
#include "bankroll.h"

class Player
{
public:
	Player();
	~Player();
	Player(const Player &);
	void SetBankroll(int);
	void SetHand(Card *, Card *);
	void DisplayMyHand(int);
	int CheckBank();
	void ResetSetHand();
	void Winnings(int);
	void Hit(Card*);
	int GetHandValue();
	void Spend(int);
	void operator=(const Player &rhs);
private:
	Bankroll myBank;
	Hand myHand;
};

#endif