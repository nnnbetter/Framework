
#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));
	rand();
	
	/*
	배열 : 한번 선언으로 같은 타입의 변수 여러개를 생성할 수 있게 해주는
	기능이다.
	변수타입 배열이름[개수];

	int NumberArray[100];

	위와 같이 int배열 100개짜리를 생성하면 400바이트만큼의 메모리가 
	하나의 블록으로 잡히게 된다.

	배열의 각 요소에 접근하기 위해서는 인덱스를 이용한다.
	인덱스는 0 ~ 개수 - 1 까지 존재한다.
	*/
	// 배열의 전체 요소를 0으로 초기화한다.
	int NumberArray[100] = {};

	// 배열의 0, 1, 2, 3 인덱스에 1, 2, 3, 4의 값을 넣고
	// 나머지는 모두 0으로 초기화한다.
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
	모든 개수를 다 곱하여 전체 수를 곱해준다. 

	int Number[50] : 50개
	int Number[5][10] : 50개
	int Number[5][10][6] : 300개
	*/
	int NumberArray1[5][10] = {};

	NumberArray1[0][2] = 300;

	int NumberArray2[50] = {};

	NumberArray2[2 * 10 + 7] = 1010;

	system("cls");

	int Card[45] = {};

	// Card의 0~49번 인덱스에 1~50까지 차례대로 대입해준다.
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
		// \t : Tab 키를 1번 누른 것과 같은 효과이다. 
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
