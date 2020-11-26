//
//  main.cpp
//  12100 2048(easy)
//
//  Created by 김유진 on 2020/04/04.
//  Copyright © 2020 김유진. All rights reserved.
//

#include <cstdio>
int n;
int input[30][30]={0,};
int data[8][30][30]={0,};
int result=0;
void func(int num)
{
    if(num==6)
    {
        int max=0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(max<data[num-1][i][j])
                {
                    max = data[num-1][i][j];
                }
            }
        }
        if(max>result)
        {
//            for(int i=0 ; i<6 ; i++)
//            {
//                for(int j=0 ; j<n ; j++)
//                {
//                    for(int k=0 ; k<n ; k++)
//                    {
//                        printf("%d ",data[i][j][k]);
//                    }
//                    printf("\n");
//                }
//                printf("\n");
//            }
//            printf("----------\n");
            result = max;
        }
        return;
    }
    
    for(int i=0 ; i<4 ; i++)
    {
//        복사
        for(int j=0 ; j<n ; j++)
        {
            for(int k=0; k<n ; k++)
            {
                data[num][j][k] = data[num-1][j][k];
            }
        }
        
//        <-
        if(i==0)
        {
            for(int j=0 ; j<n ; j++)
            {
                for(int k=0; k<n ; k++)
                {
                    int a=k+1;
                    while(data[num][j][k]==0 && a<n)
                    {
                        if(data[num][j][a]!=0)
                        {
                            data[num][j][k] = data[num][j][a];
                            data[num][j][a]=0;
                            break;
                        }
                        a++;
                    }
                    if(data[num][j][k]==0)
                    {
                        break;
                    }
                    for(int l=k+1; l<n ; l++)
                    {
                        if(data[num][j][l]!=0)
                        {
                            if(data[num][j][l]== data[num][j][k])
                            {
                                data[num][j][k]*=2;
                                data[num][j][l]=0;
                            }
                            break;
                        }
                    }
                }
            }
        }
//        ->
        else if(i==1)
        {
            for(int j=0 ; j<n ; j++)
            {
                for(int k=n-1; k>=0 ; k--)
                {
                    int a=k-1;
                    while(data[num][j][k]==0 && a>=0)
                    {
                        if(data[num][j][a]!=0)
                        {
                            data[num][j][k] = data[num][j][a];
                            data[num][j][a]=0;
                            break;
                        }
                        a--;
                    }
                    if(data[num][j][k]==0)
                    {
                        break;
                    }
                    for(int l=k-1; l>=0 ; l--)
                    {
                        if(data[num][j][l]!=0)
                        {
                            if(data[num][j][l]== data[num][j][k])
                            {
                                data[num][j][k]*=2;
                                data[num][j][l]=0;
                            }
                            break;
                        }
                    }
                }
            }
        }
//        ↓
        else if(i==2)
        {
            for(int j=0 ; j<n ; j++)
           {
               for(int k=n-1; k>=0 ; k--)
               {
                   int a=k-1;
                   while(data[num][k][j]==0 && a>=0)
                   {
                       if(data[num][a][j]!=0)
                       {
                           data[num][k][j] = data[num][a][j];
                           data[num][a][j]=0;
                           break;
                       }
                       a--;
                   }
                   if(data[num][k][j]==0)
                   {
                       break;
                   }
                   for(int l=k-1; l>=0 ; l--)
                   {
                       if(data[num][l][j]!=0)
                       {
                           if(data[num][l][j]== data[num][k][j])
                           {
                               data[num][k][j]*=2;
                               data[num][l][j]=0;
                           }
                           break;
                       }
                   }
               }
           }
        }
//        ↑
        else if(i==3)
        {
            for(int j=0 ; j<n ; j++)
            {
                for(int k=0; k<n ; k++)
                {
                    int a=k+1;
                    while(data[num][k][j]==0 && a<n)
                    {
                        if(data[num][a][j]!=0)
                        {
                            data[num][k][j] = data[num][a][j];
                            data[num][a][j]=0;
                            break;
                        }
                        a++;
                    }
                    if(data[num][k][j]==0)
                    {
                        break;
                    }
                    for(int l=k+1; l<n ; l++)
                    {
                        if(data[num][l][j]!=0)
                        {
                            if(data[num][l][j]== data[num][k][j])
                            {
                                data[num][k][j]*=2;
                                data[num][l][j]=0;
                            }
                            break;
                        }
                    }
                }
            }
        }
//        printf("[%d]\n",i);
//        for(int j=0 ; j<n ; j++)
//        {
//            for(int k=0 ; k<n ; k++)
//            {
//                printf("%d ",data[num][j][k]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        func(num+1);
    
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&input[i][j]);
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j< n ;j++)
        {
            data[0][i][j] = input[i][j];
        }
    }
    func(1);
    printf("%d",result);
}
