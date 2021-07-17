#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear;
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
int push(int a[], int& front, int& rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
			{
				a[i - front] = a[i];
			}
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int& front, int& rear, int& x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
int isFull()
{
	return (rear == MAX - 1);
}
int isEmpty()
{
	return (front == -1);
}
int main()
{

	int n, x, opt;
	bool check = false;
	cout << "\t\t\tBAI TAP THUC HANH SO 3\n";
	cout << "1.init Queue\n"
		<< "2.Push value into Queue\n"
		<< "3.Take value from Queue\n"
		<< "4.Check full\n"
		<< "5.Check empty\n"
		<< "6.Quit\n";
	do {
		cout << "Choose: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			init(a, front, rear);
			cout << "OK!\n";
			break;
		case 2:
			cout << "Input number of list: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				push(a, front, rear, x);
			}
			check = true;
			break;
		case 3:
			if (check)
			{
				int x;
				if (pop(a, front, rear, x))
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
				if (isFull())
					cout << "Queue is full\n";
				else
					cout << "Queue is not full\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 5:
			if (check)
			{
				if (isEmpty())
					cout << "Queue is empty\n";
				else
					cout << "Queue is not empty\n";
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