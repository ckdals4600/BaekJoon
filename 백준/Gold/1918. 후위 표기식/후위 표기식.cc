#include <iostream>
#include <stack>
#include <map>

using namespace std;

string chagePostfix(string form) {
	string postFix = "";
	map<char, int> opPriority = { {'(',0}, {'*',1}, {'/',1},{'+',2},{'-',2} };
	stack<char> op;

	for (int i = 0; i < form.size(); i++) {
		char c = form[i];
		if (c == '(') {			
			op.push(c);
		}
		else if (c == ')') {
			while (op.top() != '(') {
				postFix += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (c == '*' || c == '/' || c == '+' || c == '-') {
			if (op.empty()) {
				op.push(c);
			}
			else {
				if (opPriority[c] < opPriority[op.top()]) {
					op.push(c);
				}
				else {
					while (!op.empty()) {
						if (opPriority[c] < opPriority[op.top()] || op.top() == '(') {
							break;
						}
						postFix += op.top();
						op.pop();
					}
					op.push(c);

				}
			}
		}
		else{
			postFix += c;
		}
	}

	while (!op.empty()) {
		postFix += op.top();
		op.pop();
	}

	return postFix;
}


int main() {
	string form;
	cin >> form;

	cout << chagePostfix(form);
	
	return 0;
}