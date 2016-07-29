#include <iostream>
using std::cout;
using std::endl;

int MergeSort(int *data,int *tempData,int begin,int end){
	if(begin == end){
		tempData[begin] = data[begin];
		return 0;
	}

	int middle = (end+begin)/2;

	int left = MergeSort(data,tempData,begin,middle);
	int right = MergeSort(data,tempData,middle+1,end);


	int i = middle;
	int j = end;
    int k = end;
    int count = 0;
	while(i>=begin&&j>=(middle+1)){
		if(data[i] > data[j]){
			tempData[k] = data[i];
			i--;
			count += (j - middle);
		}
		else
		{
			tempData[k] = data[j];
			j--;
		}
		k--;
	}

	while(i>=begin)
		tempData[k--] = data[i--];

	while(j>=(middle+1))
		tempData[k--] = data[j--];

	for(int i=begin;i<=end;i++)
		data[i] = tempData[i];

	return count+left+right;

}


int InverseCount(int *data,int length){
	if(NULL == data || 0 == length)
		return -1;

	int *tempData = new int[length];
	int count = MergeSort(data,tempData,0,length-1);
	delete[] tempData;
	return count;
}


int main(int argc, char const *argv[])
{
	int array[] = {7,5,6,4};
	cout<<InverseCount(array,4)<<endl;
	return 0;
}


