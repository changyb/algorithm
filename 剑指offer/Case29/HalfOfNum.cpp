#include <iostream>
using std::cout;
using std::endl;

bool isPass = true;

void swap(int &a,int &b){
	if(a==b)
		return;

	a = a^b;
	b = a^b;
	a = a^b;
}

int Partition(int array[],int begin,int end){
	int temp = array[0];
	int low = begin;
	for(int high=begin+1;high<=end;high++){
		if(array[high]<=temp){
			low++;
			swap(array[low],array[high]);
		}
	}
	
	swap(array[low],array[begin]);
	return low; 
}

int IsOverHalf(int array[],int length,int value){
	int count = 0;
	for(int i=0;i<length;i++){
		if(array[i] == value)
			count++;
	}

	if(count*2<=length){
		isPass = false;
		return 0;
	}

    isPass = true;
	return value;
}


int HalfOfNum(int array[],int length){
	if(NULL == array || length <=0){
		isPass = false;
		return 0;
	}

	int result = array[0];
	int count = 1;

	for(int i=1;i<length;i++){
		/*if(count == 0){
			result = array[i];
			count = 1;
		}
		else if(array[i] == result){
			count++;
		}
		else
			count--;*/

		if(array[i] == result){
			count++;
		}
		else{
			count--;
			if(count == 0){
			result = array[i];
			count = 1;
		}
		}
	}

	return IsOverHalf(array,length,result);
}



int HalfOfNum1(int array[],int length){
	if(NULL == array || length <=0){
		isPass = false;
		return 0;
	}

	int begin = 0;
	int end = length-1;
	int middle = length>>1;

	int index = Partition(array,begin,end);

	while(index!=middle){
		if(index<middle){
			begin = index+1;
			index = Partition(array,begin,end);
		}
		else{
			end = index-1;
			index = Partition(array,begin,end);
		}
	}


	return IsOverHalf(array,length,array[index]);
}


int main(int argc, char const *argv[])
{
	int array[] = {1,3,2,2,2,2,5};
	int array1[] = {1,2,3,2,2,2,5,2,6};
	int array2[] = {1,2,3,4};

	cout<<"array:";
	cout<<HalfOfNum(array,7)<<" "<<HalfOfNum1(array,7)<<endl;

	cout<<"array1:";
	cout<<HalfOfNum(array1,9)<<" "<<HalfOfNum1(array1,9)<<endl;

	cout<<"array2:";
	cout<<HalfOfNum(array2,4)<<" "<<HalfOfNum1(array2,4)<<endl;
	return 0;
}