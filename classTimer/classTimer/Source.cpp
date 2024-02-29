#include<iostream>
#include<ctime>
#include<ostream>

using namespace std;

//����������� ����� ����������(������).������ ������ ������ ������� �������� ������� �������.������ ���� ����� ������ �������(���������� ���������� time.h), 
// ��������� �������, ���������� �������� ������ �������, ����� ��������.����������� << ��� ������ ���������� �� �����.

class Timer
{
public:
	void timerStartStop();
	void safe_time();
	void reset();
	friend ostream& operator <<(ostream& os, const Timer& t);
private:
	time_t start = 0, end = 0;
	float t = 0;
	double result = 0;
	double *result_safe = 0;
	double *result_safe2 = 0;
	int SIZE = 1;
};

int main()
{
	setlocale(LC_ALL, "rus");

	Timer t;
	t.timerStartStop();

	t.safe_time();

	cout << t;

	t.reset();

	cout << t;

	t.timerStartStop();

	t.safe_time();

	cout << t;
	return 0;
}

ostream& operator <<(ostream& os,const Timer& t)
{
	cout << endl;
	cout << "COUT����������: " << endl;
	if (t.result_safe)
		for (int i = 0; i < t.SIZE-1; i++)
			os << t.result_safe[i] << endl;
	if (t.result_safe2)
		for (int i = 0; i < t.SIZE-1; i++)
			os << t.result_safe2[i] << endl;
	return os;
}

void Timer::timerStartStop()
{
	int a;
	int a2;
	cout << "������� 1 ��� �� ������ ������" << endl;
	cin >> a;
	if (a)
	{
		time(&start);
		cout << "������� 0 ��� �� ��������� ������" << endl;
		cin >> a2;
		if (!a2)
			time(&end);
		result = difftime(end, start);
	}
	cout << "��� ��������� = " << result << " �������" << endl;
}

void Timer::safe_time()
{
	if (!result_safe)
	{
		double* result_safe = new double[SIZE];
		for (int i = 0; i < SIZE-1; i++)
			result_safe[i] = result_safe2[i];
		result_safe[SIZE - 1] = result;
		delete [] result_safe2;
		result_safe2 = result_safe;
	}

	if (!result_safe2)
	{
		double* result_safe2 = new double[SIZE];
		for (int i = 0; i < SIZE - 1; i++)
			result_safe2[i] = result_safe[i];
		result_safe2[SIZE - 1] = result;
		delete[] result_safe;
		result_safe = result_safe2;
	}
	SIZE++;

	//double* result_safe2 = new double [SIZE];
	//for (int i = 0; i < SIZE-1; i++)
	//	result_safe2[i] = result_safe[i];
	//result_safe2[SIZE - 1] = result;
	//delete []result_safe;
	//result_safe = result_safe2;
	//double* result_safe = new double[SIZE];
	//for (int i = 0; i < SIZE; i++)
	//	result_safe[i] = result_safe2[i];
	//delete [] result_safe2;
	//result_safe2 = result_safe;
	//SIZE++;

}

void Timer::reset()
{
	delete[] result_safe;
	result_safe = NULL;
	delete[] result_safe2;
	result_safe2 = NULL;
	SIZE = 1;
	double* result_safe = 0;
	double* result_safe2 = 0;
}
