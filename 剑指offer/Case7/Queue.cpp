#include <iostream>
#include <stack>
#include <exception>
#include <cassert>
using std::cout;
using std::endl;
using std::stack;
using std::exception;

template <typename T> class CQueue{
	public:
		CQueue(){};
		~CQueue(){};

		void appendTail(const T& node);
		T deleteHead();

	private:
		stack<T> stack1;
		stack<T> stack2;
};


template<typename T> void CQueue<T>::appendTail(const T& node){
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead(){
	if(stack2.empty()){
		while(stack1.size()>0){
			T &t = stack1.top();
			stack1.pop();
			stack2.push(t);
		}
	}

	/*if(stack2.size() == 0)
		throw new exception("queue is empty");*/
	assert(stack2.size() != 0);

	T t = stack2.top();
	stack2.pop();

	return t;
}

int main(){
	CQueue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	cout<<q.deleteHead()<<endl;
	q.appendTail(4);
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	return 1;
}

