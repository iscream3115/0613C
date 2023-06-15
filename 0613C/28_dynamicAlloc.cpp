#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ũ�� �Լ�
#define FREE(ptr) if(ptr != NULL) {free(ptr); ptr == NULL;}

char name[30];

char* readName()
{
	printf("�̸��� �Է��Ͻÿ� : ");
	gets_s(name);
	return name;
}

void dynamicAlloc();

char* scanName();

int main()
{
	//char* name;
	//char* name2;
	//
	////���������� �Լ� ȣ�� �Ŀ� ������� ������ ������ ���� ����.
	//name = readName();
	//printf("name : %s\n", name);
	//name2 = readName();
	//printf("name : %s\n", name2);

	//�ٸ� ���������� ������� �� �ִ�
	//name = readName();
	//name2 = readName();
	//printf("name : %s\n", name);
	//printf("name : %s\n", name2);

	dynamicAlloc();

	{
		char* name = scanName();
		char* name2 = scanName();

		printf("name1 : %s\n", name);
		printf("name2 : %s\n", name2);

		FREE(name2);
		FREE(name);

	}


	return 0;
}

void dynamicAlloc()
{
	int* ptr = NULL;

	ptr = (int*)malloc(sizeof(int) * 5);

	if (ptr == NULL)
	{
		printf("�޸� �Ҵ� ����\n");

		//1
		exit(EXIT_FAILURE);
	}
	//else
	//{
	//	printf("�޸� �Ҵ� ����\n");

	//	//0
	//	exit(EXIT_SUCCESS);
	//}

	printf("free ���� 0x%p\n", ptr);

	//���� ����
	free(ptr);

	//�޸� ���� ���� �����ִ� ������ = ��� ������
	printf("free ���� 0x%p\n", ptr);
	ptr = NULL;

	printf("free ���� 2 0x%p\n", ptr);

	FREE(ptr);

	{
		int size = 0;

		printf("���� �Ҵ� int�� ������ �޸� ���� : ");
		scanf_s("%d", &size);

		int* ma, *ca;

		//���� ���ָ� ������ ���� ����.
		ma = (int*)malloc(sizeof(int) * size);

		//����� ���ÿ� ��� NULL�� �ʱ�ȭ�� �ȴ�
		ca = (int*)calloc(size, sizeof(int));

		printf("\n�ʱ�ȭ ��\n\n");

		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n",i,ma[i]);
			printf("ca[%d] : %d\n", i, ca[i]);
		}

		//malloc�� �ʱ�ȭ�� ����� �Ѵ�
		for (int i = 0; i < size; i++) ma[i] = 0;

		printf("\n�ʱ�ȭ ��\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n", i, ma[i]);
			printf("ca[%d] : %d\n", i, ca[i]);
		}

		//LIFO. ���� �Ҵ����� ��� �������� ��������� �Ѵ�.
		free(ca);
		ca = NULL;

		free(ma);
		ma = NULL;

		printf("\n\n");

	}


	//���Ҵ� : �̹� �Ҵ�� �޸𸮿��ٰ� �ٽ� �޸𸮸� �Ҵ����ش�. ���� �޸� �ڿ� ����� ������ �ִٸ� �ڵ����� NULL�� �ʱ�ȭ���ش�.
	{
		int size = 0;

		printf("\n���� �Ҵ� �� ���� �� ���� �޸� ����: ");
		scanf("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr �Ҵ� �ּ� : %p\n",ptr);

		for (int i = 0; i < size; i++)
		{
			printf("ca[%d] : %lf\n", i, ptr[i]);
		}

		printf("\n���Ҵ� �� ������ ������ �޸� ���� : ");
		scanf("%d", &size);


		ptr = (double*)realloc((double*)ptr, size);
		printf("ptr ���Ҵ� ���� �ּ� : %p\n",ptr);

		for (int i = 0; i < size; i++)
		{
			printf("ca[%d] : %lf\n", i, ptr[i]);
		}
		printf("\n\n");

		FREE(ptr);
	}


}

char* scanName()
{
	char buffer[100] = { 0 };

	printf("�̸� �Է� : ");
	scanf("%s", buffer);

	int size = strlen(buffer) + sizeof((char)('\0'));

	if(size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size,sizeof(char));

	if (name != NULL)
		strcpy(name, buffer);


	return name;
}
