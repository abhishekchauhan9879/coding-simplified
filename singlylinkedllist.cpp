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

Node* reverseLL(Node* head) {
	if (head == null or head->next == null) {
		return head;
	}

	Node* curr = head;
	Node* prev = null;

	while (curr != null) {
		Node* nextNum = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNum;
	}
	return prev;
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

Node* reverseKnodes(Node* head, int k) {
	if (head == null || size(head) < k) {
		return head;
	}

	Node* curr = head;
	Node* prev = null;
	Node* nextNode = NULL;
	int count = 0;

	while (curr && count < k) {
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
		count++;
	}

	//recursion

	if (nextNode != null) {
		head->next = reverseKnodes(nextNode, k);
	}


	return prev;
}

bool isCircular(Node* head) {

	if (head == NULL or head->next == NULL) {
		return true;
	}

	Node* temp = head->next;

	while (temp != NULL and temp != head) {
		temp = temp->next;
	}
	if (temp == head) return true;

	return false;
}

Node* removeDuplicateFromSortedLL(Node* &head) {
	if (head == NULL || head->next == NULL)	return head;


	Node* curr = head;

	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			Node* next = curr->next->next;
			Node* toBeDeleted = curr->next;
			delete(toBeDeleted);
			curr->next = next;
		} else {
			curr = curr->next;
		}
	}
	return head;
}
Node* sortedMerge(Node* &a, Node* &b) {
	Node* result = NULL;


	if (a == null)	return b;
	if (b == null) return a;

	if (a->data <= b->data) {
		result = a;
		result->next = sortedMerge(a->next, b);
	} else {
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	return result;
}


Node* mergeSort(Node* &head) {
	if (head == null or head->next == null) {
		return head;
	}

	Node* mid = midPoint(head);
	Node* p = head;

	Node* q = mid->next;

	mid->next = null;

	p = mergeSort(p);
	q = mergeSort(q);

	Node* result = sortedMerge(p, q);
	return result;
}

Node* removeDuplicateFromUnsortedLL(Node* head) {

	Node* ptr = head;


	while (ptr->next) {

		Node* ptr1 = ptr;

		while (ptr1->next) {

			if (ptr->data == ptr1->next->data) {
				Node* toBeDeleted = ptr1->next;
				ptr1->next = ptr1->next->next;
				delete toBeDeleted;
			} else {
				ptr1 = ptr1->next;
			}
		}

		ptr = ptr->next;
	}
	return head;
}

bool isPalindrome(Node* head) {

	if (head == NULL or head->next == NULL)	return true;

	Node* mid = midPoint(head);

	Node* temp = mid->next;
	mid->next = reverseLL(temp);

	Node* h1 = head;
	Node* h2 = mid->next;

	while (h1 and h2) {
		if (h1->data != h2->data)	return false;

		h1 = h1->next; h2 = h2->next;
	}

	mid->next = reverseLL(temp);

	return true;
}
Node* reverserecursiveLL(Node* head) {
	if (head == NULL or head->next == NULL)	return head;

	Node* newHead = reverserecursiveLL(head->next);

	Node* headnext = head->next;
	headnext->next = head;
	head->next = NULL;

	return newHead;
}
Node* addtwoLL(Node* a1, Node* b1) {

	Node* result = NULL;

	Node* a = reverserecursiveLL(a1);
	Node* b = reverserecursiveLL(b1);

	int carry = 0;

	while (a != null and b != null) {
		int sum = (a->data + b->data) % 10;
		sum += carry;
		carry = (a->data + b->data) / 10;
		insertAtHead(result, sum);
		a = a->next;
		b = b->next;
	}

	while (a != null) {
		insertAtHead(result, a->data + carry);
		carry = a->data / 10;
		a = a->next;
	}
	while (b != null) {
		insertAtHead(result, b->data + carry);
		carry = b->data / 10;
		b = b->next;
	}

	if (carry > 0) {
		insertAtHead(result, carry) ;
	}

	return result;
}

Node* rotateList(Node* head, int k) {

	if (head == NULL)	return head;

	int n = 1;

	Node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
		n++;
	}

	k = k % n;
	if (k == 0)	return head;

	k = n - k;
	curr->next = head;
	while (k--)	curr = curr->next;

	head = curr->next;
	curr->next = NULL;


	return head;
}


int32_t main()
{
	Node* head = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		insertAtTail(head, k);
	}

	// cin >> n;
	// Node* head1 = NULL;
	// for (int i = 0; i < n; i++) {
	// 	int k; cin >> k;
	// 	insertAtTail(head1, k);
	// }
	int k; cin >> k;
	head = rotateList(head, k);
	//printLinkedList(head);
	// head = mergeSort(head);
	//head = removeDuplicateFromUnsortedLL(head);
	printLinkedList(head);
	//printLinkedList(head1);
	// head = reverserecursiveLL(head);
	// head1 = reverserecursiveLL(head1);
	// printLinkedList(head1);
	// printLinkedList(head);
	//cout << isPalindrome(head) << endl;
	//deleteAtTail(head);
	// insertAtAnyIndex(head,9,3);
	// printLinkedList(head);
	// deleteAtAnyIndex(head,3);
	// printLinkedList(head);
	//Node* res = addtwoLL(head, head1);
	//printLinkedList(res);

	// cout << "size of LinkedList -> " << size(head) << endl;
	// cout << "midpoint of LL is : " << midPoint(head)->data << endl;

	// /* Create a loop for testing */
	// head->next->next->next->next = head;
	// (detectCycle(head) != null) ? cout << "Cycle Detected" : cout << "Cycle Not Detected";
	// cout << endl;
	// Node* cycleStartingPoint = startingPointOfCycle(head);
	// cout << "Cycle starting at point : " << cycleStartingPoint->data << endl;
	// removeCycle(head);
	// printLinkedList(head);
	//printLinkedList(reverseLL(head));
	//printLinkedList(reverseKnodes(head, 3));

	//(isCircular(head)) ? cout << "Yes" : cout << "No";
	// head = removeDuplicateFromSortedLL(head);
	// printLinkedList(head);
	return 0;
}