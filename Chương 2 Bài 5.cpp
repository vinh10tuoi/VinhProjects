#include<iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;

void init(int a[], int& sp)
{
	sp = -1;
}
int push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;

}
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

int main()
{
	int n, x, opt;
	bool check = false;
	cout << "\t\t\tBAI TAP THUC HANH SO 3\n";
	cout << "1.init Stack\n"
		<< "2.Push value into stack\n"
		<< "3.Take value from stack\n"
		<< "4.Check full\n"
		<< "5.Check empty\n"
		<< "6.Quit\n";
	do {
		cout << "Choose: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			init(a, sp);
			cout << "OK!\n";
			break;
		case 2:
			cout << "Input number of list: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				push(a, sp, x);
			}
			check = true;
			break;
		case 3:
			if (check)
			{
				int x;
				if (pop(a, sp, x))
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
				if (isFull(a, sp))
					cout << "Stack is full\n";
				else
					cout << "Stack is not full\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 5:
			if (check)
			{
				if (isEmpty(a, sp))
					cout << "Stack is empty\n";
				else
					cout << "Stack is not empty\n";
			}
			else
				cout << "Invalid!\n";
			break;
		default:
			cout << "You chose QUIT\n";
		}
	} while (opt >= 1 || opt <= 4);
	return 0;
}