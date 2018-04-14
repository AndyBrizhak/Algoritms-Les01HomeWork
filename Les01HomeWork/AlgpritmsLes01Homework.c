#include "AlgpritmsLes01Homework.h"
#include <stdio.h>
#include <math.h>
//������ ������ �������� ������� � ������� �1 ��������� � ��������� ������

//1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h*h); ��� m - ����� ���� � �����������, h - ���� � ������.
//2. ����� ������������ �� ������� �����.������� �� ������������.
//3. �������� ��������� ������ ���������� ���� ������������� ���������� :
//a.� �������������� ������� ����������;
//b. *��� ������������� ������� ����������.
//
//4. �������� ��������� ���������� ������ ��������� ����������� ���������.
//5. � ���������� �������� ����� ������.��������� ����������, � ������ ������� ���� �� ���������.
//6. ������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
//7. � ���������� �������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).��������� ����������, ��������� ���� � ������ ����� ��� ���.
//8. ������ a � b � ������� �������� � ���� ����� �� a �� b.
//9. ���� ����� ������������� ����� N � K.��������� ������ �������� �������� � ���������, ����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.
//10. ���� ����� ����� N(> 0).� ������� �������� ������� ������ � ������ ������� �� ������� ����������, ������� �� � ������ ����� N �������� �����.���� �������, �� ������� True, ���� ��� � ������� False.
//11. � ���������� �������� �����, ���� �� ����� ������ 0. ���������� ������� �������������� ���� ������������� ������ �����, �������������� �� 8.
//12. �������� ������� ���������� ������������� �� ���� �����.
//13. * �������� �������, ������������ ��������� ����� �� 1 �� 100.
//�) � �������������� ����������� ������� rand()
//�) ��� ������������� ����������� ������� rand()
//
//14. *����������� �����.����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.��������, 252 = 625. �������� ���������, ������� ������ ����������� ����� N � ������� �� ����� ��� ����������� �����, �� ������������� N.
//���������� ������ 3 ������.����������� � ������ ��������� ������� � ���� �������.��� ������� ���������� � ����� ���������.������ �� ����������� ���������� � ��� ������, ���� ������ �������.�������� ��������� ����.




struct Cell   //������� ��������� ������
{
	int x;
	int y;
};

typedef struct Cell ChessCell; // ���������� ChessCell ��� ��������� Cell

void solution1();   //1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h*h); ��� m - ����� ���� � �����������, h - ���� � ������.
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
/// ������� �������� �� ��������  ���� ������ 1, ����� 0
///
int Odd(int value)     // ������� �������� �� ��������  ���� ������ 1, ����� 0
{
	if (value % 2 == 0)
		//value - ������ 
		return 1;
	else
		// �������� 
		return 0;
}

/// ���� 0 ������, ����� �����
int whatColor(/*struct*/ ChessCell cell)
{
	if (Odd(cell.x) == 0 & Odd(cell.y) != 0)
	{
		return 0;
	}

	else return 1;
}

/// ��������� ����� ������
void checkColor(/*struct */ChessCell firstCell, /*struct*/ ChessCell secondCell)  // ��������� ����� ������
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
	tail = head - (head / 10) * 10;											// ��������� ����� - ������� �� ������� 
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
	while (head1 > 0)													// ���� ������ ���� ��������� ����
	{
		tail1 = tailing(head1);
		head1 = head1 / 10;											// �������� �����, ��������� ������	
		tail2 = tailing(head2);											// ��������� ����� - ������� �� ������� ������� �����
		head2 = head2 / 10;											// �������� �����, ��������� ������	

	 if (tail1 == tail2)
		{
		 automorf = statehead1;
		}
		else
		{
			automorf = NULL;											// ����� �������� �������� ������������ �����
			break;														// ���������� ���� �������� ������������ �����
		}
	}

	return automorf;
}

int maximum(int x1, int x2)   //����������� ��������� ���� ����� �����
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
			solution1();//1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h*h); ��� m - ����� ���� � �����������, h - ���� � ������.
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
			solution4();
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

void solution1()	 //1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h*h); ��� m - ����� ���� � �����������, h - ���� � ������.
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

void solution2() //2. ����� ������������ �� ������� �����.������� �� ������������.
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

//3. �������� ��������� ������ ���������� ���� ������������� ���������� :
//a.� �������������� ������� ����������;
//b. *��� ������������� ������� ����������.
void solution3()
{
	printf("Solution 3\n");
	// ������� � �������������� ������� ����������;
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
	//b. *��� ������������� ������� ����������.
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a= %d\n", a);
	printf("b= %d\n", b);
	getch();
}

void solution4()
//4. �������� ��������� ���������� ������ ��������� ����������� ���������.
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

//5. � ���������� �������� ����� ������.��������� ����������, � ������ ������� ���� �� ���������.
void solution5()
{
	int m;
	printf("Input number month (1-12):");
	scanf_s("%d", &m);
	if (m<1 || m>12 )
	{
		printf("Incorrect number month (only 1 ... 12)\n");
	}
	else if (true)
	{

	}


}

void solution7()
{
	//7. *� ���������� �������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).
	//��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
	printf("Solution 1\n ");
	printf("Check if the cells have the same color?\n ");
	// �������
	
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

void solution14()
//14. *����������� �����.����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.��������, 252 = 625. 
//�������� ���������, ������� ������ ����������� ����� N � ������� �� ����� ��� ����������� �����, �� ������������� N.
{
	unsigned long long int num;
	unsigned long long int i;
	unsigned long long int result;
	unsigned long long int automorf;

	printf("Solution 2\n");
	printf("Display all special numbers on the screen.\n ");
	// �������
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
	printf("7 - Chessmates color\n");
	printf("14 - Find automorf\n");
	printf("0 - exit\n");
}






