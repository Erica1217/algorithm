//
//  main.cpp
//  카카오1
//
//  Created by 김유진 on 2020/09/12.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLower(char a)
{
    return 'a'<=a && a<='z';
}

bool isNumber(char a)
{
    return '0'<=a && a<='9';
}

string solution(string new_id) {
    string lowerid=new_id;
    int check[1010]={0,};
    
    for(int i=0 ; i<new_id.size() ; i++)
    {
        lowerid[i] = tolower(lowerid[i]);
        if(!(isLower(lowerid[i]) ||
           isNumber(lowerid[i]) ||
           lowerid[i]=='-' ||
           lowerid[i]=='_' ||
                  lowerid[i]=='.'))
        {
            check[i]=1;
        }
    }
    
    bool beforeDot=false;
    for(int i=0 ; i<new_id.size() ; i++)
    {
        if(check[i]==1)
            continue;
        if(lowerid[i]=='.')
        {
            if(beforeDot)
            {
                check[i]=1;
            }
            beforeDot=true;
            continue;
        }
        beforeDot=false;
    }
    
    string answer="";
    for(int i=0; i<lowerid.size() ; i++)
    {
        if(check[i]==0)
        {
            answer = answer+lowerid[i];
        }
    }
    if(answer[0]=='.')
    {
        answer.erase(answer.begin());
    }
        
    if(answer[answer.size()-1]=='.')
    {
        answer.erase(answer.end()-1);
    }

    
    if(answer.size()==0)
    {
        answer='a';
    }
    if(answer.size()>=16)
    {
        //마침표
        int end=15;
        end -= answer[14]=='.'?1:0;
        answer = answer.substr(0,end);
    }
    if(answer.size()<=2)
    {
        char w = answer[answer.size()-1];
        int s=answer.size();
        for(int i=s; i<3 ; i++)
        {
            answer = answer+w;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<solution("...!@BaT#*..y.abcdefghijklm")<<endl;
    cout<<solution("z-+.^.")<<endl;
    cout<<solution("=.=")<<endl;
    cout<<solution("123_.def")<<endl;
    cout<<solution("abcdefghijklmn.p")<<endl;
    return 0;
}
