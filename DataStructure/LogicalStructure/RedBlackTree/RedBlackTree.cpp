//
// Created by wzj on 2021/7/30.
//

#include "RedBlackTree.hpp"
/**
 * C++ 语言: 二叉查找树
 *
 * @author wzj
 * @date 2021/07/31
 */

#include <iostream>
using namespace std;

int main() {
    int   a[]          = { 10, 40, 30, 60, 90, 70, 20, 50, 80, 10 };
    int   check_insert = 1;  // "插入"动作的检测开关(0，关闭；1，打开)
    int   check_remove = 1;  // "删除"动作的检测开关(0，关闭；1，打开)
    int   i;
    int   ilen = (sizeof(a)) / (sizeof(a[0]));
    auto* tree = new RBTree<int>();

    cout << "== 原始数据: ";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    for (i = 0; i < ilen - 1; i++) {
        tree->Insert(a[i]);
        // 设置check_insert=1,测试"添加函数"
        if (check_insert) {
            cout << "== 添加节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->Print();
            cout << endl;
        }
    }
    tree->Remove(10);
    for (i = ilen - 1; i < ilen; i++) {
        tree->Insert(a[i]);
        // 设置check_insert=1,测试"添加函数"
        if (check_insert) {
            cout << "== 添加节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->Print();
            cout << endl;
        }
    }
    cout << "== 前序遍历: ";
    tree->PreOrder();

    cout << "\n== 中序遍历: ";
    tree->InOrder();

    cout << "\n== 后序遍历: ";
    tree->PostOrder();
    cout << endl;

    cout << "== 最小值: " << tree->Minimum() << endl;
    cout << "== 最大值: " << tree->Maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->Print();

    // 设置check_remove=1,测试"删除函数"
    if (check_remove) {
        for (i = 0; i < ilen; i++) {
            tree->Remove(a[i]);

            cout << "== 删除节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->Print();
            cout << endl;
        }
    }

    // 销毁红黑树
    tree->Destroy();

    return 0;
}