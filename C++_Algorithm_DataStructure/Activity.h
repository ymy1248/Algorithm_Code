#include <iostream>
#include "consts.h"
using namespace std;

class Activity {
public:
    Activity(const vector<const char *> &);
    virtual RunOutput run() = 0;
    Cmd getCmd() const;
    void showView();
private:
    const vector<const char *> &_content;

    inline void gotoXY(int x, int y) const {
        cout << "\e["  << x << ";" << y << "H";
    }
    inline void goUp(int n = 1) const  {
        cout << "\e[" << n << "F";
    }
    inline void goDown(int n = 1) const {
        cout << "\e[" << n << "E";
    }
    inline void goRight(int n = 1) const {
        cout << "\e[" << n << "C";
    }
    inline void goLeft(int n = 1) const {
        cout << "\e[" << n << "D";
    }
    inline void beep() const {
        cout << char(7);
    }
    inline void clear() const {
        cout << "\e[2J";
    }
};
