#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

int pos=0;
string input;

void E();
void T();
void F();

void E(){
	T();
	while(input[pos]=='+'){
		pos++;
		T();
	}
}

void T(){
	F();
	while(input[pos]=='*'){
		pos++;
		F();
	}
}

void F(){
	if(input[pos]=='i') pos++;
	else if(input[pos]=='('){
		pos++;
		E();
		if(input[pos]==')') pos++;
		else{
			cout<<"Invalid";
			exit(0);
		}
		}

else{
			cout<<"Invalid";
			exit(0);
}
}

int main(){
    cout<<"enter";
	cin>>input;
input+='$';
E();
if(input[pos]=='$') cout<<"valid";
else cout<<"invalid";
return 0;
}		
