

#include "prefixTree.h"
//#include "treeNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

prefixTree::prefixTree() 
{
	rootPtr = nullptr;
}  // end default constructor

int prefixTree::shortestPrefixIndex(std::vector<std::string> netids) {
	std::string shortest = netids[0];
	int shortestIndex = 0;
	for (int i = 1; i < netids.size(); i++) {
		if (netids[i].length() < shortest.length()) {
			shortest = netids[i];
			shortestIndex = i;
		}
	}
	return shortestIndex;
}

prefixTree::prefixTree(std::string filename) {
	//read the routing table information from the file named filename
	//and create a prefix tree based on the routing table information
	//the root pointer should be initialized to nullptr
	rootPtr = nullptr;
	//create two vectors to store the network id and port numbers
	std::vector<std::string> netids;
	std::vector<int> ports;
	//open the file
	std::ifstream file;
	file.open(filename);
	//check if the file is open
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	//read the file line by line
	std::string line;
	while (std::getline(file, line)) {
		//split each line into tokens
		//the first token is the network id
		//the second token is the port number
		//they are seperated by a colon
		std::istringstream iss(line);
		std::string token;
		std::vector<std::string> tokens;
		while (std::getline(iss, token, ':')) {
			tokens.push_back(token);
		}
		//add the network ids and port numbers to the vectors
		netids.push_back(tokens[0]);
		ports.push_back(std::stoi(tokens[1]));
	}
	//close the file since we've got the data out
	file.close();
	//create the prefix tree based on the network ids and port numbers
	//the root node should be the node with the shortest network id
	int shortestIndex;
	shortestIndex = shortestPrefixIndex(netids);
	//create a new node and make it the root node
	rootPtr = std::make_shared<treeNode>(netids[shortestIndex], ports[shortestIndex]);
	//remove the network id and port number from the vectors
	netids.erase(netids.begin() + shortestIndex);
	ports.erase(ports.begin() + shortestIndex);
	//now repeat this process, adding the remaining nodes to the prefix tree in order from shortest to longest network id
	for (std::size_t i = 0; i < netids.size(); i++) {
		shortestIndex = shortestPrefixIndex(netids);
		add(netids[shortestIndex], ports[shortestIndex]);
		netids.erase(netids.begin() + shortestIndex);
		ports.erase(ports.begin() + shortestIndex);
	}
}


prefixTree::~prefixTree()
{
	//deallocate the memory allocated to the prefixTree. Reset the tree to an empty tree;
	rootPtr = nullptr; //setting the root pointer to nullptr will call the destructor of the treeNode class
}

/**
 * @brief add a new routing entry (netid, port) to the prefixTree.
 * a child node should be contain it's parent node's network id as a prefix
 * it is a left child if it has a 0 at the end of the network id, and a right child if it has a 1 at the end of the network id
*/
bool prefixTree::add(const std::string netid, const int port) {
	std::shared_ptr<treeNode> newNodePtr = std::make_shared<treeNode>(netid, port);
	if (isEmpty()) {
		rootPtr = newNodePtr;
		return true;
	}
	rootPtr = addHelper(rootPtr, newNodePtr);
	return true;
}

std::shared_ptr<treeNode> prefixTree::addHelper(std::shared_ptr<treeNode> subTreePtr, std::shared_ptr<treeNode> newNodePtr) {
	if (subTreePtr == nullptr) {
		return newNodePtr;
	}

	int result = checkValue(newNodePtr, subTreePtr);
	if (result == -1) { //if the nodes have equal netids, then update the port number
		subTreePtr->setPort(newNodePtr->getPort()); 
		return subTreePtr; 
		
	}
	if (result == 1) {
		subTreePtr->setRightChildPtr(addHelper(subTreePtr->getRightChildPtr(), newNodePtr));
	}
	else if (result == 0) {
		subTreePtr->setLeftChildPtr(addHelper(subTreePtr->getLeftChildPtr(), newNodePtr));
	}

	return subTreePtr;
}

int prefixTree::checkValue(std::shared_ptr<treeNode> current, std::shared_ptr<treeNode> target) {
	std::string currId = current->getNetId();
	std::string targetId = target->getNetId();
	if (currId == targetId) {
		return -1;
	}
	if (currId.compare(0, targetId.length(), targetId) == 0) {
		if (currId.back() == '1') {
			return 1;
		}
		else if (currId.back() == '0') {
			return 0;
		}
	}

	// Add a case for an invalid condition, or return a default value
	return 2;
}


//recursively traverse the tree to find the parent node of the new node
std::shared_ptr<treeNode> prefixTree::findLongestValidParent(std::shared_ptr<treeNode> target, std::shared_ptr<treeNode> root) {
	if (root->isLeaf()) {
		//if the root node is a leaf, then it is the longest valid parent
		return root;
	}
	else {
		//otherwise traverse the tree to the next level
		if (target->getNetId().find(root->getNetId()) == 0) {
			//if the target node's netid is a prefix of the current node's netid, then the target node is a child of the current node
			if (target->getNetId().find(root->getLeftChildPtr() == 0)) {
				//recursively call the function on the left child
				return findLongestValidParent(target, root->getLeftChildPtr());
			}
			else if (target->getNetId().find(root->getRightChildPtr() == 0)) {
				//recursively call the function on the right child
				return findLongestValidParent(target, root->getRightChildPtr());
			}
			else {
				//if the target node is not a child of the current node, then the current node is the longest valid parent
				return root;
			}

		}
	}
}


