/*
 * Main.cpp
 *
 *  Created on: April 4, 2017
 *      Author: Kevin Jin
 */
//Import everything I need
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "RedBlackBinaryNode.h"

using namespace std;

//Function prototypes
void add(RedBlackBinaryNode* & root, int newNode);
void print(RedBlackBinaryNode* root);
void remove(RedBlackBinaryNode* & root, int target);

//TODO Make calls to constructor include the bool isItBlack

//Main method which does pretty much everything
int main () {
	//Checks for valid input ("file", "console", or "quit").
	bool running = true;
	while (running) {
		//Initializing an empty tree
		RedBlackBinaryNode* root = NULL;
		char choose;
		//Input the first char of what the user types. If it's a c, f, or q, choose console, file, or quit respectively.
		cout << "Do you want to enter the numbers through the \"console\", through a \"file\", or \"quit\" the program?" << endl << "Choose: ";
		cin >> choose;
		cin.ignore(256, '\n');
		//They gave us valid input, so we ask them for the file.
		if (choose == 'f' || choose == 'F') {
			char fileIn[81];
			cout << "Input the path to the input file." << endl << "Path: ";
			cin >> fileIn;
			//Attempt to open file. If it opens, read contents and create heap. Otherwise, program kills itself.
			ifstream input (fileIn);
			if (input.is_open()) {
				char* nums = new char[501];
				//If file isn't empty, get and print contents.
				if (!input.eof()) {
					input.getline(nums, 500);
					cout << "File contents:" << endl;
					cout << nums;
					//We walk through the input from the file and add numbers as we find them to the BST.
					int temp = 0;
					bool isNum = false;
					//If it's a digit, multiply temp (the preexisting portion of the number) by 10 then add the digit.
					for (int i = 0; i < strlen(nums); i++) {
						if (isdigit(nums[i])) {
							temp *= 10;
							temp += nums[i] - '0';
							isNum = true;
						}
						//Otherwise if it's whitespace, add the number to the BST.
						else if (nums[i] != '\0' && nums[i] != '\n'){
							add(root, temp);
							temp = 0;
							isNum = false;
						}
					}
					//This here is a workaround to deal with loose zeroes being appended to input.
					if (isNum) {
						add(root, temp);
						temp = 0;
					}
					//Print the BST.
					cout << endl << "This is the binary search tree:" << endl;
					print(root);
					bool isFinished = false;
					//While they haven't typed "c" (for continue), we ask them what they want to do with the tree
					while (!isFinished) {
					  cout << "Would you like to \"print\" the tree, \"delete\" a node from the tree, or \"continue\"?" << endl << "Input: ";
					  cin >> choose;
					  cin.ignore(256, '\n');
					  if (choose == 'p' || choose == 'P') print(root);
					  else if (choose == 'd' || choose == 'D') {
						  int target;
						  //Prompt for a target for deletion
						  cout << "Please enter the value of the Node you want to delete." << endl << "Target: ";
						  cin >> target;
						  remove(root, target);

					  }
					  else if (choose == 'c' || choose == 'C') isFinished = true;
					  else cout << "That input is invalid. Please try again." << endl;
					}
				}
				//Close input
				input.close();
			}
			else cout << "Unable to open file" << endl;
		}
		//If they want to input from console, read their input from console then proceed the exact same way as in file.
		else if (choose == 'c' || choose == 'C') {
			char* nums = new char[501];
			cout << "Input the numbers, each separated by a space." << endl << "Numbers: ";
			cin.getline(nums, 500);
			cout << "Your input:" << endl;
			cout << nums;
			//Creates the BST the same way as if input was from file.
			int temp = 0;
			bool isNum = false;
			for (int i = 0; i < strlen(nums); i++) {
				if (isdigit(nums[i])) {
					temp *= 10;
					temp += nums[i] - '0';
					isNum = true;
				}
				else if (nums[i] != '\0' && nums[i] != '\n'){
					add(root, temp);
					temp = 0;
					isNum = false;
				}
			}
			if (isNum) {
				add(root, temp);
				temp = 0;
			}
			cout << endl << "This is the binary search tree:" << endl;
			print(root);
			bool isFinished = false;
			while (!isFinished) {
			  cout << "Would you like to \"print\" the tree, \"delete\" a node from the tree, or \"continue\"?" << endl << "Input: ";
			  cin >> choose;
			  cin.ignore(256, '\n');
			  if (choose == 'p' || choose == 'P') print(root);
			  else if (choose == 'd' || choose == 'D') {
				  int target;
				  cout << "Please enter the value of the Node you want to delete." << endl << "Target: ";
				  cin >> target;
				  remove(root, target);

			  }
			  else if (choose == 'c' || choose == 'C') isFinished = true;
			  else cout << "That input is invalid. Please try again." << endl;
			}

		}
		else if (choose == 'q' || choose == 'Q') {
			running = false;
			cout << "Ending program..." << endl << "Thanks for using this program!" << endl;
		}
		else
			cout << "That input is invalid." << endl;
	}
	return 0;
}
//Add the node to the tree.
void add(RedBlackBinaryNode* & root, int newNode) {
	RedBlackBinaryNode* current = root;
	//If tree is empty, root equals the new node
	if (root == NULL)
		root = new RedBlackBinaryNode(newNode, true);
	else {
		//Otherwise, shift left if node is equal to or less than current and shift right otherwise until the end of the tree is reached
		bool hasAdded = false;
		while (!hasAdded) {
			if (newNode > current->getData()) {
				if (current->getRight() == NULL) {
					current->setRight(new RedBlackBinaryNode(newNode));
					hasAdded = true;
				}
				else
					current = current->getRight();
			}
			else {
				if (current->getLeft() == NULL) {
					current->setLeft(new RedBlackBinaryNode(newNode));
					hasAdded = true;
				}
				else
					current = current->getLeft();
			}
		}
	}
}
//Prints the BST. Prints each node and its children
void print(RedBlackBinaryNode* root) {
	//The function is recursive
	bool left = false;
	bool right = false;
	if (root != NULL) {
		cout << "Node: " << root->getData() << endl;
		if (root->getLeft() != NULL) {
			cout << "Left child: " << root->getLeft()->getData() << endl;
			left = true;
		}
		else
			cout << "Left child: None" << endl;
		if (root->getRight() != NULL) {
			cout << "Right child: " << root->getRight()->getData() << endl;
			right  = true;
		}
		else
			cout << "Right child: None" << endl;
		cout << endl;
		if (left)
			print(root->getLeft());
		if (right)
			print(root->getRight());
	}
	else cout << "The tree is empty." << endl;
}
//Deletes the targeted node, if its exists.
void remove(RedBlackBinaryNode* & root, int target) {
	RedBlackBinaryNode* current = root;
	RedBlackBinaryNode* parent = NULL;
	bool targetIsLeftChild = false;
	bool hasLeft = false;
	bool hasRight = false;
	//There are just a shit ton of conditions to check. We check all unique ones.
	while (current->getData() != target) {
		if (target > current->getData()) {
			if (current->getRight() == NULL) {
			  cout << "A node with value of \"" << target << "\" does not exist in the tree." << endl;
				return;
			}
			else {
				parent = current;
				current = current->getRight();
			}
		}
		else {
			if (current->getLeft() == NULL) {
			  cout << "A node with value of \"" << target << "\" does not exist in the tree." << endl;
				return;
			}
			else {
				parent = current;
				current = current->getLeft();
			}
		}
	}
	cout << "A node with value of \"" << target << "\" was removed from the tree." << endl;
	if (current->getLeft() != NULL) hasLeft = true;
	if (current->getRight() != NULL) hasRight = true;
	if (parent != NULL)
		if (parent->getLeft() == current) targetIsLeftChild = true;
	if (hasLeft) {
		if (!hasRight) {
			if (targetIsLeftChild && parent != NULL) parent->setLeft(current->getLeft());
			else if (parent != NULL) parent->setRight(current->getLeft());
			else root = current->getLeft();
			delete current;
		}
		else {
			RedBlackBinaryNode* rightmost = current->getLeft();
			RedBlackBinaryNode* rightmostParent = current;
			while (rightmost->getRight() != NULL){
				rightmostParent = rightmost;
				rightmost = rightmost->getRight();
			}
			if (targetIsLeftChild && parent != NULL) parent->setLeft(rightmost);
			else if (parent!= NULL) parent->setRight(rightmost);
			else root = rightmost;
			if (rightmostParent != current) {
				rightmostParent->setRight(rightmost->getLeft());
				rightmost->setLeft(current->getLeft());
			}
			rightmost->setRight(current->getRight());
			delete current;
		}
	}
	else if (hasRight) {
		if (targetIsLeftChild && parent != NULL) parent->setLeft(current->getRight());
		else if (parent != NULL) parent->setRight(current->getRight());
		else root = current->getRight();
		delete current;
	}
	else {
		if (targetIsLeftChild && parent != NULL) parent->setLeft(NULL);
		else if (parent != NULL) parent->setRight(NULL);
		else root = NULL;
		delete current;
	}

}