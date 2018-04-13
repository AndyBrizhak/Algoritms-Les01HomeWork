#include "AlgpritmsLes01Homework.h"
#include <stdio.h>
#include <math.h>
//������ ������ �������� ������� � ������� �1 ��������� � ��������� ������

//1. *� ���������� �������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).
//��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
//2. * ����������� �����.����������� ����� ���������� �����������, ���� ��� �����
//��������� ������ ������ ��������.��������, 25 2 = 625. �������� ���������, �������
//������ ����������� ����� N � ������� �� ����� ��� ����������� �����, �� �������������
//N.
//3. *����������� �������� ������ ������� ����� ������� ����������.
//**������� ����� ������� ����� ��������� � ������� ����� ���������.
//***���������� ����� ���������� ����� �����.
//4. ����������� �������� ����������� ���������� � �������.

//typedef struct Cell ChessCell; // ���������� ChessCell ��� ��������� Cell

struct Cell   //������� ��������� ������
{
	int x;
	int y;
};

typedef struct Cell ChessCell; // ���������� ChessCell ��� ��������� Cell

void solution1();   // �������� ������� Check if the cells have the same color
void solution2();
void solution3();
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

unsigned int tailing(unsigned int head)
{
	unsigned int tail;
	tail = head - (head / 10) * 10;											// ��������� ����� - ������� �� ������� 
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
	//1. *� ���������� �������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).
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

}

void solution2()
{
	unsigned int num;
	unsigned int i;
	unsigned int result;
	unsigned int automorf;

	printf("Solution 2\n");
	printf("Display all special numbers on the screen.\n ");
	// �������
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
	// �������
}

void menu()
{
	printf("1 - task1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}






