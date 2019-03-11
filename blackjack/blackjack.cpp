#include "blackjack.h"
#include "deck.h"
#include "player.h"
#include "dealer.h"
/**********************************
*
*	Purpose:
*
*	Entry:
*
*	Exit:
*
***********************************/
BlackJack::BlackJack(int x)
	:flag_DealerBlackjack(false), flag_DealerBust(false), flag_PlayerBlackjack(false), flag_PlayerBust(false), flag_stand(false)
{
	d1.Shuffle();
	Player1.SetBankroll(x);
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
void BlackJack::Deal()
{
	Card * c1 = d1.Draw();
	Card * c2 = d1.Draw();
	Card * c3 = d1.Draw();
	Card * c4 = d1.Draw();

	Player1.SetHand(c1, c3);
	theDealer.SetHand(c2, c4);

}
BlackJack::~BlackJack()
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
void BlackJack::StartGame()
{
	d1.Shuffle();
	bool keepgoing = Menu1();
	while(keepgoing)
	{
		Player1.ResetSetHand();
		theDealer.ResetSetHand();
		d1.Shuffle();
		//reset player, dealer, and reset and shuffle deck
		keepgoing = Menu1();
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
bool BlackJack::Menu1()
{
	flag_stand = false;
	bool flags = false;
	flag_DealerBlackjack = false;
	flag_DealerBust = false;
	flag_PlayerBlackjack = false;
	flag_PlayerBust = false;

	int menuchoice;
	system("PAUSE");
	system("CLS");
	cout << "1) Bet\n"
		 << "2) Exit\n";
	cin >> menuchoice;
	if (menuchoice == 1)
	{
		cout << "You have $";
		cout << Player1.CheckBank() << endl;
		cout << "How much would you like to bet: ";
		cin >> currentbet;
		while(currentbet > Player1.CheckBank())
		{
			cout << "You dont have that much money!\n"
				 << "How much would you like to bet: ";
			cin >> currentbet;
		}
		Deal();
		DisplayHands(1);

		if (Player1.GetHandValue() == 21)
			flag_PlayerBlackjack = true;
		if (theDealer.GetHandValue() == 21)
			flag_DealerBlackjack = true;
		while(!flag_DealerBlackjack && !flag_PlayerBlackjack && !flag_DealerBust && !flag_PlayerBust && !flag_stand)
		{
			flag_stand = Menu2();
			DisplayHands(1);
		}

		flags = FlagCheck();
		if (flags)
			return true;
		if (flag_stand)
		{
			DealersTurn();
			if (theDealer.GetHandValue() > 21)
				flag_DealerBust = true;
			flags = FlagCheck();
			if (flags)
				return true;
			DisplayHands(2);
		}

		if(Player1.GetHandValue() > theDealer.GetHandValue())
		{
			cout << "\n You win, you had a better hand!\n";
			Player1.Winnings(currentbet);
		}
		else if (Player1.GetHandValue() < theDealer.GetHandValue())
		{
			cout << "\n You lose, dealer had a better hand!\n";
			Player1.Spend(currentbet);
		}
		else
		{
			cout << "\n It's a tie!\n";
		}
	}
	else
		return false;
	return true;
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
void BlackJack::DealersTurn()
{
	while(theDealer.GetHandValue() < 17)
	{
		//hit
		theDealer.Hit(d1.Draw());
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
bool BlackJack::FlagCheck()
{
	if(flag_PlayerBlackjack && flag_DealerBlackjack)
	{
		DisplayHands(2);
		cout << "\n Its a tie, both got blackjack!!\n";
		return true;
	}
	else if (flag_DealerBlackjack)
	{
		DisplayHands(2);
		cout << "\n You lose, dealer had blackjack!\n";
		Player1.Spend(currentbet);
		return true;
	}
	else if (flag_PlayerBlackjack)
	{
		DisplayHands(2);
		cout << "\n You win, you got a blackjack!\n";
		Player1.Winnings(currentbet);
		return true;
	}
	else if(flag_PlayerBust)
	{
		DisplayHands(2);
		cout << "\n You lose, you busted!\n";
		Player1.Spend(currentbet);
		return true;
	}
	else if(flag_DealerBust)
	{
		DisplayHands(2);
		cout << "\n You win, dealer busted!\n";
		Player1.Winnings(currentbet);
		return true;
	}
	return false;
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
bool BlackJack::Menu2()
{
	int menuchoice;
	cout << "1) Hit\n"
		 << "2) Stand\n";
	cin >> menuchoice;

	if(menuchoice == 1)
	{
		Player1.Hit(d1.Draw());
		if(Player1.GetHandValue() > 21)
			flag_PlayerBust = true;
		return false;
	}
	else
	{
		return true;
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
void BlackJack::DisplayHands(int x)
{
	system("CLS");
	cout << "Your cards are: \n";
	Player1.DisplayMyHand(2);
	cout << endl;
	cout << "Yotal value: ";
	cout << Player1.GetHandValue();
	cout << endl;
	cout << "The Dealers cards are: \n";
	theDealer.DisplayMyHand(x);
	cout << endl << endl;
}

