#include<iostream>
#include<cmath>
using namespace std;

//dumb way
bool dumbIsPrime(int n){
	for(int i = 2; i <= n-1;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

/*vì mỗi số n không phải số nguyên tố đều có thể phân tích thành k1*k1 với k1 <= k2 nên k1*k1 <= k1*k2 = n
chính vì thế việc kiểm tra đến n là không cần thiết, ta chỉ nên kiểm tra đến sqrt(n)*/

bool littlebitCoolerIsPrime(int n){
	for(int i = 2; i <= sqrt(n);i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

/*ngoài ra số cũng là số nguyên tố nếu thỏa mãn 2 tính chất
1-Trừ số 2 mọi số nguyên tố đều là số lẻ
2-Trừ số 2 và số 3 mọi số nguyên tố đều có dạng 6k+(-)1 nếu là 6k+(-)2 thì chia hết cho 2 2k+3 chia hết cho 3...*/

//kiểm tra n có chia hết cho 2 3 hoặc các số có dạng 6k+(-)1 trong đoạn 5 đến sqrt(n)

bool coolerIsPrime(int n){
	if(n%2 == 0 || n%3 == 0){
		return false;
	}
	if(n == 2 || n == 3){
		return true;
	} 
	int k = -1;
	while(k <= sqrt(n)){
		k += 6;
		if(n % k == 0 || n%k+2 == 0){
			return false;
		}
	}
	return true;
}

//Định lý nhỏ fermat: nếu p là số nguyên tố và a là số tự nhiên thì a^p mod p = a
int main(){

}