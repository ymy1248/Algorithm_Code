#include "Activity.h"

Activity::Activity(const vector<const char *> & content)
:_content(content) {}

Cmd Activity::getCmd() const {
    size_t sel = 0;
    system("stty raw");
    #if DEBUG 
    #endif

    while (true) {
        char c = getchar();
        switch(c) {
            case 'h':
                goLeft();
                break;
            case 'j':
                if (sel < _content.size() - 1) {
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
                system("stty cooked");
                return static_cast<Cmd>(sel);
                break;
            case ':':
                // into command mode
                // TODO
                cout << "TODO" << endl;
                break;
            default:
                cout << "Unknown" << endl;
                break;
        }
    }
    return static_cast<Cmd>(sel);
}

void Activity::showView() {
    clear();
    gotoXY(1, 1);
    for (size_t i = 0; i < _content.size(); ++i) {
        cout << _content[i] << endl;
    }
    gotoXY(1, 1);
}
