#include "BST.h"

using namespace std;

int main() {
    BST <int> b;
    b.insert(40);
    b.insert(25);
    b.insert(21);
    b.insert(18);
    b.insert(57);
    b.insert(36);
    b.insert(46);
    b.insert(32);
    b.insert(78);
    b.insert(52);
    b.insert(11);
    b.insert(44);

    b.inorder();

}