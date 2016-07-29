#include <iostream>
using std::cout;
using std::endl;


bool VerifySequenceofBST(int *sequence,int length){
	if(NULL == sequence || length <=0)
		return false;

	int root = sequence[length-1];

	int i=0;
	while(i<length-1){
		if(sequence[i]>root)
			break;
		i++;
	}

	int j = i;
	while(j<length-1){
		if(sequence[i]<root)
			return false;
		j++;
	}

	bool left = true;
	if(i>0)
		left = VerifySequenceofBST(sequence,i);
	bool right = true;
	if(i<length-1)
		right = VerifySequenceofBST(sequence+i,length-i-1);

	return left&&right;
}