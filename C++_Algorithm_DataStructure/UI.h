#include "consts.h"
#include <iostream>

using namespace std;

namespace ymy1248 {
class UI {
public:
    void run();
private:
    Cmd getCmd(size_t) const;
    OutLine outline();
    Alg algorithm();
    Ds dataStructure();
    char getc();
    inline void gotoXY(int x, int y) const;
    inline void goUp(int = 1) const;
    inline void goDown(int = 1) const;
    inline void goRight(int = 1) const;
    inline void goLeft(int = 1) const;
    inline void beep() const;
    inline void clear() const;
};
}
