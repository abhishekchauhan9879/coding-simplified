#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this -> data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* buildTree() {


	int data;
	cin >> data;
	Node*root;
	if (data == -1) {
		return NULL;
	}

	root = new Node(data);
	root->left = buildTree();
	root->right = buildTree();

	return root;

}
void preorderIterative(Node* root)
{
	if (root == NULL) {
		return;
	}

	stack<Node*> s;
	s.push(root);

	Node* curr = root;

	while (!s.empty()) {

		if (curr != NULL) {
			cout << curr->data << " ";

			if (curr->right != NULL) {
				s.push(curr->right);
			}

			curr = curr->left;
		}
		else {
			curr = s.top();
			s.pop();
		}

	}
}

void inorderIterative(Node* root) {

	if (root == NULL) {
		return;
	}

	stack<Node*> s;

	Node* curr = root;

	while (!s.empty() || curr != NULL) {

		if (curr) {
			s.push(curr);
			curr = curr->left;
		} else {

			curr = s.top();
			s.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}

	}
}
void postorderIterative(Node* root) {

	if (root == NULL) {
		return;
	}

	stack<Node*> s;

	Node* curr = root;

	while (!s.empty() or curr != NULL) {




	}
}

Node* Mirror(Node* root)
{
	if (root == NULL)
	{
		return root;
	}
	Node* l = Mirror(root->left);
	Node* r = Mirror(root->right);

	Node* temp = l;
	root->left = r;
	root->right = temp;
	return root;
}
void preorder(Node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if (root == NULL) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void levelordertraversal(Node* root) {

	if (root == NULL) {
		return;
	}

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		Node* temp = q.front();

		cout << temp->data << " ";
		q.pop();


		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}


}

pair<int, int> diameterfast(Node* root) {
	if (root == NULL) {
		pair<int, int> p = make_pair(0, 0);
		return p;
	}

	pair<int, int> l = diameterfast(root->left);
	pair<int, int> r = diameterfast(root->right);

	int op1 = l.first;
	int op2 = r.first;
	int op3 = l.second + r.second + 1;

	pair<int , int > ans;
	ans.first = max(op1, max(op2, op3));
	ans.second = 1 + max(l.second, r.second);

	return ans;
}

int diameter(Node* root) {
	// Your code here
	return diameterfast(root).first;
}
int sumTreeHelper(Node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	int leftsum = sumTreeHelper(root->left);
	int rightsum = sumTreeHelper(root->right);

	if (root->data != (leftsum + rightsum)) {
		return 0;
	}
	return leftsum + rightsum + root->data;
}
bool isSumTree(Node* root)
{
	// Your code here
	return sumTreeHelper(root);
}
bool isIdentical(Node *r1, Node *r2)
{
	//Your Code here
	if (r1 == NULL and r2 == NULL) {
		return true;
	}

	if (r2 == NULL or r1 == NULL) {
		return false;
	}
	if (r1->data != r2->data) {
		return false;
	}
	bool isleftidentical = isIdentical(r1->left, r2->left);
	bool isrightidentical = isIdentical(r1->right, r2->right);


	return isleftidentical && isrightidentical;
}
pair<bool, int> isBalancedHelper(Node* root) {
	if (root == NULL) {
		pair<bool, int> p = make_pair(true, 0);
		return p;
	}

	pair<int, int> l = isBalancedHelper(root->left);
	pair<int, int> r = isBalancedHelper(root->right);

	bool leftAns = l.first;
	bool rightAns = r.first;

	bool diff = abs(l.second - r.second) <= 1;

	pair<bool, int> ans ;

	ans.second = max(l.second, r.second) + 1;

	if (leftAns and rightAns and diff) {
		ans.first = true;
	} else {
		ans.first = false;
	}

	return ans;
}
bool isBalanced(Node *root)
{
	return isBalancedHelper(root).first;
}

