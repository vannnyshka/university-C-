#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct List {
	int info;
	List* pred, * next;
};

// Функция создает двусвязный список
void create(List** begin, List** end) {
	*begin = new List;
	*end = new List;

	(*begin)->pred = NULL;
	(*begin)->next = *end;

	(*end)->pred = *begin;
	(*end)->next = NULL;
}

// Функция добавления элементов с конца
void addend(List* sp, int info) {
	List* p = new List;
	p->info = info;
	p->pred = sp->pred;
	p->next = sp;
	p->pred->next = p;
	sp->pred = p;
}
void view(List* begin)
{
	List* p;
	p = begin->next;
	while (p->next != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

void dellist(List* begin)
{
	List* temp;
	while (begin != NULL)
	{
		temp = begin;
		begin = begin->next;
		delete temp;
	}
}

void del(List* item) {
	List* pred, * next;
	pred = item->pred;
	next = item->next;

	if (pred != NULL) pred->next = next;
	else next->pred = NULL;

	if (next != NULL) next->pred = pred;
	else pred->next = NULL;

	free(item);
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n, min, max, nmax, nmin, kolvo;

	List* begin = NULL, * end = NULL;

	create(&begin, &end);

	cout << "Введите кол-во элементов списка" << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int ad = -50 + rand() % 100;

		if (i == 0) {
			max = min = ad; nmax = nmin = i;
		}
		if (ad <= min) {
			min = ad; nmin = i;
		}
		if (ad >= max) {
			max = ad; nmax = i;
		}

		addend(end, ad);

	}
	cout << "Список:" << endl;
	view(begin);
	cout << endl << "min: " << min << endl << "max: " << max << endl;

	kolvo = abs(nmin - nmax) - 1;

	cout << endl << "Нужно удалить " << kolvo << " элемент(ов)" << endl;


	List* tempItem = begin->next;
	for (int i = 0; i < n; i++) {
		if (tempItem->info == max || tempItem->info == min) {

			//cout << "Первый на удаление: " << tempItem->info << endl;

			tempItem = tempItem->next;

			for (int j = 0; j < kolvo; j++) {
				cout << "Удаляю: " << tempItem->info << endl;

				del(tempItem);

				tempItem = tempItem->next;
			}

			break;
		}
		tempItem = tempItem->next;
	}

	cout << "Список с удаленными элементами:" << endl;
	view(begin);
	dellist(begin);
}