#include <iostream>
#include <stack>
#include <cassert>
using std::cout;
using std::endl;
using std::stack;

template<class T> 
class MStack{
public:
	MStack(){};
	T GetMin();
	void Push(const T &t);
	void Pop();
private:
	stack<T> m_data;
	stack<T> m_min;
};

template<class T> T MStack<T>::GetMin(){
	assert(m_min.size()>0);
	return m_min.top();
}

template<class T> void MStack<T>::Push(const T &t){
	if(m_min.size() == 0 || t < m_min.top()){
		m_min.push(t);
	}
	else
		m_min.push(m_min.top());
	m_data.push(t);

}

template<class T> void MStack<T>::Pop(){
	assert(m_data.size()>0&&m_min.size()>0);
	m_data.pop();
	m_min.pop();
}

int main(int argc, char const *argv[])
{
	MStack<int> minStack;
	minStack.Push(3);
	cout<<minStack.GetMin()<<endl;
	minStack.Push(4);
	cout<<minStack.GetMin()<<endl;
	minStack.Push(2);
	cout<<minStack.GetMin()<<endl;
	minStack.Pop();
	cout<<minStack.GetMin()<<endl;
	minStack.Push(5);
	cout<<minStack.GetMin()<<endl;
	minStack.Pop();
	cout<<minStack.GetMin()<<endl;
	minStack.Push(1);
	cout<<minStack.GetMin()<<endl;
	return 0;
}