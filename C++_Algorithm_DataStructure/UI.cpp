#include "UI.h"

using namespace ymy1248;

void UI::run() {
    #if DEBUG
    cout << "UI run()" << endl;
    #endif
    OutLine outlineSel = outline();

    switch(outlineSel) {
        case ALGORITHM:
            algorithm();
            break;
        case DATA_STRUCTURE:
            dataStructure();
            break;
    }

}

OutLine UI::outline() {
    clear();
    gotoXY(1,1);
    for (size_t i = 0; i < OUTLINE.size(); ++i) {
        cout << OUTLINE[i] << endl;
    }
    gotoXY(1,1);
    Cmd cmd = getCmd(OUTLINE.size());
    return static_cast<OutLine>(cmd);
}

Alg UI::algorithm() {
    clear();
    gotoXY(1,1);
    for (size_t i = 0; i < ALG.size(); ++i) {
        cout << ALG[i] << endl;
    }
    gotoXY(1,1);
    Cmd cmd = getCmd(ALG.size());
    return static_cast<Alg>(cmd);
}

Ds UI::dataStructure() {
}

Cmd UI::getCmd(size_t selNum) const {
    size_t sel = 0;
    system("stty raw");
    #if DEBUG 
    cout << "cmd: " << cmd << endl;
    #endif

    while (true) {
        char c = getchar();
        switch(c) {
            case 'h':
                goLeft();
                break;
            case 'j':
                if (sel < selNum - 1) {
                    goDown();
                    sel++;
                } else {
                    beep();
                }
                break;
            case 'k':
                if (sel > 0) {
                    goUp();
                    sel--;
                } else {
                    beep();
                }
                break;
            case 'l':
                goRight();
                break;
            case 'q':
                system("stty cooked");
                break;
            case 13:
                // ascii for enter
                return static_cast<Cmd>(sel);
                break;
            case ':':
                // into command mode
                break;
            default:
                cout << "Unknown" << endl;
                break;
        }
    }
    return static_cast<Cmd>(sel);
}

void UI::gotoXY(int x, int y) const{
    cout << "\e["  << x << ";" << y << "H";
}

void UI::goUp(int n) const{
    cout << "\e[" << n << "F";
    #if DEBUG
    cout << "goUP()";
    #endif
}

void UI::goDown(int n) const{
    cout << "\e[" << n << "E";
}

void UI::goRight(int n) const{
    cout << "\e[" << n << "C";
}

void UI::goLeft(int n) const{ 
    cout << "\e[" << n << "D";
}

void UI::beep() const {
    cout << char(7);
}

void UI::clear() const {
    cout << "\e[1J";
}
