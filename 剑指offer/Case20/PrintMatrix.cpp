#include <iostream>
using std::cout;
using std::endl;


void PrintMatrixInCircle(int **number,int columns,int rows,int start){
	int endX = columns-1-start;
	int endY = rows-1-start;

	for(int i=start;i<=endX;i++)
		cout<<number[start][i]<<'\t';

	if(start<endY){
		for(int i=start+1;i<=endY;i++){
			cout<<number[i][endX]<<'\t';
		}
	}

	if(start<endY&&start<endX){
		for(int i=endX-1;i>=start;i--)
			cout<<number[endY][i]<<'\t';
	}

	if(start<endX&&start<endY-1){
		for(int i=endY-1;i>start;i--)
			cout<<number[i][start]<<'\t';
	}
}

void PrintMatrixClock(int **number,int columns,int rows){
	if(NULL == number || columns == 0 || rows == 0){
		return;
	}

	int start = 0;
	while(columns>2*start && rows>2*start){
		PrintMatrixInCircle(number,columns,rows,start);
		++start;
	}
}


int main(int argc, char const *argv[])
{
	int **number=NULL;
	number = new int*[2];
	for(int i=0;i<2;i++){
		number[i] = new int[3];
	}
	
	int num = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			number[i][j] = num++;
		}
	}

	PrintMatrixClock(number,3,2);
	for(int i=0;i<2;i++){
		delete number[i];
	}
	delete[] number;
	return 0;
}