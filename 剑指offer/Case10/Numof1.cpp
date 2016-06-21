#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//移位
int Numof1_1(int n){
	int i=1;
	int count=0;
	while(i){
		if((n&i) == i)
			++count;

		i=i<<1;
	}

	return count;
}

//n有多少个1，循环多少次
int Numof1_2(int n){
	int count=0;
	while(n){
		++count;
		n = (n-1)&n;
	}

	return count;
}

int main(){
	int n;
	cout<<"input:";
	while(cin>>n){
		cout<<"Numof1_1:"<<Numof1_1(n)<<endl;
		cout<<"Numof1_2:"<<Numof1_2(n)<<endl;
		cout<<"input:";
	}
	return 1;
}