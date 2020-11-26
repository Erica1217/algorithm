//
//  main.cpp
//  2535 아시아 정보올림피아드
//
//  Created by 김유진 on 2020/01/14.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int countryId;
    int studentId;
    int score;
};

bool compare(Student s1, Student s2){
    if(s1.score > s2.score)
        return true;
    return false;
}

int main()
{
    int n;
    vector<Student> data;
    int check[200]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        Student s;
        scanf("%d %d %d",&s.countryId, &s.studentId, &s.score);
        data.push_back(s);
    }
    
    sort(data.begin(),data.end(),compare);
    
    int a=0;
    for(int i=0 ; i<n ; i++)
    {
        int id = data[i].countryId;
        if(check[id] < 2)
        {
            Student s = data[i];
            printf("%d %d\n",s.countryId, s.studentId);
            check[id]++;
            a++;
        }
        
        if(a==3)
        {
            return 0;
        }
    }
}
