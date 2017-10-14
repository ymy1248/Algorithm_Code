#include <iostream>
#include "Sort.h"
#include "Activity.h"

using namespace std;
using namespace ymy1248;

class AlgAct : public Activity {
public:
    AlgAct() : Activity(ALG){};
    AlgAct(ActInput input) : Activity(ALG){};
    // Overide virtual run()
    RunOutput run() {
        showView();
        Cmd cmd = getCmd();
        
        switch (cmd) {
            case SELECT_0: {
                RunOutput out = { false };
                return out;
            }
            default:
                // TODO
                cout << "TODO" << endl;
                break;
        }
        RunOutput out = { false };
        return out;
    }
};

class DsAct : public Activity {
public:
    DsAct() :Activity(DS){};
    DsAct(ActInput input) : Activity(DS){};
    // Overide virtual run()
    RunOutput run(){
        showView();
        Cmd cmd = getCmd();
        switch (cmd) {
            case SELECT_0: {
                RunOutput out = { false };
                return out;
            }
            default:
                // TODO
                cout << "TODO" << endl;
                break;
        }
        RunOutput out = { false };
        return out;
    }
};

class OutLineAct : public Activity {
public:
    OutLineAct() : Activity(OUTLINE){};
    // Overide virtual run()
    RunOutput run() {
        bool exit = false;
        while(!exit) { 
            showView();
            Cmd cmd = getCmd();
            switch(cmd) {
                case SELECT_0: {
                    AlgAct algAct;
                    exit = algAct.run().exit;
                    break;
                }
                case SELECT_1: {
                    DsAct dsAct;
                    exit = dsAct.run().exit;
                    break;
                }
                default: {
                    cout << "TODO" << endl;
                    break;
                }
            }
        }
    }
};

int main() {
    OutLineAct outLineAct;
    outLineAct.run();
}

