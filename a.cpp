//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
	stack<char> s;
	char a;
	int si,check=0,check2;
	cin >> si;
	cin >> a;
	if(a == ')' || a == ']' || a == '}'){
		cout << "NO";
		return 0;
	}else{
		s.push(a);
		check2=1;
	}

	for(int i=0; i<si-2;i++){
			
		if(s.empty()){
			check++;
		}
		if(check2 == 1){
			check2 = 0;
		}
		cin >> a;
		if(a == '(' || a == '[' || a == '{'){
			s.push(a);
		}
		else if(a == ')'){
			if(s.empty() || s.top() != '('){
				cout << "NO";
				return 0;
			}
			else{
				s.pop();
			}
		}
		else if(a == ']'){
			if(s.empty() || s.top() != '['){
				cout << "NO";
				return 0;
			}
			else{
				s.pop();
			}
		}
		else if(a == '}'){
			if(s.empty() || s.top() != '{'){
				cout << "NO";
				return 0;
			}
			else{
				s.pop();
			}
		}
	}
	if(check == 0){
		cout << "NO";
	}else{
		cout << "YES";
	}

}
