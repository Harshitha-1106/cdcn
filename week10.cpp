#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

string div(string data,string gen){
	string temp=data;
	for(int i=0;i<temp.length()-gen.length();i++){
		if(temp[i]=='1'){
			for(int j=0;j<gen.length();j++){
				temp[i+j]=(temp[i+j]==gen[j])?'0':'1';
			}
		}
	}
return temp.substr(temp.length()-gen.length()+1);
}

int main(){
 string data,gen,padd,crc;
 cout<<"enter";
 cin>>data;

 string cc12="1100000001111";
 padd=data+string(12,'0');
 crc=div(padd,cc12);
 cout<<crc<<endl;
 string cc16="11000000000000101";
 padd=data+string(16,'0');
 crc=div(padd,cc16);
 cout<<crc<<endl;

   string ccit="10001000000100001";
 padd=data+string(16,'0');
 crc=div(padd,ccit);

 cout<<crc<<endl;
return 0;
}
