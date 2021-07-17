#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
node* sp;
void init()
{
	sp = NULL;
}
void push(int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = sp;
	sp = temp;
}
int pop(int& x)
{
	if (sp != NULL)
	{
		node* p = sp;
		sp = p->next;
		x = p->data;
		delete(p);
		return 1;
	}
	return 0;
}
int isEmpty()
{
	return (sp == NULL);
}

void changeBase(int n, int bin)
{
	while (n != 0)
	{
		int k = n % bin;
		push(k);
		n /= bin;
	}
	cout << endl;
}
void showStack()
{
	while (!isEmpty())
	{
		int x;
		pop(x);
		cout << x;
	}
}
int main()
{
	int n, x;
	cout << "Type decimal = ";
	cin >> n;
	changeBase(n, 2);
	showStack();
	return 0;
}