#include<iostream>
#include<stack>
using namespace std;


template <class T>
class Node {
public:
	Node<T>(int a) :value(a) {};
public:
	T value;
	Node* next;
};
template <typename T>
bool isParlindrome1(Node<T>* head)
{
	stack<Node<T>> s;
	Node<T>* cur = head;
	while (cur!=NULL)
	{
		s.push(*cur);
		cur = cur->next;
	}
	cur = head;
	bool flag = true;
	while (cur != NULL)
	{
		if (cur->value != s.top().value)
		{
			flag = false;
			break;
		}
		s.pop();
		cur = cur->next;
	}
	return flag;
}
template <typename T>
bool isParlindrome2(Node<T>* head)
{
	if (head == NULL || head->next == NULL) {
		return true;
	}
	Node<T>* right = head->next;
	Node<T>* cur = head;
	while (cur->next!=nullptr&&cur->next->next!=NULL) {
		right = right->next;
		cur = cur->next->next;
	}
	stack<Node<T>> s;
	while (right != NULL) {
		s.push(*right);
		right = right->next;
	}
	while (!s.isEmpty()) {
		if (head->value != s.top()->value) {
			return false;
		}
		head = head->next;
		s.pop();
	}
	return true;
}
template <typename T>
bool isParlindrome3(Node<T>* head) {
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	Node<T>* n1 = head;
	Node<T>* n2 = head;
	while (n2->next != NULL && n2->next->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next->next;
	}
	Node<T>* n3 = NULL;
	n2 = n1->next; // n2 -> right part first node
	n1->next = NULL; // mid.next -> null
	while (n2 != NULL) { // right part convert
		n3 = n2->next; // n3 -> save next node
		n2->next = n1; // next of right node convert
		n1 = n2; // n1 move
		n2 = n3; // n2 move
	}
	n3 = n1; // n3 -> save last node
	n2 = head;// n2 -> left first node
	bool res = true;
	while (n1 != NULL && n2 != NULL) { // check palindrome
		if (n1->value != n2->value) {
			res = false;
			break;
		}
		n1 = n1->next; // left to mid
		n2 = n2->next; // right to mid
	}
	n1 = n3->next;
	n3->next = NULL;
	while (n1 != NULL) { // recover list
		n2 = n1->nextnext;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return res;
}
template <typename T>
void printLinkList(Node<T> *head)
{
	Node<T> *cur = head;
	while (cur != NULL)
	{
		cout << cur->value << " ";
		cur = cur->next;
	}
	cout << endl;
}
int main()
{
	Node<int>* node1=new Node<int>(5);
	Node<int>* node2=new Node<int>(2);
	Node<int>* node3=new Node<int>(8);
	Node<int>* node6 = new Node<int>(8);
	Node<int>* node4=new Node<int>(2);
	Node<int>* node5=new Node<int>(5);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node6;
	node6->next = node4;
	node4->next = node5;
	node5->next = NULL;

	printLinkList(node1);
	cout<<"LinkList is Parlindrome1? :"<<isParlindrome1(node1) << endl;
	cout<<"LinkList is Parlindrome2? :"<<isParlindrome1(node1) << endl;
	cout<<"LinkList is Parlindrome3? :"<<isParlindrome1(node1) << endl;



	return 0;
}