#include <iostream>
using std::cout;
using std::endl;

int GetMin(int first,int second,int third){
	int min = first>second?second:first;
	min = min>third?third:min;
	return min;
}

int GetUglyNumber(int index){
	if(index<=0)
		return -1;

	int *uglyNumber = new int[index];
	uglyNumber[0] = 1;
	int *max2 = uglyNumber;
	int *max3 = uglyNumber;
	int *max5 = uglyNumber;

	for(int i=1;i<index;i++){
		int min = GetMin((*max2)*2,(*max3)*3,(*max5)*5);
		uglyNumber[i] = min;

		while((*max2)*2<=min)
			max2++;

		while((*max3)*3<=min)
			max3++;

		while((*max5)*5<=min)
			max5++;
	}

	int number = uglyNumber[index-1];
	delete[] uglyNumber;
	return number;
}

int main(int argc, char const *argv[])
{
	cout<<GetUglyNumber(1500)<<endl;
	return 0;
}
