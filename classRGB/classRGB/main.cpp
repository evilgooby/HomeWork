#include<iostream>
#include<ostream>
#include<istream>
using namespace std;

class RGB
{
public:
	RGB() : R(0), G(0), B(0) {};
	RGB(int R, int G, int B) : R(R), G(G), B(B) {};

	bool correctRGB();
	void setRGB(int R, int G, int B);
	bool operator ==(const RGB& p);
	bool operator != (const RGB& p);

	friend ostream& operator <<(ostream& os, const RGB& rgb);
	friend istream& operator >> (istream& in, RGB& rgb);

private:
	unsigned int R = 0;
	unsigned int G = 0;
	unsigned int B = 0;
};

int main()
{
	setlocale(LC_ALL, "rus");
	RGB rgb(233, 123, 0);
	RGB rgb2(233, 123, 0);
	rgb.correctRGB();

	return 0;
}



ostream& operator <<(ostream& os, const RGB& rgb)
{
	return os << rgb.R << ":" << rgb.G << ":" << rgb.B << endl;
}
istream& operator >> (istream& in, RGB& rgb)
{
	int R;
	int G;
	int B;
	in >> R >> G >> B;
	rgb.setRGB(R, G, B);
	return in; 
}
bool RGB::correctRGB()
{
	if ( (R <= 255 && R >= 0) && (G <= 255 && G >= 0) && (B <= 255 && B >= 0))
	{
		cout << "Значения корректны " << endl;
		return true;
	}
	cout << "Значения не корректны" << endl;
	return false;
}
void RGB::setRGB(int R, int G, int B)
{
	this->R = R;
	this->G = G;
	this->B = B;
}
bool RGB::operator==(const RGB& p)
{
	if ((R == p.R) && (G == p.G) && (B == p.B))
	{
		cout << "Равны" << endl;
		return true;
	}
	return false;
}
bool RGB::operator!=(const RGB& p)
{
	if ((R != p.R) && (G != p.G) && (B != p.B))
	{
		cout << "Не равны" << endl;
		return true;
	}
	return false;
}



