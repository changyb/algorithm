#include <iostream>
using std::cout;
using std::endl;

int FindNumOfk(int *array,int length,int k){

	if(NULL == array || length <=0)
		return -1;

	int begin = 0;
	int end = length-1;
	int kbegin = -1;
	int kend = -1;

	while(begin <= end){
		int middle = (begin+end)/2;
		if(array[middle]>k)
			end = middle-1;
		else if(array[middle] < k)
			begin = middle+1;
		else{
			kbegin = middle;
			end = middle-1;
		}
	}

	begin = 0;
	end = length - 1;

	while(begin <= end){
		int middle = (begin+end)/2;
		if(array[middle]>k)
			end = middle-1;
		else if(array[middle] < k)
			begin = middle+1;
		else{
			kend = middle;
			begin = middle+1;
		}
	}

	if(kbegin>-1&&kend>-1)
		return kend-kbegin+1;

	return -1;
}

int main(int argc, char const *argv[])
{
	int array[] = {5};
	cout<<FindNumOfk(array,1,5)<<endl;
	return 0;
}