#include <iostream>
using namespace std;

void FibIteration(int num) {
    int x = 0;
    int y = 1;
    int z = 0;
    cout << "The fibonacci numbers are: " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
    }
    cout << endl;
}

int FibRecursive(int num) {
    if (num <= 1)
        return num;
    else {
        return FibRecursive(num - 1) + FibRecursive(num - 2);
    }

}
int main()
{
    int num;
    int i = 0;
    cout << "Hello! Please enter a number:" << endl;
    cin >> num;

    bool validInput = false;
    while (!validInput) {
        cout << "How would you like to get the Fibonacci numbers:" << endl << "(0) Iteration" << endl << "(1) Recursion" << endl;
        int answer;
        cin >> answer;

            if (answer != 0 && answer != 1) {
                cout << "Invalid answer. Please try again." << endl;
                continue;
            }
            else {
                switch (answer)
                {
                case 0:
                    FibIteration(num);
                    break;
                case 1:
                    while (i < num) {
                        cout << " " << FibRecursive(i);
                        i++;
                    }
                    break;
                }

                validInput = true;
            }
    }

}
