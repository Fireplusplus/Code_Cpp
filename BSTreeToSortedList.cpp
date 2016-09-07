#include <iostream>

using namespace std;

typedef struct BSNode
{
	int _key;
	BSNode* _left;
	BSNode* _right;

	BSNode(int key)
		: _key(key)
		, _left(NULL)
		, _right(NULL)
	{}
}Node;


void ToSortedList(Node* root, Node* &last)
{
	if (NULL == root)
		return;

	Node* cur = root;
	if (NULL != cur->_left)
		ToSortedList(cur->_left, last);

	cur->_left = last;
	if (NULL != last)
		last->_right = cur;
	last = cur;

	if (NULL != cur->_right)
		ToSortedList(cur->_right, last);
}

Node* CallToSortedList(Node* root)
{
	if (NULL == root)
		return NULL;

	Node *list = new Node(-1);;
	ToSortedList(root, list->_right);

	Node* head = list->_right;
	while (NULL != head->_left && head->_left != list)
	{
		head = head->_left;
	}

	delete list;

	return head;
}

void PrintList(Node* list)
{

	while (NULL != list)
	{
		cout << list->_key << " ";
		list = list->_right;
	}
	cout << endl;
}

int main()
{
	Node *t = new Node(5);
	t->_left = new Node(3);
	t->_right = new Node(7);

	Node *list = CallToSortedList(t);
	PrintList(list);

	return 0;
}