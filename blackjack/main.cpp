/*********************************************************************
*	Eli Kloft
*
*
*
*
*
*
*
*
**********************************************************************/


#include "bankroll.h"
#include "blackjack.h"
#include "dealer.h"
#include "hand.h"
#include "player.h"
#include "card.h"
#include "deck.h"

int main()
{
	const int STARTCASH = 500; 		// Starting amount in the Players Bankroll
 	BlackJack game(STARTCASH);
 	game.StartGame();
	return 0;

}