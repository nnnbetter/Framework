
#include <iostream>
#include <time.h>

// ������ Ư������ 2���� �� 10���� �����.
// 20���� �迭�� �ʿ��ϴ�.
// 20���� �迭�� ���� 5�� ���� 4�ٷ� ����ϰ�
// �������� ���¸� ǥ���ϱ� ���ؼ� ��ȣ�� �ο��Ͽ� ����Ѵ�.

int main()
{
	srand((unsigned int)time(0));
	rand();

	char	Card[20] = {};
	bool	Open[20] = {};
	char	CardSet[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };

	// Ư������ 2���� 10������ �����Ѵ�.
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
		// i�� �����ٹ�ȣ�� �ǰ� j�� ���ι�ȣ�� �ȴ�.
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				// �ε��� ���� : ���ι�ȣ * ���ΰ��� + ���ι�ȣ
				int	Index = i * 5 + j;

				// ī�尡 ���� ���¶�� ī�� ��ȣ�� ����Ѵ�.
				// bool ���� �տ� !(NOT)�� ���̸� false�� ��� true
				// �� �ȴ�.
				if (!Open[Index])
				{
					// ī�� ��ȣ�� ����Ѵ�.
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
			// PrevInput�� Input�� ����Ǿ� �ִ� �ε����� ���� �����ͼ�
			// ���Ѵ�.
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

		// ī�� ��ȣ�� �Է¹޴´�.
		std::cout << "ī���ȣ�� �Է��ϼ���(-1 : ����) : ";
		std::cin >> Input;

		if (Input == -1)
			break;

		else if (Input < -1 || Input > 19)
			continue;

		// Open �迭���� Input ��° �ε����� true�� ��� �̹� �����ִ�
		// ī�带 �����ߴٴ� ���̴�.
		else if (Open[Input])
			continue;

		// ���������� �����ߴٸ� ī�带 �����ش�.
		Open[Input] = true;

		// PrevInput�� -1�� ��� �ΰ��� ī�� �� 
		// ù��° ī�带 Open�ϴ� ���̴�.
		if (PrevInput == -1)
			PrevInput = Input;

		// PrevInput�� ���� ��� 2��° �Է��̶�� �ǹ��̹Ƿ�
		// Check�� true�� Ȱ��ȭ �����ش�.
		else
			Check = true;
		}

		return 0;
}