void zigzagtraversal(Node* root) {

	if (root == NULL) {
		return ;
	}

	queue<Node*> q;
	q.push(root);
	bool leftToRight = true;

	while (!q.empty()) {
		int size = q.size();
		vector<int> res(size);
		int index;
		for (int i = 0; i < size; i++) {

			Node* curr = q.front();
			q.pop();

			(leftToRight) ? index = i : index = size - 1 - i;

			res[index] = curr->data;

			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}

		print(res);
		//when level changes
		leftToRight = !leftToRight;
		//result.push_back(res);
	}
	//return result;
}
void zigzagtraversalreverse(Node* root) {

	if (root == NULL) {
		return ;
	}

	queue<Node*> q;
	stack<int>s;
	q.push(root);
	bool leftToRight = false;

	while (!q.empty()) {
		int size = q.size();
		vector<int> res(size);
		int index;
		for (int i = 0; i < size; i++) {

			Node* curr = q.front();
			q.pop();

			(leftToRight) ? index = i : index = size - 1 - i;

			res[index] = curr->data;

			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		//print(res);
		for (auto i : res) {
			s.push(i);
		}
		//when level changes
		leftToRight = !leftToRight;
		//result.push_back(res);
	}
	//return result;
	while (!s.empty()) {
		cout << s.top() << " "; s.pop();
	}
}

void diagonalTraversal(Node* root) {

	if (!root) return ;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		Node* curr = q.front();
		q.pop();

		while (curr) {

			cout << curr->data << " ";

			if (curr->left) {
				q.push(curr->left);
			}

			curr = curr->right;
		}

	}
}

int sum = 0;
int sumOfLeftLeaves(Node* root) {
	if (!root)   return 0;
	if (root->left) {
		sumOfLeftLeaves(root->left);
		if (!root->left->left and !root->left->right) sum += root->left->data;
	}
	if (root->right) sumOfLeftLeaves(root->right);
	return sum;
}

void leftviewIterative(Node* root) {
	if (root == NULL)	return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		int n = q.size();

		for (int i = 0; i < n; i++) {
			Node* curr = q.front();
			q.pop();

			if (i == 0) {
				cout << curr->data << " ";
			}

			if (curr->left)	q.push(curr->left);

			if (curr->right)	q.push(curr->right);
		}
	}
}

void leftviewRecursive(Node* root, int level, int* maxLevel) {

	if (root == NULL)	return;

	if (*maxLevel < level) {
		cout << root->data << " ";
		*maxLevel = level;
	}

	leftviewRecursive(root->left, level + 1, maxLevel);
	leftviewRecursive(root->right, level + 1, maxLevel);
}
void rightviewRecursive(Node* root, int level, int* maxLevel) {

	if (root == NULL)	return;

	if (*maxLevel < level) {
		cout << root->data << " ";
		*maxLevel = level;
	}

	rightviewRecursive(root->right, level + 1, maxLevel);
	rightviewRecursive(root->left, level + 1, maxLevel);
}

void rightviewIterative(Node* root) {
	if (root == NULL)	return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		int n = q.size();

		for (int i = 1; i <= n; i++) {
			Node* curr = q.front();
			q.pop();

			if (i == n) {
				cout << curr->data << " ";
			}

			if (curr->left)	q.push(curr->left);

			if (curr->right)	q.push(curr->right);
		}
	}
}
vector<int> verticalOrder(Node *root)
{
	//Your code here
	vector<int> ans;
	if (root == NULL)  return ans;

	queue<pair<int , Node*>>q;
	map<int , vector<int>> nodes;

	q.push({0, root});

	while (!q.empty()) {

		Node* curr = q.front().second;
		int hd = q.front().first;
		q.pop();

		nodes[hd].push_back(curr->data);

		if (curr->left) {
			q.push(make_pair(hd - 1, curr->left));
		}
		if (curr->right) {
			q.push(make_pair(hd + 1, curr->right));
		}
	}

	for (auto x : nodes) {
		for (auto j : x.second) {
			ans.push_back(j);
		}
	}
	return ans;
}

void traverseLeft(Node* root, vector<int>& ans) {

	if ((root == NULL) or (root->left == NULL and root->right == NULL))   return;

	ans.push_back(root->data);
	if (root->left)
		traverseLeft(root->left, ans);
	else
		traverseLeft(root->right, ans);
}
void traverseRight(Node* root, vector<int>& ans) {

	if ((root == NULL) or (root->left == NULL and root->right == NULL))   return;

	if (root->right)
		traverseRight(root->right, ans);
	else
		traverseRight(root->left, ans);

	ans.push_back(root->data);
}

