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

void solution1();   // прототип функции Check if the cells have the same color
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

int compareSpec(unsigned int head1, unsigned int head2)
{
	//unsigned int numDig = 0;
	//unsigned int temp;
	//temp = head1;
	//while (temp>0)
	//{
	//	numDig += 1;
	//	temp = temp / 10;
	//}


	unsigned int tail1 = NULL;
	unsigned int tail2 = NULL;
	unsigned int automorf = NULL;
	unsigned int statehead1;
	statehead1 = head1;
	while (head1 > 0)													// пока больше нуля выполняем цикл
	{
		tail1 = tailing(head1);
		head1 = head1 / 10;											// отсекаем хвост, оставляем голову	
		tail2 = tailing(head2);											// вычисляем хвост - остаток от деления второго числа
		head2 = head2 / 10;											// отсекаем хвост, оставляем голову	

	 if (tail1 == tail2)
		{
		 automorf = statehead1;
		}
		else
		{
			automorf = NULL;											// иначе обнуляем значение автоморфного числа
			break;														// прервываем цикл проверки автоморфного числа
		}
	}

	return automorf;
}

unsigned int tailing(unsigned int head)
{
	unsigned int tail;
	tail = head - (head / 10) * 10;											// вычисляем хвост - остаток от деления 
	return tail;
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
	unsigned int num;
	unsigned int i;
	unsigned int result;
	unsigned int automorf;

	printf("Solution 2\n");
	printf("Display all special numbers on the screen.\n ");
	// Решение
	printf("Input integer number: \n ");
	scanf_s("%d", &num);
	automorf = NULL;
	for (i = 0; i <= num; i++)
	{
		if (i==0)
		{
			automorf = 0;
			printf(" Automorf special number: \n ");
			printf("%d\n ", automorf);
		}
		else if (i == 1)
		{
			automorf = 1;
		}
		else
		{
			result = i * i;
			automorf = compareSpec(i, result);
		}
		
		if (automorf != NULL)
		{
			printf(" Automorf special number: \n ");
			printf("%d\n ", automorf);
		}
		
	}
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






