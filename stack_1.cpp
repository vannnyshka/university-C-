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
	int inf, n;

	stack* top = NULL;
	cout << "Vvedite kolichestvo elementov: ";
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> inf;
		top = add(top, inf);
	}

	stack* temp = NULL;
	stack* prev;
	for (int i = 0; i < n - 2; i++) //перемещение эл-ов до того, который надо удалить, во временный стек
	{
			temp = add(temp, top->inf);
			prev = top;
			top = top->next;
			delete prev;
	}
	prev = top;
	top = top->next;
	delete prev;//удаление второго снизу
	
	while (temp != NULL) //перемещение из временного стека в настоящий
	{
		top = add(top, temp->inf);
		temp = temp->next;
	}

	delst(temp);

	cout << "Stack s udalennim elementom" << endl;
	view(top);

	delst(top);
}