#ifndef BANKROLL_H
#define BANKROLL_H

class Bankroll
{
public:
	Bankroll();
	Bankroll(int);
	Bankroll(const Bankroll &);
	~Bankroll();
	int Get();
	void Set(int);
	void Add(int);
	void Sub(int);
private:
	int m_cash;
};

#endif