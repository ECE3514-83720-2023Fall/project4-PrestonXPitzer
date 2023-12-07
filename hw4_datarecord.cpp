#include "hw4_datarecord.h"
#include <string>
/**
 * @brief return a string containing the netId and port of the node
*/
std::string visitNode(std::shared_ptr<treeNode> nodePtr) {
	std::string buildString = "";
	buildString += nodePtr->getNetId();
	buildString += ":";
	buildString += std::to_string(nodePtr->getPort());
	return buildString;
}
/**
 * @brief return a string containing the netId and port of the node
 * @details ONLY return if the port number >= 0
*/
std::string visitRoutingEntry(std::shared_ptr<treeNode> nodePtr) {
	std::string buildString = "";
	if (nodePtr->getPort() < 0) {
		return buildString;
	}
	buildString += nodePtr->getNetId();
	buildString += ":";
	buildString += std::to_string(nodePtr->getPort());
	return buildString;
}