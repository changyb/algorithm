#include <iostream>
using std::cout;
using std::endl;
static int count=0;

void Permutation(int columns[],int begin,int length){
	if(begin == length){
		bool isoutPut = true;
		for(int i=0;isoutPut&&i<length;i++){
			for(int j=0;j<length;j++){
				if(i!=j){
					if(i-j==columns[i]-columns[j] ||j-i == columns[i]-columns[j]){
						isoutPut = false;
						break;
					}
				}
			}
		}

		if(isoutPut){
			for(int i=0;i<length;i++){
				for(int j=0;j<length;j++){
					if(columns[i] == j)
						cout<<1;
					else
						cout<<' ';
				}
				cout<<endl;
			}
			cout<<endl;
			for(int i=0;i<length;i++)
				cout<<columns[i];
			cout<<endl;
			count++;
		}
	}
	else{
		for(int i = begin;i<length;i++){
			int temp = *(columns+i);
			*(columns+i) = *(columns+begin);
			*(columns+begin) = temp;
			Permutation(columns,begin+1,length);
			temp = *(columns+i);
			*(columns+i) = *(columns+begin);
			*(columns+begin) = temp;
		}

	}
}


void Eight_Queen(int columns[],int length){
	for(int i=0;i<length;i++){
		columns[i] = i;
	}

	Permutation(columns,0,length);
}

int main(int argc, char const *argv[])
{
	int columns[8];
	Eight_Queen(columns,8);

	cout<<"total:"<<count<<endl;
	return 0;
}