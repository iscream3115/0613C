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
	printf("������ �Է� : ");
	scanf("%c", &op);

	int x = 0;
	printf("�ǿ����� �Է� : ");
	scanf("%d", &x);

	int y = 0;
	printf("�ǿ����� �Է� : ");
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
		printf("��� : %d\n", computer(x, y));
	}

	printf("\n");




}
