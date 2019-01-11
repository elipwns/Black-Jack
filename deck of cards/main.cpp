/***********************************************************
* Author:				eli kloft
* Date Created:			10/??/12
* Last Modification Date:	10/26/12
* Lab Number:			oop c++ lab 5
* Filename:				main.cpp
*
* Overview:
*	this program tests the functionality of the deck and card classes
*
* Input:
*	doesnt require any user input
*
* Output:
*	displays deck of 52 cards and tests equal function
************************************************************/

#include "card.h"
#include "deck.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

bool Equal(const Card & lhs, const Card & rhs);

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Deck d1;
	Card * CurrentCard;
	d1.Shuffle();

	for (int i = 0; i < 52; i++)
	{
		CurrentCard = d1.Draw();
		CurrentCard->Display();
		cout << "\n";
	}

	Card c1(1,1);
	Card c2(1,1);
	cout << Equal(c1, c2);
	return 0;
}

bool Equal(const Card & lhs, const Card & rhs)
	{
		if (lhs.m_rank == rhs.m_rank)
			if(lhs.m_suit == rhs.m_suit)
				return true;
			else return false;
		else return false;
	}