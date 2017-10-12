#include <iostream>
#include <termios.h>
#include <stdlib.h>

using namespace std;

namespace ymy1248 {
class UI {
public:
    void run();
private:
    char getCmd() const;
    char getc(istream &);
    static void setKeyPress();
    static void resetKeyPress();
    void gotoXY(int x, int y);
    void goUp(int = 1);
    void goDown(int = 1);
    void goRight(int = 1);
    void goLeft(int = 1);
};
static struct termios stored_settings;
}
