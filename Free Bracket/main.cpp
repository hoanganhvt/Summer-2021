#include<iostream>
#include<vector>
#include<set>
#include<sstream>
#include<string>

using namespace std;

struct var{
	int num;
	int sign;
};

var calSubSum(var arr[],int start,int end){
	var result;
	result.num = arr[start].num;
	result.sign = arr[start].sign;
	for(int i = start+1; i <= end;i++){
		result.num += (arr[i].num*arr[i].sign);
	}
	return result;
}

int stringToInt(string str){
	stringstream strToNum(str);
	int x = 0;
	strToNum >> x;
	return x;
}

string intToString(int x){
	string result;
	ostringstream toString;
	toString << x;
	result = toString.str();
	return result;
}
int solve(var arr[],int N){
	vector<vector<int>>allS;
	vector<int>tmp;
	tmp.push_back(0);
	allS.push_back(tmp);


	for(int i = 1; i <= N;i++){
		set<int>allSubS;

		for(int j = 1; j <= i;j++){
			var subS = calSubSum(arr,j,i);
			for(int k = 0; k < allS[j-1].size();k++){
				allSubS.insert(allS[j-1][k] + subS.num*subS.sign);
			}
		}

		vector<int>allSubSClone(allSubS.begin(),allSubS.end());
		allS.push_back(allSubSClone);
	}
	return allS[N].size();
}

string result = "";
void getInputAndSolve(){
	string seq;
	int N = 0;
	var arr[60];
	arr[1].sign = 1;
	char tmp[1];
	while(tmp[0] != '\n'){
		cin.read(tmp,1);

		if((tmp[0] == '+' || tmp[0] == '-') || tmp[0] == '\n'){
			N += 1;
			arr[N].num = stringToInt(seq);
			arr[N+1].sign = (tmp[0] == '+') ? 1 : -1;

			seq = "";
		}

		else{
			seq += tmp;
		}
	}
	cout << solve(arr,N) << endl;
}


int main(){
	getInputAndSolve();
	system("pause");
}