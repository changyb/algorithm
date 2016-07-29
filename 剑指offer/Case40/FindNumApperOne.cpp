#include <iostream>
using std::cout;
using std::endl;

void FindNumApperOne(int *array,int length,int &first,int &second){
	if(NULL== array || length <=1)
		return;

	int exclusiveOr = 0;
	for(int i=0;i<length;i++)
		exclusiveOr ^= array[i];

	int indexof1 = 0;

	while(!((exclusiveOr>>indexof1)&1)){
		indexof1++;
	}

    first = second =0;
	for(int i=0;i<length;i++){
		if(array[i] & (1<<indexof1)){
		
				first ^= array[i];
		}
		else{

				second ^= array[i];
		}
	}

}


int main(int argc, char const *argv[])
{
	//int array[] = {2,4,3,0,3,2,5,5};
	int array[] = {0,0,1,2};
	int first,second;
	FindNumApperOne(array,4,first,second);
	cout<<"first:"<<first<<" second:"<<second<<endl;
	return 0;
}