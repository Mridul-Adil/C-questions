/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // allocating memory to p
    int *p = (int *)malloc(8 * sizeof(int));

    *p = 100;

    // deallocated the space allocated to p
    free(p);

    // core dump/segmentation fault
    //  as now this statement is illegal
    *p = 110;

    return 0;
}
