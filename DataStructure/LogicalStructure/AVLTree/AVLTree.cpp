#include "AVLTree.hpp"

using namespace std;

int main() {
    AVLTree<int> avlTree;
    int          a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80, 10 };
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        avlTree.Insert(a[i]);
    avlTree.Remove(10);
    //    avlTree.Insert(1);
    //    avlTree.Insert(3);
    //    cout << avlTree.Search(3)->h << endl;
    //    cout << avlTree.Height() << endl;
    //    avlTree.Insert(3);
    //    avlTree.Delete(3);
    //    avlTree.Modify(1, 2);
    avlTree.PreOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
    //    avlTree.Insert(7);
    //    avlTree.Insert(3);
    avlTree.InOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
    avlTree.PostOrder([](const int& x) -> void { cout << x << " "; });
    cout << endl;
}
