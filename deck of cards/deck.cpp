#include "deck.h"
/**************************************************************
*	  Purpose: instantiates the deck of cards
*                 
*         Entry:  its a ctor
*
*          Exit:  creates deck and exits
****************************************************************/

Deck::Deck()
	:beenDealt (0)
	{
		for ( int rank = 0; rank < NUM_RANKS; rank++)
			for ( int suit = 0; suit < NUM_SUITS; suit++)
			{
				deck [(rank * NUM_SUITS) + suit] = new Card(suit , rank);
			}
	}
/**************************************************************
*	  Purpose: dtor for deck, frees up memory
*                 
****************************************************************/

Deck::~Deck()
	{
		for (int i = 0; i < STANDARD_DECK; i++)
		{
			delete deck[i];
		}
	}
/**************************************************************
*	  Purpose: to draw a card
*                 
*         Entry: called when someone draws a card
*
*          Exit:  returns a pointer to a card and increases beenDealt
****************************************************************/

Card * Deck::Draw ()
	{
		return deck[beenDealt++];
	}
/**************************************************************
*	  Purpose:  shuffles the deck
*                 
*         Entry:  called when someones shuffles deck
*
*          Exit:  picks random cards out, replaces them with end card,
				  puts random card into temp array, then when deck is empty,
				  copy the cards back over.
****************************************************************/

void Deck::Shuffle()
	{
		srand ( time(NULL) );
		Card * tempdeck [52];
		for (int i = 0; i < 52; i++)
		{
			int RandomNum = rand() % (STANDARD_DECK - i);
			Card * tempcard = deck[RandomNum];
			deck[RandomNum] = deck[STANDARD_DECK - 1 - i];
			tempdeck[i] = tempcard;
		}

		for (int i = 0; i < 52; i++)
		{
			deck[i] = tempdeck[i];
		}

	}