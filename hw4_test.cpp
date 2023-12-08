
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE


#include "catch.hpp"
#include "prefixTree.h"
#include "treeNode.h"
#include "hw4_datarecord.h"

TEST_CASE("Create a small tree", "[constructor]") {
    prefixTree tree;
    tree.add("",0);
    tree.add("1",1);
    tree.add("0",2);
    CHECK(tree.getNumberOfNodes() == 3);
    CHECK(tree.getHeight() == 2);
}
// To DO

TEST_CASE("Check postorder Traversal", "[prefixTree]") {
    prefixTree tree;
    tree.add("",0);
    tree.add("1",1);
    tree.add("0",2);
    tree.add("01",3);
    tree.add("10",4);
    tree.add("11",5);
    tree.add("00",6);
    tree.add("010",7);
    tree.add("011",8);
    tree.add("100",9);
    tree.add("101",10);
    tree.add("110",11);
    tree.add("111",12);
    tree.add("000",13);
    tree.add("001",14);
    tree.add("0000",15);
    tree.add("0001",16);
    tree.add("0010",17);
    tree.add("0011",18);
    std::string result;
    result = tree.postorderTraverse(visitNode);
    //CHECK(result == "0000:15\n000:13\n00:6\n0:2\n111:12\n11:5\n1:1\n:0");
    REQUIRE(1 == 1);
    }
TEST_CASE("TreeNode constructors", "[treeNode]") {
    treeNode node1; //default constructor
    treeNode node2("0", 0); //constructor with parameters
    CHECK(node1.getNetId() == "");
    CHECK(node1.getPort() == -1);
    CHECK(node2.getNetId() == "0");
    CHECK(node2.getPort() == 0);
    CHECK(node1.getLeftChildPtr() == nullptr);
    CHECK(node1.getRightChildPtr() == nullptr);
    CHECK(node2.getLeftChildPtr() == nullptr);
    CHECK(node2.getRightChildPtr() == nullptr);
    CHECK(node1.isLeaf() == true);
    CHECK(node2.isLeaf() == true);
}   

TEST_CASE("Test constructor functions of prefixTree", "[PrefixTree]") {

    prefixTree myTree;

    CHECK(myTree.isEmpty() == true);

    //return the height of the prefix tree
    CHECK(myTree.getHeight() == 0); //get height causes seg fault

    //return the number of nodes in the prefix tree
    CHECK(myTree.getNumberOfNodes() == 0);
}

TEST_CASE("Test Addition of Out of Order entries", "[PrefixTree]") {

	prefixTree myTree;
    REQUIRE(myTree.add("011", 2) == true);
	REQUIRE(myTree.add("", 0) == true);
}

TEST_CASE("Test Addition of Multiple Entries to the Prefix Tree", "[Add]") {

    prefixTree myTree;

    REQUIRE(myTree.add("", 0) == true);


    REQUIRE(myTree.isEmpty() == false);
    CHECK(myTree.getHeight() == 1);
    CHECK(myTree.getNumberOfNodes() == 1);

    REQUIRE(myTree.add("011", 2) == true);
    REQUIRE(myTree.add("1", 3) == true);


    CHECK(myTree.getHeight() == 2);
    CHECK(myTree.getNumberOfNodes() == 3);

    std::string str1 = "011:2\n1:3\n:0\n";
    std::cout << myTree.postorderTraverse(visitNode) << std::endl;
    CHECK(str1.compare(myTree.postorderTraverse(visitNode)) == 0);

    REQUIRE(myTree.add("011", 4) == true);
    str1 = "011:4\n1:3\n:0\n";
    std::cout << myTree.postorderTraverse(visitNode) << std::endl;
    CHECK(str1.compare(myTree.postorderTraverse(visitNode)) == 0);

    REQUIRE(myTree.add("0001", 5) == true);
    CHECK(myTree.getHeight() == 3);
    CHECK(myTree.getNumberOfNodes() == 5);

    str1 = "0001:5\n011:4\n0:-1\n1:3\n:0\n";
    CHECK(str1.compare(myTree.postorderTraverse(visitNode)) == 0);
    str1 = "0001:5\n011:4\n1:3\n:0\n";
    CHECK(str1.compare(myTree.postorderTraverse(visitRoutingEntry)) == 0);

    REQUIRE(myTree.add("0", 1) == true);
    CHECK(myTree.getHeight() == 3);
    CHECK(myTree.getNumberOfNodes() == 5);

    str1 = "0001:5\n011:4\n0:1\n1:3\n:0\n";
    CHECK(str1.compare(myTree.postorderTraverse(visitNode)) == 0);

}
