#include <algorithm>
#include <cstdlib>
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
    bool Delete(T x) {
        return Delete(root, x);
    }
    bool Search(T& x) {
        return !(Search(root, x) == NULL);
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
    template <class T>
    void Release(BSTNode<T>* bst) {
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
    template <class T>
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
    template <class T>
    bool Delete(BSTNode<T>*& bst, const T& x) {
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
    template <class T>
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
    template <class T>
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
    template <class T>
    void DoubleRotateWithLeft(BSTNode<T>*& bst) {
        SingleRotateWithRight(bst->lchild);
        SingleRotateWithLeft(bst);
    }
    /*
        函数：右双旋：即RL型
        参数：bst：最小不平衡子树根指针
        返回值：空
    */
    template <class T>
    void DoubleRotateWithRight(BSTNode<T>*& bst) {
        SingleRotateWithLeft(bst->rchild);
        SingleRotateWithRight(bst);
    }
    /*
        函数：搜索x
        参数：bst：根节点指针    x:要搜索的值，搜索成功后反回节点值
        返回值：搜索成功，返回指向该节点的指针；搜索失败返回NULL
    */
    template <class T>
    BSTNode<T>* Search(BSTNode<T>* bst, T& x) {
        if (bst == NULL)
            return NULL;
        else if (bst->data == x) {
            x = bst->data;
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
    template <class T>
    bool Modify(BSTNode<T>* bst, const T& id, const T& x) {
        T           y = id;
        BSTNode<T>* p = Search(bst, y);
        if (p == NULL) {
            cout << "要修改的元素不存在" << endl;
            return false;
        } else {
            p->data = x;
            return true;
        }
    }
    /*
        前序遍历
    */
    template <class T>
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
    template <class T>
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
    template <class T>
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
    cout << avlTree.Height() << endl;
    avlTree.Delete(3);
    avlTree.Modify(1, 2);
    avlTree.InOrder([](const int& x) -> void { cout << x << " "; });
}
