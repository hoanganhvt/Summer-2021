#include<iostream>
using namespace std;

string addition(string a,string b){
	string result;
	while(a.length() < b.length()){
		a = '0'+a;
	}
	while(b.length() < a.length()){
		b = '0'+b;
	}
	int carry = 0;
	for(int i = a.length()-1; i >= 0;i--){
		int x,y;
		x = a[i]-'0';
		y = b[i]-'0';
		int s = x+y+carry;
		carry = s/10;
		result = (char)(48+s%10) + result;
	}
	return result;
}

string substraction(string a,string b){
	string result = "";
	while(a.length() < b.length()){
		a = '0'+a;
	}
	while(b.length() < a.length()){
		b = '0'+b;
	}

	int carry = 0;
	for(int i = a.length()-1;i >= 0;i--){
		int s = (a[i]-'0')-(b[i]-'0')-carry;
		if(s < 0){
			s = s+10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		result = (char)(s+48)+result;
	}
	return result;
}
int main(){
	cout << substraction("1000","99") << endl;
	system("pause");
}