void traverseBoundary(Node* root , vector<int>& ans) {
	if (root == NULL)  return;

	if (root->left == NULL and root->right == NULL) {
		ans.push_back(root->data);
		return;
	}
	traverseBoundary(root->left, ans);
	traverseBoundary(root->right, ans);
}
vector <int> boundary(Node *root)
{
	//Your code here
	vector<int> ans;
	if (root == NULL)  return ans;

	ans.push_back(root->data);
	//left nodes print
	traverseLeft(root->left, ans);
	//boundary leaves

	traverseBoundary(root->left, ans);
	traverseBoundary(root->right, ans);
	//right nodes print
	traverseRight(root->right, ans);
	return ans;
}
vector<int> topView(Node *root)
{
	//Your code here
	vector<int> ans;
	if (root == NULL)  return ans;

	map<int, int> nodes;
	queue<pair<int, Node*>> q;

	q.push({0, root});

	while (!q.empty()) {
		Node* curr = q.front().second;
		int hd = q.front().first;
		q.pop();

		if (!nodes[hd])  nodes[hd] = curr->data;

		if (curr->left) {
			q.push({hd - 1, curr->left});
		}
		if (curr->right) {
			q.push({hd + 1, curr->right});
		}
	}

	for (auto x : nodes) {
		ans.push_back(x.second);
	}
	return ans;
}
vector <int> bottomView(Node *root) {
	// Your Code Here//Your code here
	vector<int> ans;
	if (root == NULL)  return ans;

	map<int, int> nodes;
	queue<pair<int, Node*>> q;

	q.push({0, root});

	while (!q.empty()) {
		Node* curr = q.front().second;
		int hd = q.front().first;
		q.pop();

		nodes[hd] = curr->data;

		if (curr->left) {
			q.push({hd - 1, curr->left});
		}
		if (curr->right) {
			q.push({hd + 1, curr->right});
		}
	}

	for (auto x : nodes) {
		ans.push_back(x.second);
	}
	return ans;
}
//*************************** maximum sum of root to leaf path*****************
void solveSumOfLongRootToLeafPath(Node* root, int len, int summ, int &maxLen, int &maxSum) {

	if (root == NULL) {
		if (len > maxLen) {
			maxLen = len;
			maxSum = summ;
		} else if (len == maxLen) {
			maxSum = max(maxSum, summ);
		}
		return;
	}

	summ = summ + root->data;
	solveSumOfLongRootToLeafPath(root->left, len + 1, summ, maxLen, maxSum);
	solveSumOfLongRootToLeafPath(root->right, len + 1, summ, maxLen, maxSum);
}
int sumOfLongRootToLeafPath(Node *root)
{
	//code here
	if (root == NULL)  return 0;
	int maxLen = 0, maxSum = INT_MIN;
	solveSumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
	return maxSum;
}
//*****************Lowest Common Ancestor**********************
Node* lca(Node* root , int n1 , int n2 )
{
	//Your code here
	if (root == NULL)   return root;

	if (root->data == n1 || root->data == n2) return root;

	Node* leftAns = lca(root->left, n1, n2);
	Node* rightAns = lca(root->right, n1, n2);

	if (leftAns && rightAns)  return root;
	else if (!leftAns && rightAns) return rightAns;
	else if (leftAns && !rightAns) return leftAns;
	else if (!leftAns && !rightAns ) return NULL;
}
//******************************K Sum Paths*********************
void solveSumk(Node* root, int k, int &count, vector<int> paths) {
	if (root == NULL)    return ;

	paths.push_back(root->data);

	solveSumk(root->left, k, count, paths);
	solveSumk(root->right, k, count, paths);

	int sum = 0;
	for (int i = paths.size() - 1; i >= 0; i--) {
		sum += paths[i];
		if (sum == k)    count++;
	}
	paths.pop_back();
}
int sumK(Node *root, int k)
{
	// code here
	vector<int> paths;
	int count = 0;
	solveSumk(root, k, count, paths);
	return count;
}
//*********************kth ancestor**************************
Node* solveKthAncestor(Node* root, int &k, int node) {
	if (root == NULL)   return root;

	if (root->data == node) {
		return root;
	}
	Node* leftAns = solveKthAncestor(root->left, k, node);
	Node* rightAns = solveKthAncestor(root->right, k, node);

	if (leftAns != NULL && rightAns == NULL) {
		k--;
		if (k <= 0) {
			k = INT_MAX;
			return root;
		}
		return leftAns;
	}
	if (leftAns == NULL && rightAns != NULL) {
		k--;
		if (k <= 0) {
			k = INT_MAX;
			return root;
		}

		return rightAns;
	}
	return NULL;
}


