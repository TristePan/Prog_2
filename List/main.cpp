#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

int main() {
    List<int> list;
    list.insert(1);
    cout << list << endl;
    list.insertHead(2);
    cout << list << endl;
    list.insertHead(7);
    cout << list << endl;
    cout << *list.getHead() << endl;
    list.insertTail(40);
    cout << list << endl;
    list.insertInOrder(30);
    cout << list << endl;

    return 0;
}