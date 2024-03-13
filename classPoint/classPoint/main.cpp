#include<iostream>
#include<ostream>
#include<istream>

using namespace std;

//	–азработать класс “очка(в декартовой системе координат).ƒанные Ц координаты х, у.ѕерегрузить операции == , != , >> , << дл€ ввода / вывода точки.–еализовать метод дл€ проверки, 
//	в какой координатной четверти лежит точка, реализовать метод дл€ проверки лежит ли точка на линии, заданной уравнением, выше или ниже нее.


class Point
{
public:
	Point() : x(0), y(0) {};
	Point(int x, int y) : x(x), y(y) {};

	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void SetX(int x)
	{
		this->x = x;
	}
	void SetY(int y)
	{
		this->y = y;
	}
	
	void pointCoord()
	{
		if (x > 0 && y > 0)
		{
			cout << "1 четверть" << endl;	
		}
		if (x < 0 && y > 0)
		{
			cout << "2 четверть" << endl;
		}
		if (x < 0 && y < 0)
		{
			cout << "3 четверть" << endl;
		}
		if (x > 0 && y < 0)
		{
			cout << "4 четверть" << endl;
		}
	}

	void lineCoord()
	{
		if (((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) == 0)
		{
			cout << "точка лежит на линии" << endl;
		}
		else if (((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) > 0)
		{
			cout << "“очка лежит ниже линии" << endl;
		}
		else if (((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) < 0)
		{
			cout << "“очка лежит выше линии" << endl;
		}
	}



	bool operator == (Point& p);
	bool operator !=(Point& p);

	friend ostream& operator << (ostream& os,const Point& p);
	friend istream& operator >> (istream& in, Point& p);

private:
	int x;
	int y;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
};

int main()
{
	Point p(6, 5);

	cin >> p;
	cout << p;

	return 0;
}

ostream& operator << (ostream& os, const Point& p)
{
	return os << "x = " << p.x << " " << "y = "<<  p.y << endl;
}

istream& operator>>(istream& in, Point& p)
{
	int x;
	int y;
	in >> x >> y;
	p.SetX(x);
	p.SetY(y);

	return in;
}


bool Point::operator==(Point& p)
{
	if (x == p.x && y == p.y)
	{
		return true;
		cout << "–авны";
	}
	return false;
}
bool Point::operator!=(Point& p)
{
	if (x != p.x && y != p.y)
	{
		return true;
	}
	return false;
}
