#include <iostream>
#include "consts.h"

using namespace std;

class Activity {
public:
    Activity(vector<const char *> &);
    virtual void run() = 0;
private:
    vector<const char *> &_content;

    Cmd getCmd() const;
};
