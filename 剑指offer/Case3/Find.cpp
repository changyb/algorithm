#include <iostream>

bool Find(int *a, int rows, int columns, int target){
	bool isFind = false;
	if(NULL != a && rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1;
		while(row<rows && column>=0){
			if(a[row*columns+column]>target){
				column--;
				
			}
			else if(a[row*columns+column]<target){
				row++;
			}
			else{
				isFind = true;
				break;
			}
		}
	}

	return isFind;

}

int main(){
	using std::cout;
	using std::endl;
	int a[16] = {1,2,3,4,2,4,5,6,3,5,7,8,4,6,9,10};
	cout<<"9 in the array?:"<<Find(a,4,4,9)<<endl;
	cout<<"11 in the array?:"<<Find(a,4,4,11)<<endl;
	return 0;
}