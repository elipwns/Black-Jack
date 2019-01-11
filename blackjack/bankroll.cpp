#include "bankroll.h"
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
Bankroll::Bankroll(int x)
{
	m_cash = x;
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
Bankroll::Bankroll()
{
	m_cash = 0;
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
Bankroll::Bankroll(const Bankroll & copy)
{
	this->m_cash = copy.m_cash;
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
Bankroll::~Bankroll()
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
int Bankroll::Get()
{
	return m_cash;
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
void Bankroll::Set(int x)
{
	m_cash = x;
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
void Bankroll::Add(int x)
{
	m_cash += x;
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
void Bankroll::Sub(int x)
{
	m_cash -= x;
}