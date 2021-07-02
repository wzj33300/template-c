#include <iostream>
#include "main.hpp"

using namespace std;
using namespace MySegmentTree;

int main() {
	int lll[] = {1,2,3,4,5,5};
	MySegmentTree::SegmentTree<> a(12345, lll);
	MySegmentTree::SegmentTree<long long> b(12345, {1,2,3,4,5,5});
	cout << endl;
	return 0;
}