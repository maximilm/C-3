#include <iostream>
using namespace std;
#include "Tree.h"
int main()
{
	int capacity, com;
	float sum;
	int k;
	Tree tree;
	setlocale(0, "ru");
	cout << "Введите количество узлов идеального сбалансированного бинарного дерева: ";
	cin >> capacity;
	if (capacity == 0)
	{
		cout << "Бинарное дерево не может не иметь узлов.";
		return 1;
	}
	cout << "Введите значения узлов: ";
	tree.createTree(capacity, tree.getRoot());
	///*int count = 0;*/
	//while (capacity != 0)
	//{
	//	capacity /= 2;
	//	count += 1;
	//}
	cout << endl << "1 - Ввычислить среднее арифметическое левого поддерева;";
	cout << endl << "2 - Вычислить среднее арифметическое правого поддерева;";
	cout << endl << "3 - Отобразить дерево на экране, повернув его справа налево;";
	cout << endl << "4 - Удалить бинарное дерево;";
	cout << endl << "0 - Закончить работу программы.";
	do {
		cout << endl << "Введите номер функции: ";
		cin >> com;
		sum = 0;
		k = 0;
		switch (com)
		{
		case 1:
			tree.averageLeft(&((**tree.getRoot()).left), sum, k);
			cout << "Среднее арифметическое: " << sum / k;
			break;
		case 2:
			tree.averageRight(&((**tree.getRoot()).right), sum, k);
			cout << "Среднее арифметическое: " << sum / k;
			break;
		case 3:
			if ((*tree.getRoot()) != nullptr)
				tree.printTree(tree.getRoot(), 0);
			else
				cout << "Дерева не существует.";
			break;
		case 4:
			tree.deleteTree(tree.getRoot());
			break;
		};
	} while (com != 0);
}