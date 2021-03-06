#include "Stack.h"
#include "Static_stack.h"
#include <iostream>


int main() {
	
	Stack<int> s;

	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);

	std::cout << s << std::endl;
	
	s.pop();
	s.pop();
	
	std::cout << s << std::endl;

	NodeList<int> *top = s.top();
	std::cout << *top << std::endl;
	NodeList<int> *bot = s.bot();
	std::cout << *bot << std::endl;



	StaticStack<int> st_s(10);
	
	st_s.push(10);
	st_s.push(11);
	st_s.push(12);
	st_s.push(13);
	st_s.push(14);
	
	std::cout << st_s << std::endl;
	int ret = -1;
	ret = st_s.pop();
	ret = st_s.pop();
	ret = st_s.pop();
	ret = st_s.pop();

	std::cout << st_s << std::endl;

	ret = st_s.pop();
	
	std::cout << st_s << std::endl;

	ret = st_s.pop();
	ret = st_s.pop();
	
}