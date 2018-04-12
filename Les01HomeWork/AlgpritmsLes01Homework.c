#include "AlgpritmsLes01Homework.h"
#include <stdio.h>
#include <math.h>
//Брижак Андрей Домашнее задание к занятию №1 Алгоритмы и структуры данных

//1. *С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).
//Требуется определить, относятся ли к поля к одному цвету или нет.
//2. * Автоморфные числа.Натуральное число называется автоморфным, если оно равно
//последним цифрам своего квадрата.Например, 25 2 = 625. Напишите программу, которая
//вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие
//N.
//3. *Реализовать алгоритм поиска простых чисел «Решето Эратосфена».
//**Вывести самое большое число найденное с помощью этого алгоритма.
//***Рассчитать время нахождения этого числа.
//4. Реализовать алгоритм ускоренного возведения в степень.

//typedef struct Cell ChessCell; // определяем ChessCell как стурктуру Cell

struct Cell   //создаем структуру клетка
{
	int x;
	int y;
};

typedef struct Cell ChessCell; // определяем ChessCell как стурктуру Cell

void solution1();   // прототип функции
void solution2();
void solution3();
void menu();

///
/// функция проверка на четность  если четное 1, иначе 0
///
int Odd(int value)     // функция проверка на четность  если четное 1, иначе 0
{
	if (value % 2 == 0)
		//value - четное 
		return 1;
	else
		// нечетное 
		return 0;
}

/// если 0 черное, иначе белое
int whatColor(/*struct*/ ChessCell cell)
{
	if (Odd(cell.x) == 0 & Odd(cell.y) != 0)
	{
		return 0;
	}

	else return 1;
}

/// сравнение цвета клетки
void checkColor(/*struct */ChessCell firstCell, /*struct*/ ChessCell secondCell)  // сравнение цвета клетки
{

	int firstColor = whatColor(firstCell);
	int secondColor = whatColor(secondCell);
	if (firstColor == secondColor)
	{
		printf("It`s same colors Cells\n");
	}
	else
	{
		printf("It`s differents colors Cells\n");
	}

}

int main()
{
	int sel = 0;
	do
	{
		menu();
		scanf_s("%i", &sel);
		switch (sel)
		{
		case 1:
			solution1();
			break;
		case 2:
			solution2();
			break;
		case 3:
			solution3();
			break;
		case 0:
			printf("Bye-bye");
			break;
		default:
			printf("Wrong selected\n");
		}
	} while (sel != 0);
	return 0;
}

void solution1()
{
	//1. *С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).
	//Требуется определить, относятся ли к поля к одному цвету или нет.
	printf("Solution 1\n ");
	printf("Check if the cells have the same color?\n ");
	// Решение
	
	/*struct*/ ChessCell firstCell;
	/*struct*/ ChessCell secondCell;
	printf("Input FirstCell x1 (1-8):");
	scanf_s("%d", &firstCell.x);
	printf("Input FirstCell y1(1-8) :");
	scanf_s("%d", &firstCell.y);
	printf("Input SecondCel x2(1-8) :");
	scanf_s("%d", &secondCell.x);
	printf("Input SecondCel y2(1-8):");
	scanf_s("%d", &secondCell.y);
	checkColor(firstCell, secondCell);

}

void solution2()
{
	printf("Solution 2\n");
	// Решение
}

void solution3()
{
	printf("Solution 3\n");
	// Решение
}

void menu()
{
	printf("1 - task1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}






