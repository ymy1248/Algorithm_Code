#ifndef CONSTS_H
#define CONSTS_H

#include <vector>
#include <string>
#include <iostream>

#define DEBUG 0
#define MAX_SEL 15

using namespace std;

const vector<const char*> OUTLINE {
    "0) Algorithm",
    "1) Data Structure"
};

const vector<const char*> ALG {
    "0) Sorting",
    "1) Graph",
};

const vector<const char*> DS {
    "0) Linked List",
    "1) Queue",
    "2) Stack",
    "3) Binary Search Tree",
    "4) Read Black Tree",
    "5) Hash Map",
    "6) Hash Set",
};

const static char *MOVE = "Use hijk to move the cursor";


enum OutLine {
    ALGORITHM,
    DATA_STRUCTURE
}; 

enum Alg {
    SORTING,
    GRAPH,
};

enum Ds {
    LINKED_LIST,
    QUEUE,
    STACK,
    BST,
    RBT,
    HASH_MAP,
    SET,
}; 

enum Cmd {
    SELECT_0,
    SELECT_1,
    SELECT_2,
    SELECT_3,
    SELECT_4,
    SELECT_5,
    SELECT_6,
    SELECT_7,
    SELECT_8,
    SELECT_9,
    SELECT_10,
    SELECT_11,
    SELECT_12,
    SELECT_13,
    SELECT_14,
    SELECT_15,
};

#endif // CONSTS_H
