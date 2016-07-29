#include <iostream>
using std::cout;
using std::endl;

bool isIputValied = true;

int GetMaxSeqValue(int array[],int length){
	if(NULL == array || length <=0){
		isIputValied = false;
		return 0;
	}

	int currentMax = 0;
	int nGreatNum = 0x80000000;
	for(int i=0;i<length;i++){
		if(currentMax<=0)
			currentMax = array[i];
		else
			currentMax += array[i];

		if(currentMax > nGreatNum)
			nGreatNum = currentMax;
	}

	isIputValied = true;
	return nGreatNum;
}


int main(int argc, char const *argv[])
{
	int array[] = {1,-2,3,10,-4,7,2,-5};
	cout<<GetMaxSeqValue(array,8);
	return 0;
}