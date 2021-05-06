#include<iostream>
using namespace std;

int fib(int N){
    const int Ns = N;
    int F[Ns];
    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i < N;i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[N-1];
}
int main(){

}