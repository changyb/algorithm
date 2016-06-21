#include <iostream>
using namespace std;


// 无法处理a[begin]=a[mid]=a[end]情况，比如1 0 1 1 1
int GetMin1(int a[],int length){
	if(NULL==a || 0==length){
		return -1;
	}

	int begin = 0;
	int end = length - 1;
	int mid = 0;

	while(a[begin]>=a[end]){
		if(end-begin == 1){
			mid = end;
			break;
		}

		mid = (begin+end)/2;

		if(a[begin]<=a[mid]){
			begin = mid;
		}
		else if(a[end]>=a[mid]){
			end = mid;
		}
	}

	return a[mid];
}

int GetMinByOrder(int a[],int begin,int end){
	int min = a[begin];

	for(int i=begin+1;i<=end;i++){
		if(min>a[i])
			min = a[i];
	}

	return min;
}


int GetMin2(int a[],int length){
	if(NULL==a || 0==length){
		return -1;
	}

	int begin = 0;
	int end = length - 1;
	int mid = 0;

	while(a[begin]>=a[end]){
		if(end-begin == 1){
			mid = end;
			break;
		}

		mid = (begin+end)/2;

		if(a[begin]== a[mid] && a[mid]==a[end])
			return GetMinByOrder(a,begin,end);

		if(a[begin]<=a[mid]){
			begin = mid;
		}
		else if(a[end]>=a[mid]){
			end = mid;
		}
	}

	return a[mid];
}

int main(){
	int a[]={4,5,6,7,8,1,2,3};
	int min = GetMin1(a,8);
    cout<<min<<endl;
    int b[]={1,0,1,1,1,1};
	min = GetMin2(b,6);
    cout<<min<<endl;
	return 1;
}
