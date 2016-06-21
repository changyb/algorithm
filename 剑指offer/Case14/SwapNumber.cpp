#include <iostream>
using std::cout;
using std::endl;

void SwapNumber(int array[],int length){
	int begin = 0;
	int end = length-1;

	while(begin<=end){
		while((array[begin]&0x1)&&begin<=end){
			begin++;
		}

		while(!(array[end]&0x1)&&begin<=end){
			end--;
		}

		if(begin<=end){
			int temp = array[begin];
			array[begin] = array[end];
			array[end] = temp; 
		}

	}
}

int main(int argc, char const *argv[])
{
	int array1[]={1,2,3,4,5};
	int array2[]={3,7,9,4,2};
	SwapNumber(array1,5);
	SwapNumber(array2,5);

	for(int i=0;i<5;i++){
		cout<<array1[i]<<"\t";
	}
	cout<<endl;

	for(int i=0;i<5;i++){
		cout<<array2[i]<<"\t";
	}
	cout<<endl;
	return 0;
}