int kthAncestor(Node *root, int k, int node)
{
	// Code here
	Node* ans = solveKthAncestor(root, k, node);
	if (ans == NULL or ans->data == node)   return -1;
	else {
		return ans->data;
	}
}

Node* solvePostIn(int in[], int post[], int& idx, int is, int es, map<int, int>&mymap) {
	if (idx < 0 || is > es) {
		return NULL;
	}
	int element = post[idx--];
	Node* root = new Node(element);
	int pos = (mymap.find(element) != mymap.end()) ? mymap[element] : -1;

	root->right = solvePostIn(in, post, idx, pos + 1, es, mymap);
	root->left = solvePostIn(in, post, idx, is, pos - 1, mymap);

	return root;

}
Node *buildTreePostIn(int in[], int post[], int n) {
	// Your code here
	int postIdx = n - 1;
	map<int, int> mymap;
	for (int i = 0; i < n; i++) {
		mymap[in[i]] = i;
	}
	Node* ans = solvePostIn(in, post, postIdx, 0, n - 1, mymap);
	return ans;
}
Node* solvePreIn(int in[], int pre[], int& idx, int is, int es, int n, map<int, int>&mymap) {
	if (idx >= n || is > es) {
		return NULL;
	}
	int element = pre[idx++];
	Node* root = new Node(element);
	int pos = (mymap.find(element) != mymap.end()) ? mymap[element] : -1;

	root->left = solvePreIn(in, pre, idx, is, pos - 1, n, mymap);
	root->right = solvePreIn(in, pre, idx, pos + 1, es, n, mymap);
	return root;

}
Node* buildTreePreIn(int in[], int pre[], int n)
{
	// Code here
	int preorderIdx = 0;
	map<int, int> mymap;
	for (int i = 0; i < n; i++) {
		mymap[in[i]] = i;
	}
	Node* ans = solvePreIn(in, pre, preorderIdx, 0, n - 1, n, mymap);
	return ans;
}

/************************Burn A Tree********************************/

Node* createMapping(map<Node*, Node*>& NodeToParent, int target, Node* root) {

	if (root == NULL)    return root;

	Node* res = NULL;

	queue<Node*> q;
	q.push(root);
	NodeToParent[root] = NULL;

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		if (front->data == target) {
			res = front;
		}
		if (front->left) {
			NodeToParent[front->left] = front;
			q.push(front->left);

		}
		if (front->right) {

			NodeToParent[front->right] = front;
			q.push(front->right);
		}
	}
	return res;
}
int burnTree(Node* root, map<Node*, Node*>& NodeToParent) {

	map<Node*, bool> visited;

	int ans = 0;

	queue<Node*> q;
	q.push(root);
	visited[root] = 1;

	while (!q.empty()) {
		bool flag = false;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* front = q.front();

			q.pop();

			if (front->left && !visited[front->left]) {
				flag = 1;
				q.push(front->left);
				visited[front->left] = 1;
			}
			if (front->right && !visited[front->right]) {
				flag = 1;
				q.push(front->right);
				visited[front->right] = 1;
			}

			if (NodeToParent[front] && !visited[NodeToParent[front]]) {
				flag = 1;
				q.push(NodeToParent[front]);
				visited[NodeToParent[front]] = 1;
			}

		}
		if (flag) {
			ans++;
		}


	}
	return ans;
}
int minTime(Node* root, int target)
{
	// Your code goes here
	map<Node*, Node*> NodeToParent;

	Node* targetNode = createMapping(NodeToParent, target, root);

	int ans = burnTree(targetNode, NodeToParent);
	return ans;
}
//*********************************BT INTO SUM TREE***********
int btIntoSumTree(Node* root) {
	if (!root)	return 0;

	int old_data = root->data;

	root->data = btIntoSumTree(root->left) + btIntoSumTree(root->right);

	return root->data ;
}
//***********************Largest SubTree Sum**************

