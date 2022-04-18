#include <iostream>
#include "forward.h"
#include "double.h"
#include "list.h"
#include "node.h"
#include "iterator.h"

using namespace std;

void testSimpleLinkedList();
void testDoubleLinkedList();

int main(int argc, char const *argv[]) {
    testSimpleLinkedList();
    testDoubleLinkedList();
    cin.get();
    return EXIT_SUCCESS;
}

void testSimpleLinkedList() {
    cout << "Forward Linked List" << endl;

    ForwardList<int> integers;
    ForwardList<int>::iterator ite1;
    
    for (int i = 0; i < 5; i++) {
        integers.push_front(2 * i + 1);
    }

    integers.remove(5);
    
    for (ite1 = integers.begin(); ite1 != integers.end(); ++ite1) {
        cout << *ite1 << " ";
    }
    
    cout << endl << endl;
}

void testDoubleLinkedList() {
    cout << "Doubly Linked List" << endl;

    DoubleList<int> integers;
    DoubleList<int>::iterator ite;
    
    for (int i = 0; i < 5; i++) {
        integers.push_front(2 * i + 1);
    }
    
    ite = integers.begin();
    ++ite;
    cout << *ite << " ";
    ++ite;
    cout << *ite << " ";
    --ite;
    cout << *ite << " ";
    cout << endl << endl;
}