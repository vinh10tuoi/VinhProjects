#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
node* first;
void init()
{
	first = NULL;
}
void insertFirst(int x)
{
	node* temp = new node;
	temp->next = NULL;
	temp->data = x;
	first = temp;
}
void insertLast(int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (first == NULL)
	{
		first = temp;
	}
	else {
		node* p = first;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;

	}
}
void printList()
{
	node* p = first;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
//node* search(int x)
//{
//	node* p = first;
//	while (p != NULL && p->data != x)
//		p = p->next;
//	if (p != NULL)
//		return p;
//	return 0;
//}
int deleteFirst()
{
	if (first != NULL)
	{
		node* p = first;
		first = first->next;
		delete(p);
		return 1;
	}
	return 0;
}
int deleteLast()
{
	if (first != NULL)
	{
		node* p = first;
		node* q = NULL;
		if (p != NULL)
		{
			while (p->next != NULL)
			{
				q = p;
				p = p->next;
			}
		}
		if (p != first)
			p->next = NULL;
		else
			first = NULL;
		delete(p);
		return 1;
	}
	return 0;

}
int deleteAt(int k)
{
	node* p = first;
	if (p != NULL)
	{
		for (int i = 0; i < k - 1; i++)
		{
			p = p->next;
		}
		node* temp = p->next;
		p->next = temp->next;
		delete(temp);
		return 1;
	}
	return 0;
}
int search(int x)
{
	int i = 0;
	node* p = first;
	while (p != NULL && p->data != x)
	{
		i++;
		p = p->next;
	}
	if (p != NULL)
		return i;
	return -1;
}
int Search_Delete(int x, int n)
{
	if (search(x) == 0)
	{
		return deleteFirst();
	}
	else if (search(x) == n - 1)
	{
		return deleteLast();
	}
	else {
		return deleteAt(search(x));
	}
	return 0;
}
int main()
{
	
	int n, x, opt;
	init();
	bool check = false;
	cout << "\t\t\tBAI TAP CHUONG 2\n";
	cout << "1.input List\n"
		<< "2.Display\n"
		<< "3.Find value x\n"
		<< "4.Add value at head of list\n"
		<< "5.Delete value at head\n"
		<< "6.Add value at last of list\n"
		<< "7.Delete value at last\n"
		<< "8.Find and delete value from list\n"
		<< "9.Quit\n";
	do {
		cout << "Choose: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Input number of list: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				insertLast(x);
			}
			check = true;
			break;
		case 2:
			if (check)
			{
				printList();
			}
			else
				cout << "Invalid!\n";
			break;
		case 3:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				if (search(x))
					cout << x << " exists in list\n";
				else
					cout << x << " not exists in list\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 4:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				insertFirst(x);
			}
			else
				cout << "Invalid!\n";
			break;
		case 5:
			if (check)
			{
				if (deleteFirst())
					cout << "Delete Successfully!\n";
				else
					cout << "Delete Unsuccessfully!\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 6:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				insertLast(x);
			}
			else
				cout << "Invalid!\n";
			break;
		case 7:
			if (check)
			{
				if (deleteLast())
					cout << "Delete Successfully!\n";
				else
					cout << "Delete Unsuccessfully!\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 8:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				if (Search_Delete(x, n))
					cout << "Successfully!\n";
				else
					cout << "Unsuccessfully!\n";
			}
			else
				cout << "Invalid!\n";
			break;
		default:
			cout << "You chose QUIT\n";
		}
	} while (opt >= 1 || opt <= 8);
	return 0;
}