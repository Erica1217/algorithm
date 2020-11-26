//
//  main.cpp
//  test2
//
//  Created by 김유진 on 2020/03/28.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void)
{
    int numTestCases;
    /* read the number of test cases */
    cin >> numTestCases;
    for(int i=0; i<numTestCases; i++)
    {
        int numData, data;
        int last1Digit = 1;
        cin >> numData;
        for (int j=0; j<numData; j++)
        {
            cin >> data;
            last1Digit *= data;
            last1Digit %= 10;
        }
        cout << last1Digit%10 << endl;
    }
    return 0;
}