int LargestSubtreeSum(Node* root, int &mx)
{
	if (root == NULL) return 0;
	int l = LargestSubtreeSum(root->left, mx);
	int r = LargestSubtreeSum(root->right, mx);
	int x = l + r + root->data;
	mx = max(mx, x);
	return x;

}
//******************Tree Isomorphism*****************
bool isIsomorphic(Node *root1, Node *root2)
{
	//add code here.
	if (root1 == NULL and root2 == NULL) return true;
	if (root1 == NULL || root2 == NULL) return false;

	if (root1->data != root2->data)    return false;

	bool isnotFlipped = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
	bool isFliped = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

	return isnotFlipped || isFliped;
}
//******************Nodes at Kth distance from root****************
void NodeAtKthDist(Node* root, int k) {
	if (k == 0 )	{

		(root) ? cout << root->data : cout << "Sorry Root is not Present";
		cout << endl;
		return ;
	}
	queue<Node* >q;
	q.push(root);
	while (!q.empty() && k != 0) {
		bool flag = false;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* curr = q.front();
			q.pop();
			if (curr->left) {
				flag = true;
				q.push(curr->left);
			}
			if (curr->right) {
				flag = true;
				q.push(curr->right);
			}
		}
		if (flag) {
			k = k - 1;
		}
	}
	while (!q.empty()) {
		cout << q.front()->data << " ";
		q.pop();
	}
	cout << endl;
}
//******************** Two sum***************************

int SumTree(Node* root, int target) {
	if (root == NULL)	return 0;

	queue<Node*> q;
	q.push(root);
	return 0;
}
//************************ Populate Next Pointer *********************
//Link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Node* connect(Node* root) {
// 	if (!root)   return root;

// 	queue<Node*> q;
// 	q.push(root);
// 	while (!q.empty()) {
// 		int n = q.size();

