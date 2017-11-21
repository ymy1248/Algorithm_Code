#include "template.h"

int main() {
    priority_queue<pair<int, string>> pq;
    pq.push(pair<int,string>(98, "99"));
    pq.push(pair<int,string>(97, "99"));
    pq.push(pair<int,string>(96, "99"));
    pq.push(pair<int,string>(100, "100"));
    pq.push(pair<int,string>(99, "99"));

    cout << pq.top().first << endl;
    pq.pop();
    cout << pq.top().second << endl;
}
