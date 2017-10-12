#include <vector>
#include <string>
#define DEBUG 1 

using namespace std;

const vector<const char*> OUTLINE {
    "0) Algorithm",
    "1) Data Structure"
};

const vector<const char*> ALG {
    "0) Sorting",
    "1) Graph",
};

const static char *MOVE = "Use hijk to move the cursor";

enum OutLine {
    ALGORITHM,
    DATA_STRUCTURE
};

enum Alg {
    SORTING,
    GRAPH
};
