
#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));
	rand();
	
	/*
	�迭 : �ѹ� �������� ���� Ÿ���� ���� �������� ������ �� �ְ� ���ִ�
	����̴�.
	����Ÿ�� �迭�̸�[����];

	int NumberArray[100];

	���� ���� int�迭 100��¥���� �����ϸ� 400����Ʈ��ŭ�� �޸𸮰� 
	�ϳ��� ������� ������ �ȴ�.

	�迭�� �� ��ҿ� �����ϱ� ���ؼ��� �ε����� �̿��Ѵ�.
	�ε����� 0 ~ ���� - 1 ���� �����Ѵ�.
	*/
	// �迭�� ��ü ��Ҹ� 0���� �ʱ�ȭ�Ѵ�.
	int NumberArray[100] = {};

	// �迭�� 0, 1, 2, 3 �ε����� 1, 2, 3, 4�� ���� �ְ�
	// �������� ��� 0���� �ʱ�ȭ�Ѵ�.
	// int	NumberArray[100] = {1, 2, 3, 4};
	int Index = 10;

	if (Index < 0 || Index >= 100)
	{
		std::cout << "Index Error" << std::endl;
	}
	else
	{
		NumberArray[Index] = 1020;
	}

	NumberArray[0] = 500;

	NumberArray[1] += 20;

	for (int i = 0; i < 100; ++i)
	{
		std::cout << NumberArray[i] << std::endl;
	}

	/*
	int Number[5][10];
	int Number[5][10][6];
	��� ������ �� ���Ͽ� ��ü ���� �����ش�. 

	int Number[50] : 50��
	int Number[5][10] : 50��
	int Number[5][10][6] : 300��
	*/
	int NumberArray1[5][10] = {};

	NumberArray1[0][2] = 300;

	int NumberArray2[50] = {};

	NumberArray2[2 * 10 + 7] = 1010;

	system("cls");

	int Card[45] = {};

	// Card�� 0~49�� �ε����� 1~50���� ���ʴ�� �������ش�.
	for (int i = 0; i < 45; ++i)
	{
		Card[i] = i + 1;
		//Card[i] = rand() % 50 + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		int Index1 = rand() % 45;
		int Index2 = rand() % 45;

		int Temp = Card[Index1];
		Card[Index1] = Card[Index2];
		Card[Index2] = Temp;
	}

	/*
	
	int	Num1 = 10, Num2 = 20;
	int Temp;

	Temp = Num1;
	Num1 = Num2;
	Num2 = Temp;

	**/

	for (int i = 0; i < 6; ++i)
	{
		// \t : Tab Ű�� 1�� ���� �Ͱ� ���� ȿ���̴�. 
		std::cout << Card[i] << "\t";
	}

	std::cout << std::endl;
	
	/*
	for (int i = 0; i < 50; ++i)
	{
		std::cout << Card[i] << std::endl;
	}

	**/

	return 0;
}
