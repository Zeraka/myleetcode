#include <string>
#include <iostream>
using namespace std;
#define MAX 1000000
int min(int i, int j, int k, int tmp[])
{
    int min = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;

    if (i < 0)
    {
        tmp1 = MAX;
    }
    else
    {
        tmp1 = tmp[i];
    }
    if (j < 0)
    {
        tmp2 = MAX;
    }
    else
    {
        tmp2 = tmp[j];
    }
    if (k < 0)
    {
        tmp3 = MAX;
    }
    else
    {
        tmp3 = tmp[k];
    }

    min = tmp1;
    if (min > tmp2)
        min = tmp2;
    if (min > tmp3)
        min = tmp3;

    return min;
}
int collectcoins(int coins)
{
    int num;
    int tmp[128];

    tmp[0] = 0;
    tmp[1] = 1;
    tmp[2] = 2;
    for (int a = 1; a <= coins; a++)
    {

        tmp[a] = min(a - 1, a - 3, a - 5, tmp) + 1;
    }

    return tmp[coins];
}

int main()
{

    std::cout << collectcoins(15) << std::endl;
}