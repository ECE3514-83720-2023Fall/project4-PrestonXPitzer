

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
	//the root pointer should be the default treeNode
	treeNode root;
	rootPtr = std::make_shared<treeNode>(root);
}  // end default constructor

int prefixTree::shortestPrefixIndex(std::vector<std::string> netids){
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
    // Create a new node
    std::shared_ptr<treeNode> newNode = std::make_shared<treeNode>(netid, port);

    if (rootPtr == nullptr) {
        // If the prefix tree is empty, create a new node and make it the root node
        rootPtr = newNode;
        return true;
    } else {
        // Traverse the tree to find the parent node of the new node
        std::shared_ptr<treeNode> currentNode = rootPtr;

        while (true) {
			//if at any point the netid's are equal, then update the port number
			if (currentNode->getNetId() == newNode->getNetId()) {
				currentNode->setPort(newNode->getPort());
				return true;
			}
            // Check if the new node's netid is a prefix of the current node's netid
			if (newNode->getNetId().find(currentNode->getNetId()) == 0) {
                // If the last character of the new node's netid is '0', add it as a left child
                if (newNode->getNetId().back() == '0') {
                    if (currentNode->getLeftChildPtr() == nullptr) {
                        currentNode->setLeftChildPtr(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getLeftChildPtr();
                    }
                }
                // If the last character of the new node's netid is '1', add it as a right child
                else if (newNode->getNetId().back() == '1') {
                    if (currentNode->getRightChildPtr() == nullptr) {
                        currentNode->setRightChildPtr(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getRightChildPtr();
                    }
                }
            } else { //if we can't find a valid parent, then the new node becomes the root node
				std::shared_ptr<treeNode> temp = rootPtr;
				rootPtr = newNode;
				if (temp->getNetId() != "") {
					if (temp->getNetId().back() == '0') {
						rootPtr->setLeftChildPtr(temp);
						return true;
					}
					else if (temp->getNetId().back() == '1') {
						rootPtr->setRightChildPtr(temp);
						return true;
					}
				}
				//because both the old root and the new root are empty, potentially update the port number
				rootPtr->setPort(newNode->getPort());
				return false; //if the old root was empty, and the new root is empty, then we return false
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
		if (currentNode->getNetId() == "") {
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


