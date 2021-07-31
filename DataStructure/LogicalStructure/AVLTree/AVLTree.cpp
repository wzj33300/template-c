#include "AVLTree.hpp"

using namespace std;

int main() {
    AVLTree<int> avlTree;
    avlTree.Insert(1);
    avlTree.Insert(3);
    cout << avlTree.Search(3) -> h << endl;
    cout << avlTree.Height() << endl;
    avlTree.Delete(3);
    avlTree.Modify(1, 2);
    avlTree.PreOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
    avlTree.Insert(7);
    avlTree.Insert(3);
    avlTree.InOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
    avlTree.PostOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
}
