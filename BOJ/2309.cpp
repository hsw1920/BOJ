#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int arr[9], sev[7];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i1 = 0; i1 < 9; i1++)
        for (int i2 = i1 + 1; i2 < 9; i2++)
            for (int i3 = i2 + 1; i3 < 9; i3++)
                for (int i4 = i3 + 1; i4 < 9; i4++)
                    for (int i5 = i4 + 1; i5 < 9; i5++)
                        for (int i6 = i5 + 1; i6 < 9; i6++)
                            for (int i7 = i6 + 1; i7 < 9; i7++)
                            {
                                if (arr[i1] + arr[i2] + arr[i3] + arr[i4] + arr[i5] + arr[i6] + arr[i7] == 100)
                                {
                                    sev[0] = arr[i1];
                                    sev[1] = arr[i2];
                                    sev[2] = arr[i3];
                                    sev[3] = arr[i4];
                                    sev[4] = arr[i5];
                                    sev[5] = arr[i6];
                                    sev[6] = arr[i7];
                                }
                            }
    sort(sev, sev + 7);
    for (int i = 0; i < 7; i++)
        printf("%d\n", sev[i]);
    return 0;
}