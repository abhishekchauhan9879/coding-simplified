#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;



void printstack(stack<int> s) {

	while (!s.empty()) {
		int t = s.top();
		cout << t << " ";
		s.pop();
	}
}
void print1ton(int n) {

	if (n == 1) {
		cout << n << " ";
		return;
	}

	print1ton(n - 1);
	cout << n << " ";
}
void printnto1(int n) {
	if (n == 1) {
		cout << n << " "; return;
	}
	cout << n << " ";
	printnto1(n - 1);
}
void insert(vector<int> &v, int temp) {

	if (v.size() == 0 or v[v.size() - 1] <= temp) {
		v.push_back(temp);
		return;
	}

	int val = v[v.size() - 1];
	v.pop_back();
	insert(v, temp);
	v.push_back(val);
}
void sort(vector<int >&v) {

	if (v.size() == 1) {
		return ;
	}

	int temp = v[v.size() - 1];
	v.pop_back();
	sort(v);
	insert(v, temp);
}

void insertStack(stack<int>&s, int temp) {

	if (s.empty() or s.top() <= temp) {
		s.push(temp);
		return;
	}

	int val = s.top();
	s.pop();
	insertStack(s, temp);
	s.push(val);

}
void sortStack(stack<int> &s) {
	if (s.size() == 1) {
		return;
	}

	int temp = s.top();
	s.pop();
	sortStack(s);
	insertStack(s, temp);
}

void deletemidStack(stack<int>&s, int k) {
	if (k == 1) {
		s.pop();
		return;
	}

	int temp = s.top();
	s.pop();
	deletemidStack(s, k - 1);
	s.push(temp);
}
stack<int> deletemidStackElement(stack<int> &s) {
	if (s.size() == 0)	return s;

	int k = 1 + (s.size() / 2);

	deletemidStack(s, k);
	return s;
}

void reverseStackpush(stack<int> &s, int temp) {

	if (s.empty()) {
		s.push(temp);
		return;
	}

	int val = s.top();
	s.pop();

	reverseStackpush(s, temp);
	s.push(val);

}
stack<int> reverseStack(stack<int> &s) {

	if (s.size() == 1)	return s;

	int temp = s.top();
	s.pop();


	reverseStack(s);
	reverseStackpush(s, temp);
	return s;

}

int kthgrammer(int n, int k) {
	if (n == 1 and k == 1) {
		return 0;
	}

	int mid = pow(2, n - 1) / 2;

	if (k <= mid) {
		return kthgrammer(n - 1, k);
	}
	else {
		return !kthgrammer(n - 1, k - mid);
	}
}
void towerOfHanoi(int n, string s, string d, string h) {

	if (n == 0) {
		return;
	}

	towerOfHanoi(n - 1, s, h, d);
	cout << " Moving " << n << " from " << s << " to " << d << endl;
	towerOfHanoi(n - 1, h, d, s);

}
void printsubsequences(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << endl;
		return;
	}

	char choice = ip[0];

	string res = ip.substr(1);
	printsubsequences(res, op);
	printsubsequences(res, op + choice);

}

void helperPermutationWithSpaces(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << " " << endl;
		return;
	}

	char first_str = ip[0];

	string res = ip.substr(1);

	helperPermutationWithSpaces(res, op + first_str);
	helperPermutationWithSpaces(res, op + "_" + first_str );
}

void permutationwithspaces(string ip, string op) {

	op += ip[0];
	string res = ip.substr(1);
	helperPermutationWithSpaces(res, op);
}
void permutationCaseChange(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << endl;
		return;
	}
	permutationCaseChange(ip.substr(1), op + ip[0]);
	op.push_back(toupper(ip[0]));
	permutationCaseChange(ip.substr(1), op);
}
void permutationLetterChange(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << endl;
		return;
	}
	string op1 = op;
	if (isalpha(ip[0])) {

		op.push_back(tolower(ip[0]));
		permutationLetterChange(ip.substr(1), op );
		op1.push_back(toupper(ip[0]));
		permutationLetterChange(ip.substr(1), op1);
	} else {
		permutationLetterChange(ip.substr(1), op + ip[0]);
	}

}

void generateParenthesis(int open , int close, string op) {

	if (open == 0 and close == 0) {
		cout << op << endl;
		return;
	}

	if (open != 0) 	generateParenthesis(open - 1, close, op + "(");
	if (close > open) generateParenthesis(open, close - 1, op + ")");
}

void nthbitmore1(int ones, int zero , string op, int n) {

	if (n == 0) {
		cout << op << endl;
		return;
	}

	nthbitmore1(ones + 1, zero, op + "1", n - 1);

	if (zero < ones)	nthbitmore1(ones, zero + 1, op + "0", n - 1);

}

void solveJosephusProblem(vector<int>&v, int idx, int k, int& ans) {

	if (v.size() == 1) {
		ans = v[0];
		return;
	}

	idx = (idx + k) % (v.size());
	v.erase(v.begin() + idx);

	solveJosephusProblem(v, idx, k, ans);
}

int32_t main()
{

//	cout << kthgrammer(3, 2);

	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	//permutationwithspaces("ABC", "");
	// permutationCaseChange("ab", "");
	//permutationLetterChange("a1B2", "");
	//generateParenthesis(3, 3, "");
	//nthbitmore1(0, 0, "", 3);
	int ans = -1;
	int k = 2;
	solveJosephusProblem(v, 0, k - 1 , ans);
	cout << ans << endl;
	//towerOfHanoi(2, "A", "C", "B");
	//printsubsequences("abc", "");
	// int n; cin >> n;
	// print1ton(n);
	// cout << endl;
	// printnto1(n);
	// sort(v);
	// print(v);
	// stack<int> s;


	// s.push(1);
	// s.push(4);
	// s.push(2);
	// s.push(5);

	//sortStack(s);
	// printstack(s);
	// deletemidStackElement(s);
	// reverseStack(s);
	// cout << endl;
	// printstack(s);

	return 0;
}