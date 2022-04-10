//метод Гаусса
#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
  setlocale(LC_ALL, "Russian");

int m, i, j, k;

double f;

cout << "Введите количество переменных(и уравнений)" << endl;

cin >> m;

double** a;

a = new double* [m];

for (i = 0; i < m; i++) 
{
a[i] = new double[m];
}

cout << "Введите коэффициенты при переменных:"<< endl;

for (i = 0; i < m; i++) {

for (j = 0; j < m; j++) {

cin >> a[i][j];

}
cout << endl;
}
cout << "Матрица коэффициентов системы имеет вид:" << endl;

for (i = 0; i < m; i++) 
{
for (j = 0; j < m; j++) 
{
cout << a[i][j] <<" ";
}
cout << endl;
}

double b[5];
double x[5];

cout << "Введите правую часть ограничений:" << endl;

for (i = 0; i < m; i++) {
cin >> b[i];
}
cout << endl;

cout << "Правая часть ограничений в матричном виде имеет вид:" << endl;
for (i = 0; i < m; i++) 
{
cout << b[i] << endl;
}

for (j = 0; j < m; j++) 
{
for (i = j + 1; i < m; i++) 
{
f = a[i][j] / a[j][j];
for (k = j; k < m; k++) 
{
a[i][k] = a[i][k] - f * a[j][k];
}
b[i] = b[i] - f * b[j];
}

}
cout << "Полученная матрица:" << endl;
for (i = 0; i < m; i++) {
for (j = 0; j < m; j++) {
cout << a[i][j] << " ";
}
cout << endl;
}

x[m - 1] = b[m - 1] / a[m - 1][m - 1];
for (i = m - 2; i >= 0; i--) {
x[i] = b[i];
for (j = i+1; j <m; j++){
x[i] = x[i] - x[j] * a[i][j];
}
x[i] = x[i] / a[i][i];
}
cout<<"Корни уравнений:"<<endl;
for (i = 0; i < m; i++) 
{
cout << "x" << i+1 << "=" << x[i] << endl;
}
delete[]a;
return 0;
}