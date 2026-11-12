#include <iostream>
#include <string>
using namespace std;
int pos=0;
string input;

void E();
void EPrime();
void T();
void TPrime();
void F();

void E(){
	T();
	EPrime();
}

void EPrime(){
	if(input[pos]=='+'){
		pos++;
		T();
		EPrime();
}
}

void T(){
	F();
	TPrime();
}

void TPrime(){
	if(input[pos]=='*') {
		pos++;
		F();
		TPrime();
}
}

void F(){
	if(input[pos]=='i'){
		pos++;
		
	}
	else if(input[pos]=='('){
		pos++;
               E();
		if(input[pos]==')') pos++;
		else {
               cout<<"INValid";
			exit(0);
}
	}else{		cout<<"Invalid";
   exit(0);
	}
}

int main(){
	string s;
	cout<<"enter:";
	cin>>input;
        input+='$';
	
	E();
      if(input[pos]=='$') cout<<"valid";
      else cout<<"Invalid";

	return 0;
}