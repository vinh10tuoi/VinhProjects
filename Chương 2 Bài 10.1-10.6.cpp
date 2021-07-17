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
int isEmpty()
{
	return sp == NULL;
}
void push(int x)
{
	node* p = new node;
	p->data = x;
	p->next = sp;
	sp = p;
}
int pop(int& x)
{
	if (sp != NULL)
	{
		node* p = sp;
		x = p->data;
		sp = p->next;
		delete(p);
		return 1;
	}
	return 0;
}
// convert to binary
void changeBase(int n)
{
	while (n != 0)
	{
		int k = n % 2;
		push(k);
		n /= 2;
	}
}
void showStack()
{
	while (!isEmpty())
	{
		int x;
		pop(x);
		cout << x;
	}
	cout << endl;
}
int main()
{
	int n, x, opt;
	bool check = false;
	cout << "\t\t\tBAI TAP THUC HANH SO 3\n";
	cout << "1.init Stack\n"
		<< "2.Push value into stack\n"
		<< "3.Take value from stack\n"
		<< "4.Check empty\n"
		<< "5.Convert dec to bin\n"
		<< "6.Quit\n";
	do {
		cout << "Choose: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			init();
			cout << "OK!\n";
			break;
		case 2:
			cout << "Input number of list: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				push(x);
			}
			check = true;
			break;
		case 3:
			if (check)
			{
				int x;
				if (pop(x))
				{
					cout << x << endl;
				}
				else {

					cout << "Empty\n";
				}

			}
			else
				cout << "Invalid!\n";
			break;
		case 4:
			if (check)
			{
				if (isEmpty())
					cout << "Stack is empty\n";
				else
					cout << "Stack is not empty\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 5:
			cout << "Type decimal value = ";
			cin >> x;
			changeBase(x);
			cout << "Binary = ";
			showStack();
			break;
		default:
			cout << "You chose QUIT\n";
		}
	} while (opt >= 1 || opt <= 5);
	return 0;
}