#include <bits/stdc++.h>

using namespace std;

struct node 
{
	int data;
	node *next;
}

struct node *create(int x)
{
	node *temp = new node();
	temp->data = x;
	temp-next = NULL;

	return temp;
}

void insert(node *&head, int n)
{
	if (head == NULL)
	{
		head = create(n);

		return;
	}

	node *t = head;

	while (t->next != NULL)
	{
		t = t->next;
	}

	t->next = create(n)
}

int deleteNode(node *&head)
{
	if (head == NULL)
	{
		return 0;
	}

	node *temp = head;

	int value = head->data;

	head = head->next;

	delete temp;

	return value;
}

int digits(int n)
{
	int i = 1;

	if (n < 10)
	{
		return 1;
	}

	while (n > (int)pow(10, i))
	{
		i++;
	}

	return i;
}

void radixSort(vector<int> &arr)
{
	int size = arr.size();

	int max_value = *max_element(arr.begin(), arr.end());

	int d = digits(max_value);

	node **bins;

	bins = new node*[10];

	for (int i = 0; i < 10; i++)
	{
		bins[i] = NULL;
	}

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < size; j++)
		{
			insert(bins[(arr[j] / (int)pow(10, i)) % 10], arr[j]);
		}

		int x = 0;
		int y = 0;

		while (x < 10)
		{
			while (bins[x] != NULL)
			{
				arr[y++] = deleteNode(bins[x]);
			}

			x++;
		}
	}
}

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " " << endl;
	}
}

int main()
{
	vector<int> arr = {573, 25, 415, 12, 161, 6};

	radixSort(arr);
	printArray(arr);

	return 0;
}