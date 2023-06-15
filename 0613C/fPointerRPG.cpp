#include <stdio.h>
#include <string.h>

//c++에선 구조체를 선언할 때 typedef를 안써도 된다
struct player
{
	char name[255];
	char location[255];
	int hp;

	void (*fDead[3])(struct player*);

};

void miniRPG2();
void printDead(player* p);
void revive(player* p);
void moveTown(player* p);

int main()
{
	miniRPG2();

	return 0;
}

void miniRPG2()
{
	player p =
	{
		"Wizard",
		"Dungeon",
		100,
		{NULL,NULL,NULL}
	};

	p.fDead[0] = printDead;
	p.fDead[1] = revive;
	p.fDead[2] = moveTown;

	printf("name : %s loc : %s HP :%d\n", p.name, p.location, p.hp);

	int damage = 0;
	while (1)
	{
		printf("Damage : ");
		scanf_s("%d", &damage);
		p.hp -= damage;

		if (p.hp < 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (p.fDead[i] != NULL)
					p.fDead[i](&p);
			}
			break;
		}
	}

	printf("name : %s loc : %s HP :%d\n", p.name, p.location, p.hp);

}

void printDead(player* p)
{
	printf("%s는 죽었다.\n",p->name);

}


void revive(player* p)
{
	printf("%s는 살아났다.\n", p->name);
}

void moveTown(player* p)
{
	printf("%s는 마을로 이동했다\n", p->name);
	strcpy(p->location, "계승의 제사장");


}
