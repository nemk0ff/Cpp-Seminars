#include <iostream>
#include <queue>
#include <string>

using namespace std;

string predictPartyVictory(string senate) {
    queue<int> RQueue, DQueue;
    int n = senate.size();

    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            RQueue.push(i);
        } else {
            DQueue.push(i);
        }
    }

    while (!RQueue.empty() && !DQueue.empty()) {

        int R_index = RQueue.front();
        int D_index = DQueue.front();

        RQueue.pop();
        DQueue.pop();

        if (R_index < D_index) {
            RQueue.push(R_index + n);
        }
        else {
            DQueue.push(D_index + n);
        }
    }

    return RQueue.empty() ? "Democrats" : "Republican";
}

int main() {
    string senate1 = "RD";
    string senate2 = "RDD";
    string senate3 = "DDDDRRRRRRR";

    cout << predictPartyVictory(senate1) << endl;  // Republican
    cout << predictPartyVictory(senate2) << endl;  // Democrats
    cout << predictPartyVictory(senate3) << endl;  // Democrats

    return 0;
}


