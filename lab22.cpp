#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Commute {
    string commuteFrom;
    string commuteTo;
    int time;
    bool arrival;
};

void printCommute(const Commute& commute);
Commute createCommute();


int main() {
    const int numCommutes = 2;
    vector<Commute> commuteList(numCommutes);

    for (int i = 0; i < numCommutes; ++i) {
        commuteList[i] = createCommute();
    }

    cout << "\nCommute Information:" << endl;
    for (int i = 0; i < numCommutes; ++i) {
        printCommute(commuteList[i]);
    }

    return 0;
}

void printCommute(const Commute& commute) {
    string arrival;
    if (commute.arrival) {
        arrival = "on time";
    } else {
        arrival = "late";
    }
    cout << "Commute from " << commute.commuteFrom << " to " << commute.commuteTo << endl;
    cout << "Duration: " << commute.time << " minutes, Arrival: " << arrival << endl;
}

Commute createCommute() {
    Commute newCommute;
    cout << "Where do you commute from? ";
    cin.ignore();
    getline(cin, newCommute.commuteFrom);
    cout << "Where do you commute to? ";
    getline(cin, newCommute.commuteTo);
    cout << "On average, how many minutes is your commute? ";
    cin >> newCommute.time;
    cout << "When do you normally arrive? (0 for late, 1 for on time): ";
    cin >> newCommute.arrival;
    return newCommute;
}
