#include "card.h"
/**************************************************************
*	  Purpose:  getter for rank
****************************************************************/

int Card::GetRank()
{
	return m_rank;
}
/**************************************************************
*	  Purpose: getter for suit
****************************************************************/

int Card::GetSuit()
{
	return m_suit;
}
/**************************************************************
*	  Purpose: getter for value
****************************************************************/

int Card::Getvalue()
{
	return m_value;
}
/**************************************************************
*	  Purpose:  setter for vlaue
****************************************************************/

void Card::SetValue(int value)
{
	m_value = value;
}
/**************************************************************
*	  Purpose:  displays the rank and suit
****************************************************************/

void Card::Display()
{
	int rankoffset = GetRank();
	int suitoffset = GetSuit();
	cout << Rank[rankoffset] << " " << Suit[suitoffset];
}