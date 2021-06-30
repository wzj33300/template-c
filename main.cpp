#include <iostream>
#include "main.hpp"

using namespace std;

int main() {
	MyStack::Stack<int> st(1000);
	st.push(1);
	st.push(2);
	cout << st.top();
}