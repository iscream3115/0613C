#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum cardNum
{
	A = 1,
	J = 11,
	Q,
	K
};

struct card
{
	char shape[3];
	int num;
	bool isDraw;
};

card c[4][13];

void init(card (*fc)[13]);
void shuffle(card(*fc) [13]);
void printCard();

int main()
{
	int money = 10000;
	int bet = 0, selection = 0;
	int countI = 0, countJ = 0;
	int secretNum = 0;
	const char* secretShape = "  ";

	init(c);

	printf("-------------------------------------\n\n");
	printf("	HIGH LOW SEVEN\n\n");
	printf("-------------------------------------\n\n\n");
	
	shuffle(c);

	//printCard();

	while (money > 0)
	{

		printf("카드를 공개합니다.\n");

		for (int k = 0; k < 4; k++)
		{

			if(c[countI][countJ].num < 11 && c[countI][countJ].num > 1)	printf("%2s%d\t",c[countI][countJ].shape, c[countI][countJ].num);
			else if (c[countI][countJ].num == J)	printf("%2sJ\t", c[countI][countJ].shape);
			else if (c[countI][countJ].num == Q)	printf("%2sQ\t", c[countI][countJ].shape);
			else if (c[countI][countJ].num == K)	printf("%2sK\t", c[countI][countJ].shape);
			else if (c[countI][countJ].num == A)	printf("%2sA\t", c[countI][countJ].shape);

			if(countJ < 13) countJ++;
			else
			{
				countI++;
				countJ = 0;
			}

		}
		secretNum = c[countI][countJ].num;
		secretShape = c[countI][countJ].shape;

		printf("\t??\n");

		while (bet < 1000)
		{
			printf("보유 자산: %2d\n", money);

			printf("배팅할 금액 입력 (최소 금액 1000)\n> ");
			scanf_s("%d", &bet);
		}

		printf("\n다음 카드는? (1.high	2.low		3.seven)\n> ");
		scanf_s("%d", &selection);

		printf("마지막 카드는....\n\n");

		if (secretNum == J) printf("%2s J", secretShape);
		else if (secretNum == Q) printf("%2s Q", secretShape);
		else if (secretNum == K) printf("%2s J", secretShape);
		else if (secretNum == A) printf("%2s A", secretShape);
		else if (secretNum == 7) printf("***%2s 7***", secretShape);
		else printf("%2s %d", secretShape, secretNum);

		printf("\n이였다.\n");

		switch (selection)
		{
			case 1:
				if (7 < secretNum)
				{
					printf("High. 당신은 %d만큼의 돈을 획득 했다! \n", bet * 2);
					money += bet;
				}
				else
				{
					printf("당신은 돈을 잃었다...\n");
					money -= bet;
				}
				break;
			case 2:
				if (secretNum < 7)
				{
					printf("Low. 당신은 %d만큼의 돈을 획득 했다! \n", bet * 2);
					money += bet;
				}
				else
				{
					printf("당신은 돈을 잃었다...\n");
					money -= bet;
				}
				break;
			case 3:
				if (secretNum == 7)
				{
					printf("세븐을 맞췄다!!! 당신은 %d만큼의 거액을 획득했다!!\n", bet * 13);
					money += bet * 13;
				}
				else
				{
					printf("당신은 돈을 잃었다...\n");
					money -= bet;
				}
				break;
		}

		if (countI >= 3 && countJ >= 12)
		{
			shuffle(c);
			countI = 0;
			countJ = 0;
		}
		else
		{
			if (countJ < 13) countJ++;
			else
			{
				countI++;
				countJ = 0;
			}
		}

		bet = 0;

		printf("보유 자산: %2d\n", money);

		printf("\n******************************\n\n");

	}

	printf("당신은 모든 돈을 잃었다....\n");

	return 0;
}

void init(card (*fc)[13])
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			switch (i)
			{
			case 0:
				strcpy(fc[i][j].shape, "♥");
				break;
			case 1:
				strcpy(fc[i][j].shape, "♠");
				break;
			case 2:
				strcpy(fc[i][j].shape, "◆");
				break;
			case 3:
				strcpy(fc[i][j].shape, "♣");
				break;
			}
			fc[i][j].num = j + 1;
			fc[i][j].isDraw = false;
		}
				
	}
}

void shuffle(card (*fc)[13])
{
	srand((unsigned int)time(NULL));

	int count = 0;

	//까진 카드가 몇개 있는지 확인

	for (int k = 0; k < 40; k++)
	{
		int randomI = rand() % 4;
		int randomJ = rand() % 13;

		int randomI2 = rand() % 4;
		int randomJ2 = rand() % 13;

		int temp = fc[randomI][randomJ].num;
		char shapeTmp[3] = "  ";
			
		strcpy(shapeTmp, fc[randomI][randomJ].shape);

		fc[randomI][randomJ].num = fc[randomI2][randomJ2].num;
		strcpy(fc[randomI][randomJ].shape, fc[randomI2][randomJ2].shape);

		fc[randomI2][randomJ2].num = temp;
		strcpy(fc[randomI2][randomJ2].shape,shapeTmp);

	}


}

void printCard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{

			printf("%2s%d\t", c[i][j].shape, c[i][j].num);

		}

		printf("\n");

	}


}
