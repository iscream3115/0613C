#include <stdio.h>

void fPointer();

int main()
{
	fPointer();




	return 0;
}

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

void fPointer()
{
	char op = '\0';
	printf("연산자 입력 : ");
	scanf("%c", &op);

	int x = 0;
	printf("피연산자 입력 : ");
	scanf("%d", &x);

	int y = 0;
	printf("피연산자 입력 : ");
	scanf("%d", &y);

	int (*computer)(int, int) = NULL;

	//int* ptr = NULL;

	switch (op)
	{
		case '+':
			computer = add;
			break;
		case '-':
			computer = sub;
			break;
	}

	if (computer != NULL)
	{
		printf("결과 : %d\n", computer(x, y));
	}

	printf("\n");




}
