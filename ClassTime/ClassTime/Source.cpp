#include<iostream>
#include<iomanip>
#include<ostream>
#include<istream>

using namespace std;

//Реализовать класс Время.Объекты класса должны хранить значение времени(часы, минуты, секунды).Перегрузить операции сравнения(> , < , != , == ), арифметические операции(в частности + , +=, -, -=) и операции >> , << (для ввода / вывода).
//Также должен быть реализован метод перевода времени из 24 - х часового формата в 12 - часовой.

class Time
{
public:
	Time() 
	{
		this->hours = 12;
		this->min = 00;
		this->sec = 00;
		
	};
	Time(int hours)
	{
		if (hours <= 23)
		{
			this->hours = hours;
			this->min = 00;
			this->sec = 00;
		}
		else
		{
			cout << "Данные введены не корректно" << endl;
			this->hours = 00;
			this->min = 00;
			this->sec = 00;
		}
	};
	Time(int hours,int min)
	{
		if (hours <= 23 && min <= 59)
		{
			this->hours = hours;
			this->min = min;
			this->sec = 00;
		}
		else
		{
			cout << "Данные введены не корректно" << endl;
			this->hours = 00;
			this->min = 00;
			this->sec = 00;
		}
	};
	Time(int hours, int min, int sec)
	{
		if (hours <= 23 && min <= 59 && sec <= 59)
		{
			this->hours = hours;
			this->min = min;
			this->sec = sec;
		}
		else
		{
			cout << "Данные введены не корректно" << endl;
			this->hours = 00;
			this->min = 00;
			this->sec = 00;
		}
	};
	Time(Time& time)
	{
		hours = time.hours;
		min = time.min;
		sec = time.sec;
	}

	void getTime()
	{
		cout << setfill('0') << setw(2) << hours << ":";
		cout << setfill('0') << setw(2) << min << ":" ;
		cout << setfill('0') << setw(2) << sec << ";";

	}
	void setTime()
	{
		for (int i = 0; i < 1;)
		{
			cin >> hours;
			cin >> min;
			cin >> sec;

			if (hours <= 23 && min <= 59 && sec <= 59)
			{
				i++;
			}
			else
			{
				cout << "Данные введены не корректно, попробуйте ещё раз" << endl;
			}
		}
	}
	void setInTime(int hours, int min, int sec)
	{
		for (int i = 0; i < 1;)
		{
			if (hours <= 23 && min <= 59 && sec <= 59)
			{
				this->hours = hours;
				this->min = min;
				this->sec = sec;
				i++;
			}
			else
			{
				cout << "Данные введены не корректно, попробуйте ещё раз" << endl;
				i++;
			}
		}
	}
	void AmPm()
	{
		if (hours > 12)
		{
			hours -= 12;
		}
	}

	bool operator > (const Time& t);
	bool operator < (const Time& t);
	bool operator != (const Time& t);
	bool operator == (const Time& t);
	Time operator + (const Time& t);
	Time operator += (const Time& t);
	Time operator - (const Time& t);
	Time operator -= (const Time& t);

	friend ostream& operator << (ostream& os, const Time& t);
	friend istream& operator >> (istream& in, const Time& t);

private:
	int hours;
	int min;
	int sec;
};

ostream& operator << (ostream& os, const Time& t)
{
	return os << setfill('0') << setw(2) << t.hours << ":" << setfill('0') << setw(2)  << t.min << ":" << setfill('0') << setw(2) << t.sec << ";" << endl;
}
istream& operator >> (istream& in,Time& t)
{
	unsigned int hours;
	unsigned int min;
	unsigned int sec;
	in >> hours >> min >> sec;
	if (in)
	{
		t.setInTime(hours, min, sec);
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Time t(13, 23, 23);
	Time t2(13, 23, 23);
	cout << t;

	t.AmPm();

	cout << t;
	return 0;
}

bool Time::operator > (const Time& t)
{
	if (hours > t.hours)
	{
		return true;
	}
	else if (min > t.min)
	{
		return true;
	}
	else if (sec > t.min)
	{
		return true;
	}
	return false;
}
bool Time::operator < (const Time& t)
{
	if (hours < t.hours)
	{
		return true;
	}
	else if (min < t.min)
	{
		return true;
	}
	else if (sec < t.min)
	{
		return true;
	}

	return false;
}
bool Time::operator != (const Time& t)
{
	if (hours != t.hours && min != t.min && sec != t.sec)
	{
		cout << "Не равно" << endl;
		return true;
	}
	return false;

}
bool Time::operator == (const Time& t)
{
	if (hours == t.hours && min == t.min && sec == t.sec)
	{
		cout << "Равны" << endl;
		return true;
	}
	return false;

}
Time Time::operator+(const Time& t)
{
	hours += t.hours;
	min += t.min;
	sec += t.sec;
	return hours,min,sec;
}
Time Time::operator+=(const Time& t)
{
	hours += t.hours;
	min += t.min;
	sec += t.sec;
	return hours, min, sec;
}
Time Time::operator-(const Time& t)
{
	hours -= t.hours;
	min -= t.min;
	sec -= t.sec;
	return hours, min, sec;
}
Time Time::operator-=(const Time& t)
{
	hours -= t.hours;
	min -= t.min;
	sec -= t.sec;
	return hours, min, sec;
}




