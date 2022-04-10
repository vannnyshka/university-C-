// По методу Лагранжа
#include <iostream>
#include <math.h>

using namespace std;

double fx(double x) //Функция
{
	return pow(x, 3) - 5 * pow(x, 2);
}

double d(double x, double PL) //Нахождение погрешности
{
	return (fx(x) - PL);
}

double PL(double xt, double* y, double* x, double n) //Интерполяционный многочлен Лагранжа 
{

	double PL, p = 0.0;

	for (int k = 1; k <= n; k++)
	{

		double  e = 1.0;
		for (int i = 1; i <= n; i++)
		{
			if (k != i)
			{
				e *= (xt - x[i]) / (x[k] - x[i]);
			}
		}
		p = p + y[k] * e;
	}
	PL = p;

	return(PL);

}

void table(double xt, double PL)
{

	cout << "Значение точки: " << xt << endl << "y= " << fx(xt) << endl << "PL(xt)= " << PL << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, m, n;

	int i, j;

	a = -2; b = 5; m = 5; n = 5;

	double x[15], y[15];

	for (i =1; i <= m; i++)
	{

		x[i] = a + (i - 1) * (b - a) / (m - 1);

		y[i] = fx(x[i]);

	}

	for (int i = 1; i < 21; i++)
	{
		double xt = a + (i - 1) * (b - a) / 20;

		table(xt, PL(xt, y, x, m));

		cout << "Погрешность: d= " << d(xt, PL(xt, y, x, m)) << endl << "-------------------------" << endl;
	}
}
