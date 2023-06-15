#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//메크로 함수
#define FREE(ptr) if(ptr != NULL) {free(ptr); ptr == NULL;}

char name[30];

char* readName()
{
	printf("이름을 입력하시오 : ");
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
	////지역변수는 함수 호출 후에 사라지기 때문에 쓰레기 값이 들어간다.
	//name = readName();
	//printf("name : %s\n", name);
	//name2 = readName();
	//printf("name : %s\n", name2);

	//다만 전역변수는 덮어씌워질 수 있다
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
		printf("메모리 할당 실패\n");

		//1
		exit(EXIT_FAILURE);
	}
	//else
	//{
	//	printf("메모리 할당 성공\n");

	//	//0
	//	exit(EXIT_SUCCESS);
	//}

	printf("free 이전 0x%p\n", ptr);

	//누수 방지
	free(ptr);

	//메모리 해제 이후 남아있는 포인터 = 허상 포인터
	printf("free 이후 0x%p\n", ptr);
	ptr = NULL;

	printf("free 이후 2 0x%p\n", ptr);

	FREE(ptr);

	{
		int size = 0;

		printf("동적 할당 int형 변수의 메모리 공간 : ");
		scanf_s("%d", &size);

		int* ma, *ca;

		//선언만 해주면 쓰레기 값이 들어간다.
		ma = (int*)malloc(sizeof(int) * size);

		//선언과 동시에 즉시 NULL로 초기화가 된다
		ca = (int*)calloc(size, sizeof(int));

		printf("\n초기화 전\n\n");

		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n",i,ma[i]);
			printf("ca[%d] : %d\n", i, ca[i]);
		}

		//malloc은 초기화를 해줘야 한다
		for (int i = 0; i < size; i++) ma[i] = 0;

		printf("\n초기화 후\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n", i, ma[i]);
			printf("ca[%d] : %d\n", i, ca[i]);
		}

		//LIFO. 직접 할당해줄 경우 역순으로 해제해줘야 한다.
		free(ca);
		ca = NULL;

		free(ma);
		ma = NULL;

		printf("\n\n");

	}


	//재할당 : 이미 할당된 메모리에다가 다시 메모리를 할당해준다. 만약 메모리 뒤에 충분한 공간이 있다면 자동으로 NULL로 초기화해준다.
	{
		int size = 0;

		printf("\n동적 할당 할 더블 형 변수 메모리 공간: ");
		scanf("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr 할당 주소 : %p\n",ptr);

		for (int i = 0; i < size; i++)
		{
			printf("ca[%d] : %lf\n", i, ptr[i]);
		}

		printf("\n재할당 할 더블형 변수의 메모리 공간 : ");
		scanf("%d", &size);


		ptr = (double*)realloc((double*)ptr, size);
		printf("ptr 재할당 받은 주소 : %p\n",ptr);

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

	printf("이름 입력 : ");
	scanf("%s", buffer);

	int size = strlen(buffer) + sizeof((char)('\0'));

	if(size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size,sizeof(char));

	if (name != NULL)
		strcpy(name, buffer);


	return name;
}
