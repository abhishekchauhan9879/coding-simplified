#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define null NULL
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;

class Node {
public:
	int data; Node* next;
	Node(int val) {
		this->data = val;
		this->next = NULL;
	}
};

void printLinkedList(Node* n) {
	while (n != NULL) {
		cout << n->data << "->"; n = n->next;
	}
	cout << "NULL" << endl;
}
int size(Node* head) {
	Node* temp = head;
	int c = 0;
	while (temp != null) {
		temp = temp->next;
		c++;
	}
	return c;
}
void insertAtHead(Node* &head, int val) {
	Node* temp = new Node(val);
	temp->next = head;
	head = temp;
}
void insertAtTail(Node* &head, int val) {
	if (head == NULL) {
		head = new Node(val); return;
	}
	Node* n = new Node(val);

	Node* temp = head;

	while (temp->next != null) {
		temp = temp->next;
	}

	temp->next = n;
}

void insertAtAnyIndex(Node* head , int data , int pos) {

	if (pos <= 1 and head == null) {
		insertAtHead(head, data);
		return;
	}

	if (pos >= size(head)) {
		insertAtTail(head, data);
		return;
	}

	int jump = 1;

	Node* temp = head;

	while (jump < pos - 1) {
		temp = temp->next; jump++;
	}

	Node* n = new Node(data);

	n->next = temp->next;
	temp->next = n;
}



void deleteAtHead(Node* &head) {
	if (head == null)	return;

	Node* toBeDeleted = head;
	head = head->next;
	delete toBeDeleted;
}
void deleteAtTail(Node* &head) {
	if (head == null)	return;

	Node* temp = head;

	while (temp->next->next != null) {
		temp = temp->next;
	}
	temp->next = NULL;
}
void deleteAtAnyIndex(Node* head , int pos) {

	if (pos <= 1 and head == null) {
		deleteAtHead(head); return;
	}

	if (pos >= size(head)) {
		deleteAtTail(head);
	}

	int jump = 1;

	Node* temp = head;
	while (jump < pos - 1) {
		temp = temp->next;
		jump++;
	}
	Node* toBeDeleted = temp->next;
	temp->next = temp->next->next;
	delete toBeDeleted;
}
Node* midPoint(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast->next != null and fast->next->next != null) {
		slow = slow->next; fast = fast->next->next;
	}
	return slow;
}
Node* detectCycle(Node* head) {

	if (head == null) {
		return null;
	}


	Node* slow = head;
	Node* fast = head;

	while (slow and fast->next and fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return slow;
		}
	}
	return null;
}

Node* startingPointOfCycle(Node* head) {

	Node* intersectionPoint = detectCycle(head);

	if (intersectionPoint == null) {
		return null;
	}

	Node* slow = head;
	while (slow != intersectionPoint) {
		slow = slow->next;
		intersectionPoint = intersectionPoint->next;
	}
	return slow;
}

void removeCycle(Node* head) {

	if (head == null) {
		return;
	}

	Node* startOfLoop = startingPointOfCycle(head);
	Node* temp = startOfLoop;

	while (temp->next != startOfLoop) {
		temp = temp->next;
	}
	temp->next = null;
}

int32_t main()
{
	Node* head = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		insertAtTail(head, k);
	}

	printLinkedList(head);
	//deleteAtTail(head);
	// insertAtAnyIndex(head,9,3);
	// printLinkedList(head);
	// deleteAtAnyIndex(head,3);
	// printLinkedList(head);


	cout << "size of LinkedList -> " << size(head) << endl;
	cout << "midpoint of LL is : " << midPoint(head)->data << endl;

	/* Create a loop for testing */
	head->next->next->next->next = head;
	(detectCycle(head) != null) ? cout << "Cycle Detected" : cout << "Cycle Not Detected";
	cout << endl;
	Node* cycleStartingPoint = startingPointOfCycle(head);
	cout << "Cycle starting at point : " << cycleStartingPoint->data << endl;
	removeCycle(head);
	printLinkedList(head);

	return 0;
}