#include "consts.h"
#include "UI.h"

using namespace ymy1248;

void UI::run() {
    cout << MOVE << endl;
    for (size_t i = 0; i < OUTLINE.size(); ++i) {
        cout << OUTLINE[i] << endl;
    }
    while (true) {
        char cmd = getc(cin);
        switch(cmd) {
            case 'h':
                goLeft();
                break;
            case 'j':
                goDown();
                break;
            case 'k':
                goUp();
                break;
            case 'l':
                goRight();
                break;
        }
    }
}


char UI::getc(istream &istr) {
    char ch;
    setKeyPress();
    istr.unsetf(ios_base::skipws);
    istr >> ch;
    istr.setf(ios_base::skipws);
    resetKeyPress();
    return ch;
}

void UI::setKeyPress() {
    struct termios new_settings;
    tcgetattr(0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_cflag &= (~ICANON);
    new_settings.c_lflag &= (~ECHO);
    new_settings.c_cc[VTIME] = 0;
    tcgetattr(0, &stored_settings);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);
}

void UI::resetKeyPress() {
    tcsetattr(0, TCSANOW, &stored_settings);
}

void UI::gotoXY(int x, int y) {
    cout << "\e["  << x << ";" << y << "F";
}

void UI::goUp(int n) {
    cout << "\e[" << n << "A";
}

void UI::goDown(int n) {
    cout << "\e[" << n << "B";
}

void UI::goRight(int n) {
    cout << "\e[" << n << "C";
}

void UI::goLeft(int n) { 
    cout << "\e[" << n << "D";
}
