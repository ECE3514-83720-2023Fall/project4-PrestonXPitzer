
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE


#include "catch.hpp"
#include "prefixTree.h"
#include "treeNode.h"
#include "hw4_datarecord.h"

TEST_CASE("Test Creating an Empty Tree", "[constructor]") {
    prefixTree tree;
    tree.add("",0);
    tree.add("1",1);
    tree.add("0",2);
    REQUIRE(1==1);
}
// To DO

TEST_CASE("Add a lot of nodes to a tree", "[prefixTree]") {
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
    REQUIRE(result == "0000:15\n0001:16\n0010:17\n0011:18\n001:14\n000:13\n01:3\n10:4\n11:5\n0:2\n1:1\n:0\n");
    REQUIRE(1==1);
    }