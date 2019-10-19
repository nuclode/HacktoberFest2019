#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define M 1000000007
#define fi first
#define se second
#define inp(i, n, a) for(int i=0;i<n;i++) cin>>a[i];
#define int long long
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

Node *newNode(int data)
{
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push(Node **head_ref, int new_data)
{
	Node *new_node = newNode(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

Node *addTwoList(Node *first, Node *second)
{
	Node *res = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;
	
	while(first != NULL || second != NULL)
	{
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		carry = (sum>=10 ? 1 : 0);
		temp = newNode(sum%10);
		if(prev == NULL)
		res = temp;
		else
		prev->next = temp;
		prev = temp;
		if(first) first = first->next;
		if(second) second = second->next;
	}
	if(carry>0)
	temp->next = newNode(carry);
	return res;
}

void printList(Node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

signed main()
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

Node *res = NULL;
Node *first = NULL;
Node *second = NULL;

push(&first, 6);
push(&first, 4);
push(&first, 9);
push(&first, 5);
push(&first, 7);
cout << "First list is "; 
printList(first);

push(&second, 4);
push(&second, 8);
cout << "Second list is ";
 printList(second);

res = addTwoList(first, second);
cout << "Resultant list is "; 
printList(res);

return 0;
}

