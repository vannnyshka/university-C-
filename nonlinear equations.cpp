#include <iostream>
#include <math.h>

using namespace std;

//методы решения нелинейных уравнений
//метод Вегстейна, вариант 10

double f(double x)
{
return pow(x, 3) - 5 * pow(x, 2)+12;

}

double df(double x) 

{

return (3*pow(x,2)-10*x);

}

double MV(double alph, double bett, double e) 
{
	double MV, p = 0.0, x0, x1, y0, y1, z, de;
	x0=alph; x1=bett; 
	y0=f(x0);
	y1=f(x1);
	int it=0;
	do
	{
	    it=it+1;
	    double d=x1-x0;
	    z=x1-((y1*d)/(y1-y0));
	    de = abs(x1-z);
	    x0=x1;
	    x1=z;
	    y0=y1;
	    y1=f(z);
	    
	} while (de<e||it>100);
	MV=z;
	return(MV);
}


int main()
{

double a = -2, b = 5 , m, h, x, y, alph, bett, z;

double E = 0.0001;

m = 20;

h = (b - a) / m;

x = a;

while (x < b) {

y = f(x);

cout << "x:" << x<<" "<< "y:" << y << endl;

x = x + h;

}

cout << "Korni" << endl;

alph=a;
bett=alph+h;

for(alph = a; alph<b; alph+=h, bett+=h)
{
  if(f(alph)*f(bett)<0)
  {
cout<<"x:"<<MV(alph,bett,E)<<endl;
}
}
return 0;
}