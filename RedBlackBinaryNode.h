/*
 * RedBlackBinaryNode.h
 *
 *  Created on: April 4, 2017
 *      Author: 293359
 */

#ifndef REDBLACKBINARYNODE_H_
#define REDBLACKBINARYNODE_H_

#include <iostream>
using namespace std;
/** -- Class RedBlackBinaryNode --
  * The RedBlackBinaryNode object is a component that, in conjunction with other binary nodes,
  * can form binary trees.
  * The RedBlackBinaryNode can be used to store and access integers.
  *
  * Members:
  * private int data
  * - The int value that the Node holds.
  *    The data of a RedBlackBinaryNode cannot be changed after construction.
  * private RedBlackBinaryNode* left
  * - The RedBlackBinaryNode pointer that represents the left child in the tree.
  * private RedBlackBinaryNode* right
  * - The RedBlackBinaryNode pointer that represents the right child in the tree.
  * private RedBlackBinaryNode* parent
  * - The RedBlackBinaryNode pointer that represents the parent of this RedBlackBinaryNode (root's parent should be null).
  *
  * Methods:
  * RedBlackBinaryNode(int newData, RedBlackBinaryNode* parent)
  * - Constructs a new RedBlackBinaryNode object
  *    Parameters: newData - the int value that the member data is set to.
  * RedBlackBinaryNode* getLeft()
  * - Returns the RedBlackBinaryNode pointer that is the left child of this RedBlackBinaryNode;
  *    returns the value in the member left.
  * RedBlackBinaryNode* getRight()
  * - Returns the RedBlackBinaryNode pointer that is the right child of this RedBlackBinaryNode;
  *    returns the value in the member right.
  * char* getData();
  * - Returns the int value that this RedBlackBinaryNode contains;
  *    returns the value in the member data.
  * void setLeft(RedBlackBinaryNode* newLeft)
  * - Sets the value for the member left.
  *    Parameters: newLeft - the RedBlackBinaryNode pointer that the member left is set to.
  * void setRight(RedBlackBinaryNode* newRight)
  * - Sets the value for the member right.
  *    Parameters: newRight - the RedBlackBinaryNode pointer that the member right is set to.
  * ~RedBlackBinaryNode()
  * - Destructs the RedBlackBinaryNode.
  *
  **/
class RedBlackBinaryNode {
 public:
  RedBlackBinaryNode(RedBlackBinaryNode* parent, int newData, bool isItBlack);
  RedBlackBinaryNode* getLeft();
  RedBlackBinaryNode* getRight();
  RedBlackBinaryNode* getParent();
  int getData();
  bool getIsBlack();
  void setLeft(RedBlackBinaryNode* newLeft);
  void setRight(RedBlackBinaryNode* newRight);
  RedBlackBinaryNode* grandparent();
  RedBlackBinaryNode* uncle();
  ~RedBlackBinaryNode();

 private:
  int data;
  RedBlackBinaryNode* left;
  RedBlackBinaryNode* right;
  RedBlackBinaryNode* parent;
  bool isBlack;
};



#endif /* REDBLACKBINARYNODE_H_ */
