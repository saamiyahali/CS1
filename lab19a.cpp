#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // constant variables
    const char FILL = '-';
    const int WIDTH = 50;

    // seed the RNG
    srand(time(0));

    // create the array of magic 8 ball responses

    vector<string> magicResp{
        "Yes, of course!",
        "Without a doubt, yes.",
        "You can count on it.",
        "For sure!",
        "Ask me later.",
        "I'm not sure . . .",
        "I can't tell you right now.",
        "I'll tell you after my nap. Zzzzzz",
        "No way!",
        "I don't think so.",
        "Without a doubt . . . no!",
        "The answer is very clearly NOOOOO"
    };

    // greeting message
    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
    cout << "        THE MAGIC 8-BALL HAS BEEN SUMMONED!\n";

    // use a loop to let the user enter their questions
    string question = "yes";
    while (question == "yes")
    {
        cout << setfill(FILL) << setw(WIDTH) << "" << endl;
        cout << "Enter a question below, so that I might answer it:\n";
        getline(cin, question);
        cout << endl << magicResp.at(rand() % magicResp.size()) << endl << endl;
        cout << "Enter yes to continue: ";
        getline(cin, question);
    }

    // final message
    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
    cout << "           THE MAGIC 8-BALL NOW DEPARTS!\n";
    cout << setfill(FILL) << setw(WIDTH) << "" << endl;

    // terminate
    return 0;
}
