#include<iostream>
using namespace std;

const int size = 7490;
const int money[5] = {1, 5, 10, 25, 50};

int main(void)
{
    int n = 0;
    int coin[size] = {0};
    coin[0] = 1;

    for(int i = 0; i < 5; i++)
    {
        for(int j = money[i]; j < size; j++)
        {
            coin[j] += coin[j - money[i]];
        }
    }
    while(cin>>n)
    {
        cout << coin[n] << endl;
    }
    return 0;
}