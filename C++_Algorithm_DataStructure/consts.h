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
    "0) GO BACK",
    "1) Sorting",
    "2) Graph",
};

const vector<const char*> DS {
    "0) GO BACK",
    "1) Linked List",
    "2) Queue",
    "3) Stack",
    "4) Binary Search Tree",
    "5) Read Black Tree",
    "6) Hash Map",
    "7) Hash Set",
};

const static char *MOVE = "Use hijk to move the cursor";

struct RunInput {
};

struct RunOutput {
    bool exit;
};

struct ActInput{
};

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
