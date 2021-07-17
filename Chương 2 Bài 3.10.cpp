#include<iostream>
using namespace std;
#define MAX 100

void input(int a[], int& n)
{
	cout << "Type number of list: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
void deleteLast(int a[], int& n)
{
	n--;
}
void deleteFirst(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void deleteAt(int a[], int& n, int k)
{
	for (int i = k; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void addHead(int a[], int& n, int x)
{
	for (int i = n; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	n++;
}
void addTail(int a[], int& n, int x)
{
	a[n++] = x;
	
}
int binSearch(int a[], int n, int x)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = (r + l) / 2;
		if (a[mid] < x)
			l = mid + 1;
		else
			r = mid;
	}
	if (a[l] == x)
		return l;
	return -1;

}
int search_delete(int a[], int& n, int x)
{
	if (binSearch(a, n, x) != -1)
	{
		if (binSearch(a, n, x) == 0)
			deleteFirst(a, n);
		else if (binSearch(a, n, x) == n - 1)
			deleteLast(a, n);
		else
			deleteAt(a, n, binSearch(a, n, x));
		return 1;
	}
	return 0;
}
int main()
{
	int a[MAX];
	int n, x, opt;
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
			input(a, n);
			check = true;
			break;
		case 2:
			if (check)
			{
				display(a, n);
			}
			else
				cout << "Invalid!\n";
			break;
		case 3:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				if (binSearch(a, n, x))
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
				addHead(a, n, x);
			}
			else
				cout << "Invalid!\n";
			break;
		case 5:
			if (check)
			{
				deleteFirst(a, n);
				cout << "Delete Successfully!\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 6:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				addTail(a, n, x);
			}
			else
				cout << "Invalid!\n";
			break;
		case 7:
			if (check)
			{
				deleteLast(a, n);
				cout << "Delete Successfully!\n";
			}
			else
				cout << "Invalid!\n";
			break;
		case 8:
			if (check)
			{
				cout << "Type value x: ";
				cin >> x;
				if (search_delete(a, n, x))
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