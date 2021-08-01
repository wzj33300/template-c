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
	�������ͷ�bst��
	���������ĸ�ָ��
	����ֵ����
    */
    void        Release(BSTNode<T>* bst) {
        if (bst != NULL) {
            Release(bst->lchild);
            Release(bst->rchild);
            delete bst;
        }
    }
    /*
	��������ȡ���ĸ߶ȣ������߶�Ϊ0��
	������bst�����ĸ�ָ��
	����ֵ�����ĸ߶�
    */
    inline int Height(BSTNode<T>* bst) {
        return (bst == NULL ? -1 : bst->h);
    }
    /*
	����������x
	������bst�����ĸ�ָ�룬���е�����ʱ����޸���ֵ����������    x��Ҫ�����ֵ
	����ֵ���Ƿ�ɹ�����
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
            cout << "����Ԫ���Ѿ����ڣ�����" << endl;
            return false;
        }*/
        return false;
    }

    /*
	    ������ɾ��ֵΪx�Ľڵ�(���ж���ڵ��������ʱ��ɾ�����bst��(��������))
    	������bst������ָ�룬���е�����ʱ����޸���ֵ����������    x��Ҫɾ����ֵ
    	����ֵ���Ƿ�ɹ�ɾ��
    */
    bool Remove(BSTNode<T>*& bst, const T& x) {
        if (bst == NULL) {
            cout << "ɾ��Ԫ�ز����ڣ�����" << endl;
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
                if (p == bst->rchild)  //�������
                    bst->rchild = p->rchild;
                else {  //һ�����
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
    	��������������LL��
    	������bst����С��ƽ��������ָ��
    	����ֵ����
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
        �������ҵ�������RR��
        ������bst����С��ƽ��������ָ��
        ����ֵ����
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
        ��������˫������LR��
        ������bst����С��ƽ��������ָ��
        ����ֵ����
    */
    void DoubleRotateWithLeft(BSTNode<T>*& bst) {
        SingleRotateWithRight(bst->lchild);
        SingleRotateWithLeft(bst);
    }
    /*
        ��������˫������RL��
        ������bst����С��ƽ��������ָ��
        ����ֵ����
    */
    void DoubleRotateWithRight(BSTNode<T>*& bst) {
        SingleRotateWithLeft(bst->rchild);
        SingleRotateWithRight(bst);
    }
    /*
        ����������x
        ������bst�����ڵ�ָ��    x:Ҫ������ֵ�������ɹ��󷴻ؽڵ�ֵ
        ����ֵ�������ɹ�������ָ��ýڵ��ָ�룻����ʧ�ܷ���NULL
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
        �������޸Ľڵ�ֵ
        ������x���ѽڵ�ֵΪid�Ľڵ�Ľڵ�ֵ�޸�Ϊx
        ����ֵ���Ƿ�ɹ��޸�
    */
    bool Modify(BSTNode<T>* bst, const T& id, const T& x) {
        return ((Remove(bst, id)) && (Insert(bst, x)));
    }
    /*
        ǰ�����
    */
    void PreOrder(BSTNode<T>* bst, void visit(const T& x)) {
        if (bst != NULL) {
            visit(bst->data);
            PreOrder(bst->lchild, visit);
            PreOrder(bst->rchild, visit);
        }
    }
    /*
        �������
    */
    void InOrder(BSTNode<T>* bst, void visit(const T& x)) {
        if (bst != NULL) {
            InOrder(bst->lchild, visit);
            visit(bst->data);
            InOrder(bst->rchild, visit);
        }
    }
    /*
        �������
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