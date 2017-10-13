#include "Activity.h"

Activity::Activity(vector<const char *> & content)
:_content(content) {
    clear();
    this->gotoXY(1, 1);
    for (size_t i = 0; i < _content.size(); ++i) {
        cout << _content.size() << endl;
    }
}

Cmd Activity::getCmd() const {
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
