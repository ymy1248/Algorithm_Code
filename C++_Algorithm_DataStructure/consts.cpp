#include "consts.h"

inline void gotoXY(int x, int y) {
    cout << "\e["  << x << ";" << y << "H";
}
inline void goUp(int n = 1) {
    cout << "\e[" << n << "F";
}
inline void goDown(int n = 1) {
    cout << "\e[" << n << "E";
}
inline void goRight(int n = 1) {
    cout << "\e[" << n << "C";
}
inline void goLeft(int n = 1) {
    cout << "\e[" << n << "D";
}
inline void beep() {
    cout << char(7);
}
inline void clear() {
    cout << "\e[1J";
}
