//////#define NDEBUG
////#include <cassert>
////#include <iostream>
////namespace MyLinkedList {
////    template <class T>
////    struct Node {
////        T        data;
////        Node<T>* next;  // 后续
////        Node<T>* prev;  // 前驱
////        Node(T _data, Node<T>* _next = NULL, Node<T>* _prev = NULL)
////            : data(_data), next(_next), prev(_prev) {}
////    };
////    template <class T>
////    struct LinkedList {
////        int      len;
////        Node<T>* head;
////        Node<T>* cache;
////        int      cachePosition;
////        LinkedList() : len(0), head(NULL), cache(NULL) {}
////        ~LinkedList() {
////            while (!empty()) {
////                erase(0);
////            }
////        }
////        Node<T>* find(int position) {
////            assert(position < len);
////            if (!cache)
////                cache = head, cachePosition = 0;
////            Node<T>* q;
////            int      cnt = 0;
////            int      _a = position - cachePosition, _b = position;
////            if (abs(_a) >= abs(_b)) {
////                q = head;
////                while (q->next != NULL && cnt++ != _b) {
////                    q = q->next;
////                }
////            } else {
////                q = cache;
////                if (_a < 0) {
////                    while (q->prev != NULL && cnt++ != _a) {
////                        q = q->prev;
////                    }
////                } else {
////                    while (q->next != NULL && cnt++ != _a) {
////                        q = q->next;
////                    }
////                }
////            }
////            return cache = q;
////        }
////        void Insert(T data, int position) {
////            assert(position <= len);
////            if (position == 0) {  // 头部插入
////                if (!head) {
////                    head = new Node<T>(data, NULL, NULL);
////                    ++len;
////                    return;
////                }
////
////                Node<T>* a = new Node<T>(data, head, NULL);
////                head->prev = a;
////                head       = a;
////            } else {
////                Node<T>* q = find(position - 1);
////                q->next    = new Node<T>(data, q->next, q);
////            }
////            ++len;
////        }
////        void push_back(T data) {
////            Insert(data, len);
////        }
////        void push_front(T data) {
////            Insert(data, 0);
////        }
////        void erase(int position) {
////            assert(position < len);
////            if (position == 0) {
////                if (len == 1) {
////                    head  = NULL;
////                    cache = NULL;
////                    --len;
////                    return;
////                }
////                head = head->next;
////                delete head->prev;
////                head->prev = NULL;
////            } else {
////                Node<T>* q = find(position - 1);
////                q->next    = q->next->next;
////                delete q->next->prev;
////                q->next->prev = q;
////            }
////            --len;
////        }
////        void pop_back() {
////            erase(len - 1);
////        }
////        void pop_front() {
////            erase(0);
////        }
////        T& operator[](int position) {
////            return find(position)->data;
////        }
////        int size() {
////            return len;
////        }
////        bool empty() {
////            return !len;
////        }
////        T& front() {
////            return find(len - 1)->data;
////        }
////        T& back() {
////            return find(0)->data;
////        }
////    };
////}  // namespace MyLinkedList
////
////int main() {
////    MyLinkedList::LinkedList<int> a;
////    a.push_back(1);
////    a.push_front(2);
////    a.pop_front();
////    a.pop_back();
////    //    a.pop_front();
////    a.push_front(12);
////    std::cout << a[0] << std::endl << a.size() << std::endl;
////}
//
//#define NDEBUG 0
//
//class Array;
//#include <cassert>
//
//namespace MyQueue {
//    template <class T, class Container = MyArray::Array<T> >
//    struct Queue {
//        Container a;
//        int head, tail;
//        Queue(int maxn) : a(maxn), head = 0, tail = 0 {
//            head = tail = 0;
//        }
//
//        Queue<T>& operator=(const Queue<T>& other) {
//            a       = other.a;
//            head    = other.head;
//            tail    = other.tail;
//        }
//
//        void pop() {
//            assert(!empty());
//            head = (head + 1) % maxSize;
//        }
//
//        void push(T data) {
//            assert((tail + 1) % maxSize != head);
//            a[tail] = data;
//            tail    = (tail + 1) % maxSize;
//        }
//
//        T& front() {
//            return a[head];
//        }
//
//        T& back() {
//            return a[tail];
//        }
//
//        int size() {
//            return (tail - head + maxSize) % maxSize;
//        }
//
//        bool empty() {
//            return head == tail;
//        }
//    };
//}  // namespace MyQueue
//
////
////#include <iostream>
////#include <cstdio>
////#include <ctime>
//// template <class T>
//// T gcdV1(T a, T b) {
////    T _temp;
////    while (b != 0) {
////        _temp = a;
////        a = b;
////        b = _temp % b;
////    }
////    return a;
////}
//// template <class T>
//// T gcdV2(T a, T b) {
////    while (a != b) {
////        int big = a > b?a:b;
////        int small = a < b?a:b;
////        a = big - small;
////        b = small;
////    }
////    return a;
////
////
////}
//// template <class T>
//// T gcdV3(T a, T b) {
////    long long _temp = 0;
////    while (a != b) {
////        int _aaa = a & 1, _bbb = b & 1;
////        if (_aaa == 0) {
////            if (_bbb == 0)
////                a >>= 1, b >>= 1, ++_temp;
////            else
////                a >>= 1;
////        } else {
////            if (_bbb == 0)
////                b >>= 1;
////            else {
////                int _big = a > b ? a : b, _small = a < b ? a : b;
////                a = _big - _small, b = _small;
////            }
////        }
////    }
////    return a << _temp;
////}
////
//// template <class T>
//// void swapa(T& a, T& b) {
////    T _temp = a;
////    a = b;
////    b = _temp;
////}
//// template <class T>
//// T gcdV4(T a, T b) {
////    long long r = 0;
////    while (true) {
////        if (!a || !b)
////            return (a + b) << r;
////        while ((a & 1) == 0 && (b & 1) == 0)
////            ++r, a >>= 1, b >>= 1;
////        while ((a & 1) == 0)
////            a >>= 1;
////        while ((b & 1) == 0)
////            b >>= 1;
////        if (a < b)
////            swapa(a, b);
////        a -= b;
////    }
////}
////
//// int main() {
////    std::cout << gcdV4(121310,5315353);
////    long long a, b;
////    system(R"(C:\Users\wzj\OneDrive\VScode\template-c\template_c.exe)");
////    freopen(R"(C:\Users\wzj\OneDrive\VScode\template-c\cmake-build-debug\.out)",
////    "r", stdin); std::cin >> a >> b; time_t t = clock();
////
////}
////
////// 1 1 2 3 5 8 13 21 34 55
////

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

