//  MyBST.h
//

#ifndef MyBST_h
#define MyBST_h

#include "BST.h"

using namespace std;

struct Pair {
    Node *parent;
    Node *child;
};

/**
 * Represents one rotation (ZIG or ZAG) around one key in a Binary Search Tree
 */
class MyBST: public BST {
    public:

        /* default constructor -- constructs an empty Binary Search Tree */
        MyBST();

        /* constructs a one-node Binary Search Tree with the given key */
        MyBST(int num);

        /* constructs a Binary Search Tree by repeatedly inserting ints in <nums>
         in the order they appear in the array */
        MyBST(vector<int>& nums);

        /* constructs a rotation of type rot on key=num */
        vector<Rotation> transform(MyBST target);

        bool isParent(Node *parent, Node *child);

        bool isLeftParent(Node *parent, Node *child);

        bool isRightParent(Node *parent, Node *child);

        bool isRoot(Node* rootNode);

        bool rotateRight(Node *pivot, Node *parent, Node *grandParent);

        bool rotateLeft(Node *pivot, Node *child, Node *parent);

        Node* findParentLastRightSpineBranch();

        vector<Rotation> makeRightChain(RotationType rotType);

        void reverse(vector<Rotation> input);


};

#endif /* MyBST_h */
