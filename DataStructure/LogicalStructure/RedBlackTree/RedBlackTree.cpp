//
// Created by wzj on 2021/7/30.
//

#include "RedBlackTree.hpp"
/**
 * C++ ����: ���������
 *
 * @author wzj
 * @date 2021/07/31
 */

#include <iostream>
using namespace std;

int main() {
    int   a[]          = { 10, 40, 30, 60, 90, 70, 20, 50, 80, 10 };
    int   check_insert = 1;  // "����"�����ļ�⿪��(0���رգ�1����)
    int   check_remove = 1;  // "ɾ��"�����ļ�⿪��(0���رգ�1����)
    int   i;
    int   ilen = (sizeof(a)) / (sizeof(a[0]));
    auto* tree = new RBTree<int>();

    cout << "== ԭʼ����: ";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    for (i = 0; i < ilen - 1; i++) {
        tree->Insert(a[i]);
        // ����check_insert=1,����"��Ӻ���"
        if (check_insert) {
            cout << "== ��ӽڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->Print();
            cout << endl;
        }
    }
    tree->Remove(10);
    for (i = ilen - 1; i < ilen; i++) {
        tree->Insert(a[i]);
        // ����check_insert=1,����"��Ӻ���"
        if (check_insert) {
            cout << "== ��ӽڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->Print();
            cout << endl;
        }
    }
    cout << "== ǰ�����: ";
    tree->PreOrder();

    cout << "\n== �������: ";
    tree->InOrder();

    cout << "\n== �������: ";
    tree->PostOrder();
    cout << endl;

    cout << "== ��Сֵ: " << tree->Minimum() << endl;
    cout << "== ���ֵ: " << tree->Maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->Print();

    // ����check_remove=1,����"ɾ������"
    if (check_remove) {
        for (i = 0; i < ilen; i++) {
            tree->Remove(a[i]);

            cout << "== ɾ���ڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->Print();
            cout << endl;
        }
    }

    // ���ٺ����
    tree->Destroy();

    return 0;
}