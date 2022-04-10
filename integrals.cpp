#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fx(double x) //Функция
{
	return pow(x, 3) - 5 * pow(x, 2);
}

double d1_T(double x) //Первая точная производная
{
	return 3 * pow(x, 2) - 10 * x;
}

double d2_T(double x) // Вторая точная производная
{
	return 6 * x - 10;
}

double d1_P(double x, double fx(double x), double hp) // Первая приближенная производная
{

	return ((fx(x + hp) - fx(x - hp)) / (2 * hp));

}

double d2_P(double x, double fx(double x), double hp) // Вторая приближенная производная
{

	return((fx(x + hp) - 2 * fx(x) + fx(x - hp)) / (hp * hp));

}
double intTrapFun(double* x, double h, int m) // Метод трапеций
{
	// h * (((X1 + Xm) / 2) + (X2 + ... Xm-1))
	double IntTrap = 0;
	for (int i = 1; i < m; i++) 
	{
		IntTrap += x[i];
	}
	IntTrap = (IntTrap + (x[0] + x[m]) / 2) * h;

	return IntTrap;
}

double intSrFun(double* x, double h, int m) // Метод средних
{
	double IntSr = 0;
	for (int i = 0; i < m - 1; i++) {
		IntSr = IntSr + (x[i + 1] + x[i]) / 2;
	}
	IntSr = IntSr * h;

	return IntSr;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a = -2, b = 5; // Интервал, на котором считаем
	double hp; // Шаг производной
	double d; // Погрешность для интеграла
	double d1_t, d2_t, d1_p, d2_p, e1, e2;
	int m = 2; // Кол-во шагов в интеграле
	int n; //Для кейсов
	double x[10000]; // Сюда будут записываться значения точек по шагам в интеграле и значение шага в производной

	cout << "Выберите шаг производной h: 1 - 0.2; 2 - 0.1; 3 - 0.005" << endl;
	cin >> n;
	switch (n) 
	{ 
	case 1: hp = 0.2; break;
	case 2: hp = 0.1; break;
	case 3: hp = 0.005; break;
	default:
		cout << "Выбрано не верное значение" << endl;
		return 0;
	}

	cout << endl << "|" << setw(10) << "d1_точн." << setw(10) << "|" << setw(10) << "d1_прибл." << setw(10)
		<< "|" << setw(10) << "d2_точн." << setw(10) << "|" << setw(10) << "d2_прибл." << setw(10) << "|" << endl;
	for (int i = 0; i < 20; i++)
	{
		x[i] = a + hp * i;
		d1_t = d1_T(x[i]);
		d2_t = d2_T(x[i]);
		d1_p = d1_P(x[i], fx, hp);
		d2_p = d2_P(x[i], fx, hp);
		e1 = d1_t - d1_p;
		e2 = d2_t - d2_p;
		cout << "|" << setw(10) << d1_t << setw(10) << "|" << setw(10) << d1_p << setw(10)
			<< "|" << setw(10) << d2_t << setw(10) << "|" << setw(10) << d2_p << setw(10) << "|" << endl;
	}
	cout << "Погрешность d1: " << e1 << endl << "Погрешность d2: " << e2 << endl << endl;


	cout << "Выберите погрешность d: 1 - 0.1; 2 - 0.01; 3 - 0.001" << endl;
	cin >> n;
	switch (n)
	{
	case 1: d = 0.1; break;
	case 2: d = 0.01; break;
	case 3: d = 0.001; break;
	default:
		cout << "Выбрано не верное значение" << endl;
		return 0;
	}

	double intTrap = 0, intSr = 0; // Интеграл методом трапеций и средних

	double h;
	do // Метод с автоматическим подбором шага
	{
		h = (double)(b - a) / m; // Длина шага

		for (int i = 0; i <= m; i++) 
		{
			x[i] = fx(a + h * i);
		}

		intTrap = intTrapFun(x, h, m);
		intSr = intSrFun(x, h, m);

		m *= 2;

	} while (abs(intSr - intTrap) > d);

	double intAuto = (intTrap + 2 * intSr) / 3;

	cout << "Интеграл по методу средних: " << intSr << endl;
	cout << "Интеграл по методу трапеций: " << intTrap << endl;
	cout << "Полученный интеграл методом автомата: " << intAuto << endl;
}