#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;
};
node* first, * last;
void init()
{
	first = NULL;
	last = NULL;
}
void insert_First(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	if (first != NULL)
	{
		first->pre = p;
	}
	else {
		last = p;
	}
	first = p;
	
}
void insert_Last(int x) {
	node* p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = last;
	if (last != NULL) {
		last->next = p;
	}
	else {
		first = p;
	}
	last = p;
}
void insert_At(int k, int x) {
	node* p = first;
	if (p != NULL) 
	{
		for (int i = 0; i < k - 1; i++)
		{
			p = p->next;
		}
		node* temp = new node;
		temp->data = x;
		temp->next = p->next;
		temp->pre = p;
		p->next->pre = temp;
		p->next = temp;
	}
}
void printProccess()
{
	node* p = first;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
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
		node* p2 = temp->next;
		p->next = p2;
		p2->pre = p;
		delete(temp);
		return 1;
	}
	return 0;
}
int deleteFirst()
{
	if (first != NULL)
	{
		node* p = first;
		first = first->next;
		delete(p);
		if (first != NULL)
		{
			first->pre = NULL;
		}
		else {
			last = NULL;
		}
		return 1;
	}
	return 0;
}
int deleteLast()
{
	if (last != NULL)
	{
		node* p = last;
		last = last->pre;
		delete(p);
		if (last != NULL)
		{
			last->next = NULL;
		}
		else {
			first = NULL;
		}
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
	else if (search(x) == n-1)
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
	int k;
	bool check = false;
	init();
	
	cout << "\t\t\tBAI THUC HANH CHUONG 1\n";
	cout << "1.Init a list\n"
		<< "2.Display the list\n"
		<< "3.Find a value\n"
		<< "4.Add 1 value from last\n"
		<< "5.Delete value from last\n"
		<< "6.Delete value from index i\n"
		<< "7.Search and delete value x\n"
		<< "8.Quit\n";
	do {
		cout << "Choose: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Type the number of node: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> x;
				insert_Last(x);
			}
			check = true;
			break;
		case 2:
			if (check)
			{
				printProccess();
				cout << endl;
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		case 3:
			if (check)
			{
				cout << "Type input: ";
				cin >> x;
				if (search(x) != -1)
					cout << "Value " << x << "  exists at node " << search(x) << ".\n";
				else
					cout << "Not found value " << x << endl;
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		case 4:
			if (check)
			{
				cout << "Type input: ";
				cin >> x;
				insert_Last(x);
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		case 5:
			if (check)
			{
				if (deleteLast())
					cout << "Delete successfully!\n";
				else
					cout << "Delete unsuccessfully!\n";
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		case 6:
			if (check)
			{
				do {
					cout << "Type index: ";
					cin >> k;
					if (k > n)
						cout << "Invalid\n";
				} while (k > n);
				deleteAt(k);
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		case 7:
			if (check)
			{
				cout << "Type input: ";
				cin >> x;
				Search_Delete(x, n);
			}
			else
				cout << "Invalid. Please init a list\n";
			break;
		default:
			cout << "You chose QUIT";
		}
	} while (opt >= 1 || opt <= 7);
	return 0;
}