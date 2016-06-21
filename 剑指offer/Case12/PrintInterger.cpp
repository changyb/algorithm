#include <iostream>
using std::cout;
using std::endl;

void PrintNumber(char *numstr,int n){
	bool iszero = true;

	for(int i=0;i<n;i++){
		if(numstr[i]!='0')
			iszero = false;
		if(!iszero)
			cout<<numstr[i];
	}

	if(iszero)
		cout<<0;
	cout<<'\t';
}

void PrintIntegerRecursively(char *numstr,int index,int length){
	if(index == length){
		PrintNumber(numstr,length);
		return;
	}

	for(int i=0;i<10;i++){
		numstr[index]=i+'0';
		PrintIntegerRecursively(numstr,index+1,length);
	}
}


void PrintInteger(unsigned int n){
	if(n==0)
		return;
	char *numstr = new char[n];
	PrintIntegerRecursively(numstr,0,n);
	delete[] numstr;

}

int main(int argc, char const *argv[])
{
	PrintInteger(2);
	return 0;
}