/*
 * RedBlackBinaryNode.cpp
 *
 *  Created on: April 4, 2017
 *      Author: 293359
 */

#include <iostream>
#include "RedBlackBinaryNode.h"
using namespace std;

//Constructs a Node
RedBlackBinaryNode::RedBlackBinaryNode(int newData, bool isItBlack) {
  data = newData;
  left = NULL;
  right = NULL;
  isBlack = isItBlack;
}
//Return left
RedBlackBinaryNode* RedBlackBinaryNode::getLeft() {
  return left;
}
//Return right
RedBlackBinaryNode* RedBlackBinaryNode::getRight() {
  return right;
}
//Return data
int RedBlackBinaryNode::getData() {
  return data;
}
//Return whether the node is black or red
bool RedBlackBinaryNode::getIsBlack() {
	return isBlack;
}
//Sets left RedBlackBinaryNode
void RedBlackBinaryNode::setLeft(RedBlackBinaryNode* newLeft) {
  left = newLeft;
}
//Sets right RedBlackBinaryNode
void RedBlackBinaryNode::setRight(RedBlackBinaryNode* newRight) {
  right = newRight;
}
//Destructs the RedBlackBinaryNode
RedBlackBinaryNode::~RedBlackBinaryNode() {
}





