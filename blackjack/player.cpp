#include "player.h"
Player::Player()
{
	
}
Player::~Player()
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
void Player::operator=(const Player &rhs)
{
	this->myBank = rhs.myBank;
	this->myHand = rhs.myHand;
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
Player::Player(const Player & copy)
{
	this->myBank = copy.myBank;
	this->myHand = copy.myHand;
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
void Player::SetBankroll(int x)
{
	myBank.Set(x);
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
void Player::SetHand(Card * c1, Card * c2)
{
	Hand h1(c1, c2);
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
void Player::DisplayMyHand(int x)
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
int Player::CheckBank()
{
	return myBank.Get();
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
void Player::Hit(Card* cardin)
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
int Player::GetHandValue()
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
void Player::Spend(int x)
{
	myBank.Sub(x);
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
void Player::Winnings(int x)
{
	myBank.Add(x);
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
void Player::ResetSetHand()
{
	myHand.ResetHand();
}




