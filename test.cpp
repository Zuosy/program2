#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    // cout << argc << endl;
    map<string, int> word;
    word["HELLO"] = 2;
    word["zuo"] = 3;
    map<string, int>::iterator p = word.begin();
    for (;p != word.end(); ++p)
    {
        cout << p->first << ", " << p->second << endl;
    }




    return 0;
}