int prefixTree::findPort(std::string ipaddr) const
{
	//find the longest (lowest level) netid that is a prefix of the ipaddr
	//return the port number of that netid
	//if no netid is a prefix of the ipaddr, return -1
	std::shared_ptr<treeNode> currentNode = rootPtr;
	std::string longestPrefix = "";
	while (currentNode != nullptr) {
		if (isEmpty()) {
			return -1;
		}
		if (ipaddr.find(currentNode->getNetId()) == 0) {
			//if the current node's netid is a prefix of the ipaddr, then update the longest prefix
			longestPrefix = currentNode->getNetId();
			//check if the current node is a leaf node
			if (currentNode->isLeaf()) {
				//if the current node is a leaf node, then the longest prefix has been found
				return currentNode->getPort(); 
			}
			//otherwise traverse the tree to the next level
			else {
				if (ipaddr[currentNode->getNetId().length()] == '0') { //if the next character of the ipaddr is a 0, then the next node is the left child
					currentNode = currentNode->getLeftChildPtr(); 
				}
				else if (ipaddr[currentNode->getNetId().length()] == '1') { //if the next character of the ipaddr is a 1, then the next node is the right child
					currentNode = currentNode->getRightChildPtr(); 
				}
			}
		}
		else { //if the current node is not a prefix then the longest prefix has been found
			return currentNode->getPort(); 
		}
	}
}


/**
 * @brief remove the targeted routing entry from the prefixTree.
*/
bool prefixTree::remove(const std::string prefix)
{
	//traverse the tree to find the node to be removed
	std::shared_ptr<treeNode> currentNode = rootPtr;
	std::shared_ptr<treeNode> parentNode = nullptr;
	while (currentNode != nullptr) {
		if (currentNode->getNetId() == prefix){
			//we found the node to be removed
			parentNode = currentNode;
		}
		else if (currentNode->getNetId().find(prefix) != std::string::npos) {
			//if the prefix is a prefix of the current node's network id, then the current node is a valid parent, but we need to check its children
			currentNode = currentNode->getLeftChildPtr();
		}
		else if (currentNode->getNetId().find(prefix) != std::string::npos) {
			//if the prefix is a prefix of the current node's network id, then the current node is a valid parent, but we need to check its children
			currentNode = currentNode->getRightChildPtr();
		}
		else {
			//if the prefix is not a prefix of the current node's network id, then the current node is not a valid parent
			//the parent node is the previous node
			parentNode = currentNode;
			break;
		}
	}
	//check if the node to be removed is a leaf node
	if (currentNode->isLeaf()) {
		currentNode = nullptr; //setting the node to nullptr will call the destructor of the treeNode class
		return true; //removal is successful
	}
	else {
		//if the node to be removed is not a leaf node, then it has children
		//check if the node to be removed has a left child
		if (currentNode->getLeftChildPtr() != nullptr) {
			//if the node to be removed has a left child, then the left child is the new parent
			parentNode = currentNode->getLeftChildPtr();
		}
		else {
			//if the node to be removed does not have a left child, then the right child is the new parent
			parentNode = currentNode->getRightChildPtr();
		}
		//remove the node
		currentNode = nullptr; //setting the node to nullptr will call the destructor of the treeNode class

	}
	return true;
}

void prefixTree::clear()
{
	//deallocate the memory allocated to the prefixTree. Reset the tree to an empty tree;
	rootPtr = nullptr; //setting the root pointer to nullptr will call the destructor of the treeNode class
}


std::string prefixTree::postorderTraverseHelper(std::string visit(std::shared_ptr<treeNode> NodePtr), std::shared_ptr<treeNode> treePtr) const
{
	if (treePtr == nullptr) {
		return "";
	}
	else {
		return postorderTraverseHelper(visit, treePtr->getLeftChildPtr()) + postorderTraverseHelper(visit, treePtr->getRightChildPtr()) + visit(treePtr);
	}
}



RoutingEntry  prefixTree::getRoutingEntry(const std::string netId) const 
{

	return RoutingEntry{ "", -1 };
}

std::string prefixTree::postorderTraverse(std::string visit(std::shared_ptr<treeNode> NodePtr)) const {
	return postorderTraverseHelper(visit, rootPtr);
}



int prefixTree::getHeightHelper(std::shared_ptr<treeNode> subTreePtr) const
{
	if (subTreePtr == nullptr) {
		return 0;
	}
	else {
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
	}
}

int prefixTree::getNumberOfNodesHelper(std::shared_ptr<treeNode> subTreePtr) const
{
	if (subTreePtr == nullptr){
		return 0;
	}
	else {
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
	}
}





bool prefixTree::isEmpty() const {
	if (rootPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

int prefixTree::getHeight() const
{
	return getHeightHelper(rootPtr);
}

int prefixTree::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}


