#include <iostream>
using std::cout;
using std::endl;

void PrintNumber(int small,int big){
	for(int i=small;i<=big;i++)
		cout<<i<<' ';
	cout<<endl;
}

void FindContinueSequence(int sum){
	if(sum<3)
		return;

	int small = 1;
	int big = 2;
	int middle = (sum+1)/2;
	int currentNum = small+big;

	while(small<middle){
		if(currentNum==sum)
			PrintNumber(small,big);

		while(currentNum>sum && small < middle){
			currentNum -= small;
			small++;
			if(currentNum == sum)
				PrintNumber(small,big);
		}

		big++;
		currentNum += big;
	}
}

int main(int argc, char const *argv[])
{
	FindContinueSequence(15);
	return 0;
}