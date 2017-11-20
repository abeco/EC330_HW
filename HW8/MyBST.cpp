//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"

/* constructs an empty Binary Search Tree */
MyBST::MyBST() : BST()
{
}

/* constructs a one-node Binary Search Tree with the given key */
MyBST::MyBST(int num): BST(num)
{
}

/* constructs a Binary Search Tree by repeatedly inserting ints in <nums>
    in the order they appear in the array */
MyBST::MyBST(vector<int>& nums): BST(nums)
{
}

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 *  must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */

vector<Rotation> MyBST::transform(MyBST target) {

  vector<Rotation> rotationVectorMe;
  vector<Rotation> rotationVectorTarget;

  /*** This is what you have to do ***/

  // 1)  transform our BST to a right chain via rotations
  //     and get the vector of rotation operations needed
  rotationVectorMe = this->makeRightChain(ZIG);

  // 2) transform target BST to a right chain via rotations
  //    and get the vector of rotation operations needed
  //    N.B. target rotation operations are ZAGs because they're opposite
  //    of the right rotations to form the right chain
  rotationVectorTarget = target.makeRightChain(ZAG);

  // 3) target BST rotation vector should be reversed since we apply those
  //    operations in opposite order
  reverse(rotationVectorTarget);

  // 4) concatenate the two vectors of rotation operations
  rotationVectorMe.insert(rotationVectorMe.end(),
                    rotationVectorTarget.begin(), rotationVectorTarget.end() );

  // return our vector of operations;
  return rotationVectorMe;

}

bool MyBST::isLeftParent(Node *parent, Node *child) {

  bool leftParent = false;

  if (parent && parent->left) {
      if (parent->left == child) {
        leftParent = true;
      }
  }

  return leftParent;

}

bool MyBST::isRightParent(Node *parent, Node *child) {

  bool rightParent = false;

  if (parent && parent->right) {
      if (parent->right == child) {
        rightParent = true;
      }
  }

  return rightParent;
}

bool MyBST::isParent(Node *parent, Node *child) {
  return (isLeftParent(parent, child) || isRightParent(parent,child));
}

bool MyBST::isRoot(Node *rootNode) {

  if (this->root == rootNode) {
    return true;
  } else {
    return false;
  }
}

bool MyBST::rotateRight(Node *root, Node *pivot, Node *parent) {

  // if parent is NULL, then root should be rootNode
  if (!parent && !isRoot(root)) {
    return false;
  }

  // if parent is a real node, it should be a parent of the root
  if ((parent && !isParent(parent, root))) {
    return false;
  }

  // both root and pivot should be real nodes
  if (!(root && pivot )) {
    return false;
  }

  // verify that pivot is left child of root
  if (!isLeftParent(root, pivot)) {
    return false;
  }

  // rotate Tree
  root->left = pivot->right;
  pivot->right = root;

  if (parent) {
    if (isLeftParent(parent, root)) {
      parent->left = pivot;
    } else {
      parent->right = pivot;
    }
  } else {
    this->root = pivot;
  }

  return true;

}

bool MyBST::rotateLeft(Node *root, Node *pivot, Node *parent) {

  // if parent is NULL, then root should be rootNode
  if (!parent && !isRoot(root)) {
    return false;
  }

  // if parent is a real node, it should be a parent of the root
  if ((parent && !isParent(parent, root))) {
    return false;
  }

  // both root and pivot should be real nodes
  if (!(root && pivot )) {
    return false;
  }

  // verify that pivot is left child of root
  if (!isRightParent(root, pivot)) {
    return false;
  }

  // rotate Tree
  root->right = pivot->left;
  pivot->left = root;

  if (parent) {
    if (isLeftParent(parent, root)) {
      parent->left = pivot;
    } else {
      parent->right = pivot;
    }
  } else {
    this->root = pivot;
  }

  return true;

}

Node* MyBST::findParentLastRightSpineBranch() {

  Node *branchParent = nullptr;
  Node *current = this->root;

  while (current) {
    if (current->right && current->right->left) {
      branchParent = current;
    }
    current = current->right;
  }
  return branchParent;

}

vector<Rotation> MyBST::makeRightChain(RotationType rotType) {
  Node* nextBranch = nullptr;
  vector<Rotation> rotations;
  int rotationKey;


  while (true) {
    nextBranch = findParentLastRightSpineBranch();

    // we found the last branch
    if (nextBranch) {

      // store key for rotation;
      rotationKey = nextBranch->right->left->key;

      // rotate tree
      rotateRight(nextBranch->right, nextBranch->right->left, nextBranch);

      // add to our stack of rotations
      rotations.push_back(Rotation(rotationKey,rotType));


    } else {
      // does the root node have a branch?
      if (this->root && this->root->left) {

        // store key for rotation;
        rotationKey = this->root->left->key;

        // rotate tree
        rotateRight(this->root, this->root->left, nullptr);

        // add to our stack of rotations
        rotations.push_back(Rotation(rotationKey,rotType));

      } else {
        // nothing else to do, break
        break;
      }
    }
  }

  return rotations;
}

void MyBST::reverse(vector<Rotation> input) {

  if (input.size() == 0) {
    return;	
  }

  Rotation temp = input.at(0);

  for(int forward = 0, back = input.size()-1; forward < input.size()/2; forward++, back--){
  	        temp = input.at(forward);
  	        input.at(forward) = input.at(back);
  	        input.at(back) = temp;
  	    }

}
