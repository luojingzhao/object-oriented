#include <iostream>
#include <stdio.h>
using namespace std;
int begin_adress, N, K;

struct Node
{
	int R;
	int L;
	int num;
	Node *before;
	Node *next;
}array[100005];

struct Node *Creat()
{
	Node *head;
	int Adress, Data, Next;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> Adress >> Data >> Next;
		array[Adress].L = Adress;
		array[Adress].num = Data;
		array[Adress].R = Next;
		if (Next != -1)
		{
			array[Adress].next = &array[Next];
			array[Next].before = &array[Adress];
		}
		else
		{
			array[Adress].next = NULL;
		}
	}
	head = &array[begin_adress];
	return head;
}


struct Node *Change(struct Node *head)
{
	int count = 0;
	struct Node *New_head, *p1, *p2, *p3;
	int i, j;
	//New_head=p1=p2=p3=new Node;
	New_head = NULL;
	N = 1;
	p1 = head;
	while (p1->next != NULL)
	{
		N++;
		p1 = p1->next;
	}
	p1 = head;
	while (p1&&N >= K)
	{
		count++;
		if (count == K)
		{
			N -= K;
			p3 = p1;
			p1 = p1->next;
			while (count--&&p3)
			{
				if (New_head == NULL) New_head = p3;
				else   p2->next = p3;
				p2 = p3;
				p3 = p3->before;
			}
			count = 0;
		}
		else
		{
			p1 = p1->next;
		}
	}
	while (p1)
	{
		if (New_head == NULL)
		{
			New_head = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
		p1 = p1->next;
	}
	p2->next = NULL;
	return New_head;
}


void Print(struct Node *head)
{
	struct Node *p;
	p = head;
	while (p)
	{
		if (p->next)
			printf("%05d %d %05d\n", p->L, p->num, p->next->L);
		else
		{
			p->R = -1;
			printf("%05d %d %d\n", p->L, p->num, p->R);
		}
		p = p->next;
	}
}
int main()
{
	cin >> begin_adress >> N >> K;
	Node *head;
	head = Creat();
	head = Change(head);
	Print(head);
	return 0;
}
