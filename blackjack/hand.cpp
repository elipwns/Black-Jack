#include "hand.h"
#include "card.h"
Hand::Hand()
	:cardCount(0)
{
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
Hand::Hand(Card * Card1, Card * Card2)
	:cardCount(2)
{
	cards[0] = Card1;
	cards[1] = Card2;
}
Hand::~Hand()
{
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
Hand::Hand(const Hand & copy)
{
	for (int i = 0; i < cardCount; i++)
	{
		cards[i] = copy.cards[i];
	}
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
void Hand::DisplayHand(int x)
{
	if (x == 1)
	{
		cout << "x x\n";
	}

	for ( int i = 0; i < cardCount; i++)
	{
		if (x == 2)
		{
			cards[i]->Display();
			cout << endl;
		}
		else if (x == 1 && i != 1)
		{
			cards[i]->Display();
		}
	}
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
void Hand::AddCard(Card * card)
{
	cards[cardCount] = card;
	cardCount++;
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
int Hand::DisplayValue()
{
	int total = 0;
	int aces = 0;
	for ( int i = 0; i < cardCount; i++)
	{
		total += cards[i]->Getvalue();
		if(cards[i]->Getvalue() == 1)
		{
			aces++;
		}
	}
	if (aces)
		total = total > 11? total : total + 10;

	

	return total;
}
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
void Hand::ResetHand()
{
	cardCount = 0;
	*cards = nullptr;
}

