#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "deck.h"
#include "dealer.h"
#include "player.h"

class BlackJack
{
public:
	BlackJack(int);
	~BlackJack();
	void StartGame();

private:
	void Deal();
	bool FlagCheck();
	void DisplayHands(int);
	bool Menu1();
	bool Menu2();
	void DealersTurn();

	bool flag_stand;
	bool flag_PlayerBlackjack;
	bool flag_DealerBlackjack;
	bool flag_PlayerBust;
	bool flag_DealerBust;

	int currentbet;
	Deck d1;
	Dealer theDealer;
	Player Player1;
};

#endif
