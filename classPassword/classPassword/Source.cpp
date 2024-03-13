#include<iostream>
#include<istream>
#include<ostream>
#include<string>
using namespace std;

// Реализовать класс Пароль.Данные - пароль.Методы: определение степени безопасности пароля(слабый, средний, высокий), перегрузка операций сравнения == , != .

class Password
{
public:

	Password() : pass(0) {};
	Password() : pass(pass) {};
		
	void defensPass()
	{
		for (int i = 0; i < size(pass); i++)
		{
			if (isdigit(pass[i]))
			{
				num++;
			}
			if (isupper(pass[i]) || islower(pass[i]))
			{
				lat++;
			}
			if (ispunct(pass[i]))
			{
				chart++;
			}
		}
		if(num > 0 && lat == 0 && chart == 0)
		{
			cout << "Пароль слабый" << endl;
		}
		else if (num > 6 && (lat >=1 || chart >=1))
		{
			cout << "Пароль средний" << endl;
		}
		else if (num > 8 && lat >=3 && chart >= 1)
		{
			cout << "Пароль высокий" << endl;
		}
	}
	bool operator ==(const Password& p);
	bool operator !=(const Password& p);

private:
	int num = 0;
	int lat = 0;
	int chart = 0;
	string pass;
};

bool Password::operator==(const Password& p)
{
	if (pass == p.pass)
	{
		cout << "Равен" << endl;
		return true;
	}
	return false;
}

bool Password::operator!=(const Password& p)
{
	if (pass != p.pass)
	{
		cout << "Не равен" << endl;
		return true;
	}
	return false;
}
