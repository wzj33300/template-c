#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

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
        return Remove(root, x);
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
        } else if (x <= bst->data) {
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
        } /* else {
            cout << "插入元素已经存在！！！" << endl;
            return false;
        }*/
        return false;
    }

    /*
	    函数：删除值为x的节点(当有多个节点符合条件时，删除最靠近bst的(最早插入的))
    	参数：bst：树根指针，进行调整的时候会修改其值，故用引用    x：要删除的值
    	返回值：是否成功删除
    */
    bool Remove(BSTNode<T>*& bst, const T& x) {
        if (bst == NULL) {
            cout << "删除元素不存在！！！" << endl;
            return false;
        } else if (x < bst->data) {
            bool r = Remove(bst->lchild, x);
            if (Height(bst->lchild) - Height(bst->rchild) == -2) {
                if (Height(bst->lchild) - Height(bst->rchild->rchild) == -1)
                    SingleRotateWithRight(bst);
                else
                    DoubleRotateWithRight(bst);
            }
            bst->h = max(Height(bst->lchild), Height(bst->rchild)) + 1;
            return r;
        } else if (x > bst->data) {
            bool r = Remove(bst->rchild, x);
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
        return ((Remove(bst, id)) && (Insert(bst, x)));
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

#endif