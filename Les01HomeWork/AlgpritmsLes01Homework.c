#include "AlgpritmsLes01Homework.h"
#include <stdio.h>
#include <math.h>
//Брижак Андрей Домашнее задание к занятию №1 Алгоритмы и структуры данных

//1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где m - масса тела в килограммах, h - рост в метрах.
//2. Найти максимальное из четырех чисел.Массивы не использовать.
//3. Написать программу обмена значениями двух целочисленных переменных :
//a.с использованием третьей переменной;
//b. *без использования третьей переменной.
//
//4. Написать программу нахождения корней заданного квадратного уравнения.
//5. С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится.
//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
//7. С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется определить, относятся поля к одному цвету или нет.
//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
//9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет — вывести False.
//11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
//12. Написать функцию нахождения максимального из трех чисел.
//13. * Написать функцию, генерирующую случайное число от 1 до 100.
//а) с использованием стандартной функции rand()
//б) без использования стандартной функции rand()
//
//14. *Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например, 252 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
//Достаточно решить 3 задачи.Записывайте в начало программы условие и свою фамилию.Все решения создавайте в одной программе.Задачи со звездочками выполняйте в том случае, если решили базовые.Снабдите программу меню.




struct Cell   //создаем структуру клетка
{
	int x;
	int y;
};

typedef struct Cell ChessCell; // определяем ChessCell как стурктуру Cell

void solution1();   //1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где m - масса тела в килограммах, h - рост в метрах.
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();
void solution11();
void solution12();
void solution13();
void solution14();
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

unsigned long long int tailing(unsigned long long int head)
{
	unsigned long long int tail;
	tail = head - (head / 10) * 10;											// вычисляем хвост - остаток от деления 
	return tail;
}

unsigned long long int compareSpec(unsigned long long int head1, unsigned long long int head2)
{
	//unsigned int numDig = 0;
	//unsigned int temp;
	//temp = head1;
	//while (temp>0)
	//{
	//	numDig += 1;
	//	temp = temp / 10;
	//}


	unsigned long long int tail1 = NULL;
	unsigned long long int tail2 = NULL;
	unsigned long long int automorf = NULL;
	unsigned long long int statehead1;
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

int maximum(int x1, int x2)   //определение максимума двух целых чисел
{
	if (x1> x2)
	{
		return x1;
	}
	else return x2;
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
			solution1();//1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где m - масса тела в килограммах, h - рост в метрах.
			break;
		case 2:
			solution2();
			break;
		case 3:
			solution3();
			break;
		case 7:
			solution7();
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

void solution1()	 //1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где m - масса тела в килограммах, h - рост в метрах.
{
	double wht;
	double gr;
	double BMI;
	printf("Input Weght (kg):");
	scanf_s("%lf", &wht);
	printf("Input growth (m):");
	scanf_s("%lf", &gr);
	BMI = wht / (gr*gr);
	printf("BMI: %lf", BMI);
}

void solution2() //2. Найти максимальное из четырех чисел.Массивы не использовать.
{
	int num1;
	int num2;
	int num3;
	int num4;
	int max;
	
	max = 0;
	printf("Input num1 (int):");
	scanf_s("%d", &num1);
	max = maximum(max, num1);
	printf("Input num2 (int):");
	scanf_s("%d", &num2);
	max = maximum(max, num2);
	printf("Input num3 (int):");
	scanf_s("%d", &num3);
	max = maximum(max, num3);
	printf("Input num4 (int):");
	scanf_s("%d", &num4);
	max = maximum(max, num4);
	printf("Maximum: %d\n", max);
}

void solution7()
{
	//7. *С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).
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

void solution14()
//14. *Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например, 252 = 625. 
//Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
{
	unsigned long long int num;
	unsigned long long int i;
	unsigned long long int result;
	unsigned long long int automorf;

	printf("Solution 2\n");
	printf("Display all special numbers on the screen.\n ");
	// Решение
	printf("Input integer number: \n ");
	scanf_s("%llu", &num);
	automorf = NULL;
	for (i = 0; i <= num; i++)
	{
		if (i==0)
		{
			automorf = 0;
			printf(" Automorf special number: \n ");
			printf("%llu\n ", automorf);
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
			printf("%llu\n ", automorf);
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
	printf("Menu\n");
	printf("1 - BMI\n");
	printf("2 - Maximum\n");
	printf("3 - task3\n");
	printf("7 - task7\n");
	printf("0 - exit\n");
}






