//
//  main.cpp
//  SCPC 오르락내리락
//
//  Created by 김유진 on 21/06/2019.
//  Copyright © 2019 김유진. All rights reserved.
//

#include <stdio.h>

int Answer;

int main(void)
{
    freopen("/Users/kim-yujin/Documents/알고리즘/SCPC 오르락내리락/SCPC 오르락내리락/input.txt","r",stdin);
    int T, test_case;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        int a,b;
        int n=0;
        scanf("%d %d",&a,&b);
        for(int i=0 ; a!=1 && b!=1 ; i++){
            if(a!=0){
                if(a%2==1){
                    n++;
                    a++;
                }
                n++;
                a/=2;
            }
            
            if(b!=0){
                if(b%2==1){
                    n++;
                    b++;
                }
                n++;
                b/=2;
            }
            printf("%d %d %d\n",a,b,n);
        }
        Answer=n;

        // Print the answer to standard output(screen).
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
    }
    
    return 0;//Your program should return 0 on normal termination.
}
