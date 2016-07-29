#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::multiset;
using std::cout;
using std::endl;
using std::greater;

typedef multiset<int, greater<int>> inSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const std::vector<int> &data,inSet &leastNumbers,int k){
	leastNumbers.clear();

	if(k<1 || data.size() < k)
		return;

	std::vector<int>::const_iterator iter = data.begin();
	for(;iter != data.end();iter++){
		if((leastNumbers.size()) < k)
			leastNumbers.insert(*iter);
		else
		{
			setIterator iterGreatest = leastNumbers.begin();
			if(*iter<*iterGreatest){
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}

		}
	}
}


int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);
	inSet leastNumbers;
	GetLeastNumbers(v,leastNumbers,4);
	setIterator iterGreatest = leastNumbers.begin();
	while(iterGreatest != leastNumbers.end()){
		cout<<*iterGreatest<<'\t';
		iterGreatest++;
	}
	cout<<endl;
	return 0;
}