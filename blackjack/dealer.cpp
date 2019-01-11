#include "dealer.h"
Dealer::Dealer()
{
}
Dealer::~Dealer()
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
Dealer::Dealer(const Dealer & copy)
	:myHand(copy.myHand)
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
void Dealer::SetHand(Card * c1, Card * c2)
{
	Hand h1(c1,c2);
	myHand = h1;
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
void Dealer::DisplayMyHand(int x)
{
	myHand.DisplayHand(x);
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
int Dealer::GetHandValue()
{
	return myHand.DisplayValue();
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
void Dealer::Hit(Card* cardin)
{
	myHand.AddCard(cardin);
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
void Dealer::ResetSetHand()
{
	myHand.ResetHand();
}