// 		for (int i = 0; i < n; i++) {
// 			Node* curr = q.front();
// 			q.pop();
// 			if (i == n - 1)   curr->next = NULL;
// 			if (!(i == n - 1))curr->next = q.front();
// 			if (curr->left) {
// 				q.push(curr->left);
// 			}
// 			if (curr->right) {
// 				q.push(curr->right);
// 			}
// 		}
// 	}
// 	return root;
// }
//************************** Cousins in Binary Tree *******************
void solve(Node* root , int a, int b, map<int , int>& depth, map<int, Node*>& nodeToParent) {
	if (root == NULL)  return ;

	queue<Node*> q;
	q.push(root);
	int level = 0;
	while (!q.empty()) {
		int n = q.size();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			Node* curr = q.front();
			q.pop();

			depth[curr->data] = level;

			if (curr->left) {
				flag = true;
				nodeToParent[curr->left->data] = curr;
				q.push(curr->left);
			}
			if (curr->right) {
				flag = true;
				nodeToParent[curr->right->data] = curr;
				q.push(curr->right);
			}
		}
		if (flag)    level++;
	}
}
bool isCousins(Node *root, int a, int b)
{
	map<int , int> depth;
	map<int, Node*> nodeToParent;

	solve(root, a, b, depth, nodeToParent);
	return (depth[a] == depth[b]) && (nodeToParent[a] != nodeToParent[b]);
}
//******************************* Cousins in Binary Tree******************88
vector<int> solveCousin(Node* A, int B) {
	vector<int> ans;
	if (A == NULL ) {
		return ans;
	}

	queue<Node*> q;
	q.push(A);
	map<int, Node*> nodesToParent;
	nodesToParent[A->data] = NULL;
	bool flag = 0;
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* curr = q.front();
			q.pop();

			if ((curr->left && curr->left->data == B) || (curr->right && curr->right->data == B)) flag = 1;
			else {
				if (curr->left)  q.push(curr->left);
				if (curr->right)  q.push(curr->right);
			}

		}
		if (flag) {
			while (!q.empty()) {
				ans.push_back(q.front()->data);
				q.pop();
			}
			return ans;
		}
	}
	return ans;

}
//******************************* Path to given Node*******************
bool hasPath(Node* root, int B, vector<int>& ans) {
	if (!root)   return false;

	ans.push_back(root->data);

	if (root->data == B)    return true;

	if (hasPath(root->left, B, ans) || hasPath(root->right, B, ans))    return true;

	ans.pop_back();
	return false;

}
vector<int> solvePathToGivenNode(Node* root, int B) {
	vector<int> ans;
	hasPath(root, B, ans);
	return ans;
}
//******************************* Remove Half nodes**********************
Node* removehalfNodes(Node* root) {
	if (!root)	return NULL;

	if (root->left && root->right) {
		root->left = removehalfNodes(root->left);
		root->right = removehalfNodes(root->right);
	}
	else if (root->left)	root = removehalfNodes(root->left);
	else if (root->right)	root = removehalfNodes(root->right);
	return root;
}
//*******************************Merge two BT******************************
Node* mergeTrees(Node* root1, Node* root2) {
	if (!root1 and !root2)    return nullptr;

	if (root1 && !root2)  return root1;

	if (!root1 && root2) return root2;

	Node* root = new Node(root1->data + root2->data);

	root->left = mergeTrees(root1->left, root2->left);
	root->right = mergeTrees(root1->right, root2->right);

	return root;
}
//************************************************************************
int32_t main()
{

	//int pre[] = {1, 2, 3, 4, 6};
	//{8, 4, 5, 3, 2, 9, 40, 10};
	//int in[] = {2, 1, 4, 3, 6};
	//{5, 4, 3, 8, 40, 9, 2, 10};
	//int post[] = {5, 3, 4, 40, 9, 10, 2, 8};
	//int pos = 0;
	//Node* root = buildTreePreIn(in, pre, 5);
	//Node* root = buildTreePostIn(in, post, 8);
	//cout << "Minimum Time to burn Tree : " << minTime(root, 1) << endl;
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	// root->left->left = new Node(4);
	// root->left->right = new Node(5);
	root->right->left = new Node(4);
	root->right->left->right = new Node(5);
	//root->right->left->left = new Node(40);

	preorder(removehalfNodes(root));
	// vector<int> arr;
	// pathToGivenNode(root, arr, 2);
	// print(arr);
	// print(solveCousin(root, 5));
	// NodeAtKthDist(root, 4);
	// int mx = 0;
	// LargestSubtreeSum(root, mx\);
	// cout << mx;
	//cout << btIntoSumTree(root);
	//preorder(temp);
	cout << endl;
	//creating a Tree
	// root = buildTree();

	//root = buildTree(root);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	cout << "Left view Iterative: " << endl;
	leftviewIterative(root);
	cout << endl << "Left view Recursive: " << endl;
	int maxLevel = 0;
	leftviewRecursive(root, 1, &maxLevel);
	cout << endl << "right view Iterative: " << endl;
	rightviewIterative(root);
	cout << endl << "right view Recursive: " << endl;
	maxLevel = 0;
	rightviewRecursive(root, 1, &maxLevel);

	//cout << endl << "Level Order Traversal :" << endl;
	// levelordertraversal(root);
	// cout << endl;
	// cout << "Preorder Iterative :" << endl;
	// preorderIterative(root);
	// cout << endl;
	// cout << "Inorder Iterative :" << endl;
	// inorderIterative(root);
	// cout << endl;
	// cout << "Diameter of tree is : " <<  diameter(root) << endl;
	// // int t = 1;
	// //cin>>t;
	// cout << "Zig Zag Traversal : " << endl;
	// zigzagtraversal(root);
	// cout << "Zig Zag Traversal Reverse: " << endl;
	// zigzagtraversalreverse(root);
	// cout << endl;
	// cout << "diagonalTraversal : " << endl;
	// diagonalTraversal(root);
	// cout << endl;

	return 0;
}