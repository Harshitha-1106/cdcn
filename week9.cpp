#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int main(){

string d;
cout<<"enter:";
cin>>d;

cout<<d.length()+1<<endl;

string stuff="FLAG",r;
r+=stuff;

for(char c:d){
	if(c=='F') r+=
"ESC";
	r+=c;
}
cout<<r<<endl;


string bits;
cout<<"enter";

cin>>bits;
string res="011110";
int count=0;
for(char c:bits){
  res+=c;
  if(c=='1') count++;
 else count=0;
  if(count==5) {
res+='0';
count=0;
}
 }
res+="011110";
cout<<res<<endl;
return 0;
}
