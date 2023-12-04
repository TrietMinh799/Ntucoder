#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    string res =  "";
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        temp += (i % 2 == 0 ? "W" : "B");
        if (temp == "W")
            for (int j = 1; j < n; j++)
                temp += (j % 2 == 0 ? "W" : "B");
        else
            for (int j = 1; j < n; j++)
                temp += (j % 2 == 1 ? "W" : "B");

        for(int i = 0; j < 3; j++) {

        }
    }

    return 0;
}
