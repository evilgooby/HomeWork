#include<iostream>
#include<ostream>
#include <cmath>

using namespace std;

//	Реализовать класс Вклад.Данные - процентная ставка, срок, возможность пополнения / снятия денег.Методы – пополнение / снятие денег(операции + , -), расчет дохода.Вывод реквизитов на экран(перегрузка операции << )

class Deposit
{
public:
	Deposit() : money(0), month(0), interesеRate(0) {};
	Deposit(float money) : money(money) {};
	Deposit(float money, int month) : money(money), month(month) {};
	Deposit operator +(const float& d);
	Deposit operator -(const float& d);
	void skolko_zarabotayu();
	friend ostream& operator << (ostream& os, const Deposit& d);
private:
	float interesеRate = 10;		// процентная ставка в год
	int month = 0;
	float money = 0;
};

int main()
{
	setlocale(LC_ALL, "rus");
	Deposit d(5000, 12);
	d + 6000;
	d - 1000;
	d.skolko_zarabotayu();
	cout << d;
	return 0;
}

ostream& operator << (ostream& os, const Deposit& d)
{
	return os << d.money << endl;
}
Deposit Deposit::operator+(const float& d)
{
	this->money += d;
	return *this;
}
Deposit Deposit::operator-(const float& d)
{
	money -= d;
	return *this;
}
void Deposit::skolko_zarabotayu()
{
	float k;
	k = money * pow((1 + ((interesеRate / 100) / 12)), month);
	cout << k << endl;
}
