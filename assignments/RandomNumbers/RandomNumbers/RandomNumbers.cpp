#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	cout <<"Unix time stamp in seconds: "<< time(0) << endl;
	cout << endl;
	srand(time(0));
	for (int i = 0; i < 58; i++)
	{
		i++;
		int n = rand() % 20 + 1;
		cout << n << endl;
	}
	return 0;
}

