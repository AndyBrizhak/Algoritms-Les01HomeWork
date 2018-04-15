#include "AlgpritmsLes01Homework.h"
#include <stdio.h>
#include <math.h>
//#include <string.h>

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
	//setlocale(LC_ALL, "Russian");
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
		case 4:
			solution4();
			break;
		case 5:
			solution5();
			break;
		case 6:
			solution6();
			break;
		case 7:
			solution7();
			break;
		case 8:
			solution8();
			break;
		case 9:
			solution9();
			break;
		case 10:
			solution10();
			break;
		case 11:
			solution11();
			break;
		case 12:
			solution12();
			break;
		case 13:
			solution13();
			break;
		case 14:
			solution14();
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
	getch();
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
	getch();
}

//3. Написать программу обмена значениями двух целочисленных переменных :
//a.с использованием третьей переменной;
//b. *без использования третьей переменной.
void solution3()
{
	printf("Solution 3\n");
	// Решение с использованием третьей переменной;
	int a, b, c;
	printf("Input a (int):");
	scanf_s("%d", &a);
	printf("Input b (int):");
	scanf_s("%d", &b);
	c = b;
	b = a;
	a = c;
	printf("a= %d\n", a);
	printf("b= %d\n", b);
	getch();
	//b. *без использования третьей переменной.
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a= %d\n", a);
	printf("b= %d\n", b);
	getch();
}

void solution4()
//4. Написать программу нахождения корней заданного квадратного уравнения.
// ax^2+bx+c=0 
//D=b^2-4ac
//
{
	double a, b, c, D, x1, x2;
	printf("Input a :");
	scanf_s("%lf", &a);
	printf("Input b :");
	scanf_s("%lf", &b);
	printf("Input c :");
	scanf_s("%lf", &c);
	D = b * b - 4 * a*c;
	if (D>0)
	{
		x1 = (sqrt(D) - b) / (2 * a);
		x2 = (sqrt(D) + b) / (2 * a);
		printf("First root: %lf\n", x1);
		printf("Second root: %lf\n", x2);
	}
	else if (D==0)
	{
		x1 = -1 * (b / 2 * a);
		printf("One root: %lf\n", x1);
	}
	else
	{
		printf("No roots\n");
	}
	getch();
}

//5. С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится.
void solution5()
{
	int m;
	printf("Input number month (1-12):");
	scanf_s("%d", &m);
	if (m<1 || m>12 )
	{
		printf("Incorrect number month (only 1 ... 12)\n");
	}
	else if (m==12 || m==1 || m==2)
	{
		printf("This is Winter\n");
	}
	else if (m==3 || m==4 || m==5)
	{
		printf("This is Spring\n");
	}
	else if (m == 6 || m == 7 || m == 8)
	{
		printf("This is Summer\n");
	}
	else if (m == 9 || m == 10 || m == 11)
	{
		printf("This is Autumn\n");
	}
	else
	{
		printf("Incorrect number month (only intger 1 ... 12)\n");
	}
	getch();
}

//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void solution6()
{
	int age;
	printf("Input age (years) (1...150):");
	scanf_s("%d", &age);
	if (age<0 || age>150)
	{
		printf("Incorrect age (only 1 ... 150)\n");
	}
	else if (age % 10 == 1)
	{
		printf(" Your age is %d years old\n", age);
	}
	else if (age % 10 == 2 || age % 10 == 3 || age % 10 == 4)
	{
		printf(" Your age is %d years old\n", age);
	}
	else if (age % 10 == 0 || age % 10 == 5 || age % 10 == 6 || age % 10 == 7 || age % 10 == 8 || age % 10 == 9)
	{
		printf(" Your age is %d years old\n", age);
	}
	else
	{
		printf("Incorrect age (only 1 ... 150)\n");
	}
	getch();
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
	getch();

}

//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void solution8()
{
	int a, b, sq, cb, i ;
	printf("Input a (int):");
	scanf_s("%d", &a);
	printf("Input b (int):");
	scanf_s("%d", &b);
	for ( i = a; i <= b; i++)
	{
		sq = pow(i, 2);
		cb = sq * i;
		printf(" Square number  %d is %d\n", i, sq);
		printf(" Cube number  %d is %d\n", i, cb);

	}
	getch();
}

//9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
void solution9()
{
	getch();
}

//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.
//Если имеются, то вывести True, если нет — вывести False.
void solution10()
{
	getch();
}

//11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
void solution11()
{
	getch();
}

//12. Написать функцию нахождения максимального из трех чисел.
void solution12()
{
	getch();
}

//13. * Написать функцию, генерирующую случайное число от 1 до 100.
//а) с использованием стандартной функции rand()
//б) без использования стандартной функции rand()

void solution13()
{
	getch();
}


void solution14()
//14. *Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например, 252 = 625. 
//Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
{
	unsigned long long int num;
	unsigned long long int i;
	unsigned long long int result;
	unsigned long long int automorf;

	printf("Automorf \n");
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
	getch();
}


void menu()
{
	printf("Menu\n");
	printf("1 - BMI\n");
	printf("2 - Maximum\n");
	printf("3 - Change num\n");
	printf("4 - Roots\n");
	printf("5 - Month\n");
	printf("6 - Age\n");
	printf("7 - Chessmates color\n");
	printf("8 - degree\n");
	printf("9 - division\n");
	printf("10 - odd\n");
	printf("11 - flag\n");
	printf("12 - Max3\n");
	printf("13 - Rand\n");
	printf("14 - Find automorf\n");
	printf("0 - exit\n");
}






