#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct stack 
{
	int inf;
	stack* next;
};

void view(stack* top) //Функция вывода стека
{
	while (top != NULL)
	{
		cout << top->inf << endl;
		top = top->next;
	}
}

stack* add(stack* top, int info) //Функция добавления элементов в стек
{
	stack* p = new stack;
	p->next = top;
	p->inf = info;
	return p;
}

void delst(stack* top)
{
	stack* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

int main()
{
	int inf, n, sum = 0, kolvo = 0;
	double srednee;
	stack* top = NULL;
	cout << "Vvedite kolichestvo elementov: ";
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> inf;
		top = add(top, inf);
		sum += inf;
	}
	srednee = sum / n;
	for (int i = 0; i < n; i++) 
	{
		if (top->inf < srednee) 
		{
			kolvo++;
		}
		top = top->next;
	}
	cout << "Elementov men'she srednego " << kolvo;
	delst(top);
}