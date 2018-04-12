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

void solution1();   // �������� �������
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
	printf("Solution 2\n");
	// �������
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