template <class T>
struct BSTNode {
    T          data;
    int        h;
    BSTNode<T>*lchild, *rchild;
};
template <class T>
class AVLTree {
public:
    AVLTree()
        : root(NULL) {}
    ~AVLTree() {
        Release(root);
    }
    int Height() {
        return Height(root);
    }
    bool Insert(T x) {
        return Insert(root, x);
    }
    bool Remove(T x) {
        return Delete(root, x);
    }
    BSTNode<T>* Search(const T& x) {
        return Search(root, x);
    }
    bool Modify(const T& id, const T& x) {
        return Modify(root, id, x);
    }
    void PreOrder(void visit(const T& x)) {
        PreOrder(root, visit);
    }
    void InOrder(void visit(const T& x)) {
        InOrder(root, visit);
    }
    void PostOrder(void visit(const T& x)) {
        PostOrder(root, visit);
    }

private:
    BSTNode<T>* root;
    /*
	函数：释放bst树
	参数：树的根指针
	返回值：空
    */
    void        Release(BSTNode<T>* bst) {
        if (bst != NULL) {
            Release(bst->lchild);
            Release(bst->rchild);
            delete bst;
        }
    }
    /*
	函数：获取树的高度（树根高度为0）
	参数：bst：树的根指针
	返回值：树的高度
    */
    inline int Height(BSTNode<T>* bst) {
        return (bst == NULL ? -1 : bst->h);
    }
    /*
	函数：插入x
	参数：bst：树的根指针，进行调整的时候会修改其值，故用引用    x：要插入的值
	返回值：是否成功插入
    */
    bool Insert(BSTNode<T>*& bst, const T& x) {
        if (bst == NULL) {
            bst = new BSTNode<T>{ x, 0, NULL, NULL };
            if (bst == NULL) {
                cerr << "Out of Space !!!" << endl;
                exit(1);
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return true;
        } else if (x < bst->data) {
            bool r = Insert(bst->lchild, x);
            if (Height(bst->lchild) - Height(bst->rchild) == 2) {
                if (x < bst->lchild->data)
                    SingleRotateWithLeft(bst);
                else {
                    DoubleRotateWithLeft(bst);
                }
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return r;
        } else if (x > bst->data) {
            bool r = Insert(bst->rchild, x);
            if (Height(bst->lchild) - Height(bst->rchild) == -2) {
                if (x > bst->rchild->data)
                    SingleRotateWithRight(bst);
                else {
                    DoubleRotateWithRight(bst);
                }
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return r;
        } else {
            cout << "插入元素已经存在！！！" << endl;
            return false;
        }
    }

    /*
	    函数：删除值为x的节点
    	参数：bst：树根指针，进行调整的时候会修改其值，故用引用    x：要删除的值
    	返回值：是否成功删除
    */
    bool Remove(BSTNode<T>*& bst, const T& x) {
        if (bst == NULL) {
            cout << "删除元素不存在！！！" << endl;
            return false;
        } else if (x < bst->data) {
            bool r = Delete(bst->lchild, x);
            if (Height(bst->lchild) - Height(bst->rchild) == -2) {
                if (Height(bst->lchild) - Height(bst->rchild->rchild) == -1)
                    SingleRotateWithRight(bst);
                else
                    DoubleRotateWithRight(bst);
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return r;
        } else if (x > bst->data) {
            bool r = Delete(bst->rchild, x);
            if (Height(bst->lchild) - Height(bst->rchild) == 2) {
                if (Height(bst->lchild->lchild) - Height(bst->rchild) == 1)
                    SingleRotateWithLeft(bst);
                else
                    DoubleRotateWithLeft(bst);
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return r;
        } else {
            if (bst->lchild == NULL && bst->rchild == NULL) {
                delete bst;
                bst = NULL;
            } else if (bst->lchild != NULL && bst->rchild == NULL) {
                BSTNode<T>* p = bst;
                bst           = bst->lchild;
                delete p;
            } else if (bst->lchild == NULL && bst->rchild != NULL) {
                BSTNode<T>* p = bst;
                bst           = bst->rchild;
                delete p;
            } else {
                BSTNode<T>* p = bst->rchild;
                while (p->lchild != NULL) {
                    p = p->lchild;
                }
                bst->data = p->data;
                if (p == bst->rchild)  //特殊情况
                    bst->rchild = p->rchild;
                else {  //一般情况
                    bst->rchild->lchild = p->rchild;
                    bst->rchild->h      = max(Height(bst->rchild->lchild), Height(bst->rchild->rchild)) + 1;
                }
                delete p;
            }
            if (bst != NULL)
                bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return true;
        }
    }
    /*
    	函数：左单旋：即LL型
    	参数：bst：最小不平衡子树根指针
    	返回值：空
    */
    void SingleRotateWithLeft(BSTNode<T>*& bst) {
        BSTNode<T>* t = bst->lchild;
        bst->lchild   = t->rchild;
        t->rchild     = bst;

        bst->h        = max(Height(bst->lchild), Height(bst->rchild)) + 1;
        t->h          = max(Height(t->lchild), bst->h) + 1;
        bst           = t;
    }
    /*
        函数：右单旋：即RR型
        参数：bst：最小不平衡子树根指针
        返回值：空
    */
    void SingleRotateWithRight(BSTNode<T>*& bst) {
        BSTNode<T>* t = bst->rchild;
        bst->rchild   = t->lchild;
        t->lchild     = bst;

        bst->h        = max(Height(bst->lchild), Height(bst->rchild)) + 1;
        t->h          = max(bst->h, Height(t->rchild)) + 1;
        bst           = t;
    }
    /*
        函数：左双旋：即LR型
        参数：bst：最小不平衡子树根指针
        返回值：空
    */
    void DoubleRotateWithLeft(BSTNode<T>*& bst) {
        SingleRotateWithRight(bst->lchild);
        SingleRotateWithLeft(bst);
    }
    /*
        函数：右双旋：即RL型
        参数：bst：最小不平衡子树根指针
        返回值：空
    */
    void DoubleRotateWithRight(BSTNode<T>*& bst) {
        SingleRotateWithLeft(bst->rchild);
        SingleRotateWithRight(bst);
    }
    /*
        函数：搜索x
        参数：bst：根节点指针    x:要搜索的值，搜索成功后反回节点值
        返回值：搜索成功，返回指向该节点的指针；搜索失败返回NULL
    */
    BSTNode<T>* Search(BSTNode<T>* bst, const T& x) {
        if (bst == NULL)
            return NULL;
        else if (bst->data == x) {
            return bst;
        } else if (bst->data < x)
            return Search(bst->rchild, x);
        else
            return Search(bst->lchild, x);
    }
    /*
        函数：修改节点值
        参数：x：把节点值为id的节点的节点值修改为x
        返回值：是否成功修改
    */
    bool Modify(BSTNode<T>* bst, const T& id, const T& x) {
        Delete(id);
        Insert(x);
    }
    /*
        前序遍历
    */
    void PreOrder(BSTNode<T>* bst, void visit(const T& x)) {
        if (bst != NULL) {
            visit(bst->data);
            PreOrder(bst->lchild, visit);
            PreOrder(bst->rchild, visit);
        }
    }
    /*
        中序遍历
    */
    void InOrder(BSTNode<T>* bst, void visit(const T& x)) {
        if (bst != NULL) {
            InOrder(bst->lchild, visit);
            visit(bst->data);
            InOrder(bst->rchild, visit);
        }
    }
    /*
        后序遍历
    */
    void PostOrder(BSTNode<T>* bst, void visit(const T& x)) {
        if (bst != NULL) {
            PostOrder(bst->lchild, visit);
            PostOrder(bst->rchild, visit);
            visit(bst->data);
        }
    }
};

int main() {
    AVLTree<int> avlTree;
    avlTree.Insert(1);
    avlTree.Insert(3);
    cout << avlTree.Search(3)->h << endl;
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

/**
DataStructure
    PhysicalStructure
        Array
            Array.cpp*
            Array.hpp*
            Array.md*
        LinkedList
            LinkedList.cpp*
            LinkedList.hpp
            LinkedList.md*
        PhysicalStructure.md*
    LogicalStructure
        AVLTree
            AVLTree.cpp
            AVLTree.hpp
            AVLTree.md*
        Stack
            Stack.cpp*
            Stack.hpp
            Stack.md*
        RedBlackTree
            RedBlackTree.cpp
            RedBlackTree.hpp
            RedBlackTree.md*
        SegmentTree
            SegmentTree.cpp
            SegmentTree.hpp
            SegmentTree.md*
        Queue
            Queue.cpp
            Queue.hpp
            Queue.md*
        LogicalStructure.md*
Algorithm
    DP*
    GcdLcm*
        GcdLcm.cpp
        README.md*
    Algorithm.md*
README.md*


* = 占坑代填

*/