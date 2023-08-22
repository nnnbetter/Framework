
#include <iostream>
#include <time.h>

// 동일한 특수문자 2개씩 총 10개를 만든다.
// 20개의 배열이 필요하다.
// 20개의 배열을 가로 5개 세로 4줄로 출력하고
// 뒤집어진 상태를 표현하기 위해서 번호를 부여하여 출력한다.

int main()
{
	srand((unsigned int)time(0));
	rand();

	char	Card[20] = {};
	bool	Open[20] = {};
	char	CardSet[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };

	// 특수문자 2개씩 10종류를 지정한다.
	for (int i = 0; i < 10; ++i)
	{
		Card[i] = CardSet[i];
		Card[i + 10] = CardSet[i];
	}

	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % 20;
		int	Index2 = rand() % 20;
		
		char	Temp = Card[Index1];
		Card[Index1] = Card[Index2];
		Card[Index2] = Temp;
	}

	int	PrevInput = -1;
	int	Input = -1;
	bool	Check = false;

	while (true)
	{
		system("cls");
		// i가 세로줄번호가 되고 j가 가로번호가 된다.
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				// 인덱스 공식 : 세로번호 * 가로개수 + 가로번호
				int	Index = i * 5 + j;

				// 카드가 닫힌 상태라면 카드 번호를 출력한다.
				// bool 변수 앞에 !(NOT)을 붙이면 false일 경우 true
				// 가 된다.
				if (!Open[Index])
				{
					// 카드 번호를 출력한다.
					std::cout << Index << "\t";
				}

				else
				{
					std::cout << Card[Index] << "\t";
				}
			}

			std::cout << std::endl;
		}

		if (Check)
		{
			// PrevInput과 Input에 저장되어 있는 인덱스의 값을 가져와서
			// 비교한다.
			if (Card[PrevInput] != Card[Input])
			{
				Open[PrevInput] = false;
				Open[Input] = false;
			}

			PrevInput = -1;
			Check = false;
			system("pause");
			continue;
		}

		// 카드 번호를 입력받는다.
		std::cout << "카드번호를 입력하세요(-1 : 종료) : ";
		std::cin >> Input;

		if (Input == -1)
			break;

		else if (Input < -1 || Input > 19)
			continue;

		// Open 배열에서 Input 번째 인덱스가 true일 경우 이미 열려있는
		// 카드를 선택했다는 것이다.
		else if (Open[Input])
			continue;

		// 정상적으로 선택했다면 카드를 열어준다.
		Open[Input] = true;

		// PrevInput이 -1일 경우 두개의 카드 중 
		// 첫번째 카드를 Open하는 것이다.
		if (PrevInput == -1)
			PrevInput = Input;

		// PrevInput이 있을 경우 2번째 입력이라는 의미이므로
		// Check를 true로 활성화 시켜준다.
		else
			Check = true;
		}

		return 0;
}
