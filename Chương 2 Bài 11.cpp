#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
void init()
{
	front = NULL;
	rear = NULL;
}

void push(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
int main()
{

	int n, x, opt;
	bool check = false;
	cout << "\t\t\tBAI TAP THUC HANH SO 4\n";
	cout << "1.init Queue\n"
		<< "2.Push value into Queue\n"
		<< "3.Take value from Queue\n"
		<< "4.Check empty\n"
		<< "5.Quit\n";
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
	} while (opt >= 1 && opt <= 4);
	return 0;
}