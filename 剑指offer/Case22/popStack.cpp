#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

bool IsPopStack(int pushArray[],int popArray[],int length){
	if(pushArray==NULL || popArray == NULL || length<=0)
		return false;

	stack<int> tStack;
	int i=0;
	int j=1;
	bool returnValue = true;
	tStack.push(pushArray[0]);

	while(i<length){
		while(tStack.top() != popArray[i] && j<length)
			tStack.push(pushArray[j++]);
		if(tStack.top() != popArray[i]){
			returnValue = false;
			break;
		}
		else{
			tStack.pop();
			i++;
		}
	}

	return returnValue;
}

int main(int argc, char const *argv[])
{
	int pushArray[]={1,2,3,4,5};
	int popArray1[]={4,5,3,2,1};
	int popArray2[]={4,3,5,1,2};
	cout<<IsPopStack(pushArray,popArray1,5)<<endl;
	cout<<IsPopStack(pushArray,popArray2,5)<<endl;
	return 0;
}