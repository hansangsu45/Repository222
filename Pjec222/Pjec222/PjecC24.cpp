#include<iostream>
using namespace std;

typedef struct linked {
	int data;
	struct linked* next;
}node;

node* head = NULL;
node* tail = NULL;

void Init()
{
	head = new node;
	head->data = 0;
	head->next = NULL;
	
	tail = head;
	return;
}

void Insert(node* ptr)
{
	node* newnode = new node;
	int num = 0;

	cout << "input number: ";
	cin >> num;

	newnode->data = num;
	newnode->next = NULL;

	ptr->next = newnode;
	tail = newnode;

	return;
}

void PrintList(node* ptr)
{
	node* view = ptr->next;

	while (view != NULL)
	{
		cout << view->data<<" ";
		view = view->next;
	}
	cout << endl;
	return;
}

void Modify(node* ptr)
{
	int index = 0;
	int num = 0;
	int i;

	cout << "input modify index: ";
	cin >> index;

	cout << "input modify data: ";
	cin >> num;

	for (i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	ptr->data = num;
	return;
}

void InsertData(node* ptr)
{
	node* newnode = new node;
	
	int index = 0, num = 0;
	int i;

	cout << "input InserdData index: ";
	cin >> index;

	cout << "input data: ";
	cin >> num;

	for (i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	newnode->data = num;
	newnode->next = NULL;

	if (ptr->next == NULL)
	{
		ptr->next = newnode;
		tail = newnode;
	}
	else {
		newnode->next = ptr->next;
		ptr->next = newnode;
	}
	return;
}

void Delete(node* ptr)
{
	node* temp = 0;
	int i;
	int index;

	if (head == tail) {
		cout << "not found data" << endl;
		return;
	}
	cout << "input delete index: ";
	cin >> index;

	for (i = 0; i < index - 1; i++)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	if (temp->next == NULL)
	{
		ptr->next = NULL;
		tail = ptr;
	}
	else {
		ptr->next = temp->next;
	}
	delete(temp);
	return;
}

int main()
{
	int menu = 0;

	Init();

	while (1) {
		cout << "1. 입력 2.출력 3.수정 4. 삽입 5.삭제 6. 종료" << endl;
		cout << "input menu: ";
		cin >> menu;

		switch (menu) {
		case 1:
			Insert(tail);
			break;
		case 2:
			PrintList(head);
			break;
		case 3:
			Modify(head);
			break;
		case 4:
			InsertData(head);
			break;
		case 5:
			Delete(head);
			break;
		case 6:
			break;
		default:
			cout << "select menu error.." << endl;
		}
		if (menu == 6) break;
	}
	return 0;
}