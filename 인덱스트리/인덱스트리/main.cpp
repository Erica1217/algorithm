//
//  main.cpp
//  인덱스트리
//
//  Created by 김유진 on 2020/04/25.
//  Copyright © 2020 김유진. All rights reserved.
//

/*구간에서 최소값 찾는 프로그램을 짜봤습니다.
 입력 형식은 다음과 같습니다.
 첫번째 줄에 숫자의 갯수 n과 질문의 갯수 q가 입력됩니다.
 다음줄에 n개의 숫자가 주어지고
 다음줄부터 q개의 줄에 숫자 i j가 들어옵니다. i,j는 i~j사이에서 최소값을 찾아달라는 뜻입니다.
 */
#include<stdio.h>
#define Maxn 1000
#define MaxTn 256
#define ST 127
#define Max 0x7fffffff

void init(void);
void process(void);
void out(void);

int n;
int data[Maxn + 1];
int Tree[MaxTn + 1];

int main(void){
    init();
    process();
    out();
    return 0;
}

void init(void){
    int i , q , l , r , k;
    FILE *in = fopen("mininpart10.in" , "r");
    FILE *op = fopen("mininpart10.out" , "w");
    fscanf(in , "%d %d" , &n , &q);
    for(i=1; i<=n; i++){
        fscanf(in , "%d" , &data[i]);
    }
    for(i=1; i<=MaxTn; i++){
        Tree[i] = Max;
    }
    for(i=1; i<=n; i++){
        //Leaf노드 중 i번째 노드의 위치는 ST + i
        k = ST + i;
        while(k > 0 && Tree[k] > data[i]){//Tree[k]가 data[i]보다 크다면(갱신 해야 하니까)
            Tree[k] = data[i];
            k>>=1;//k>>=1 이 연산은 k/=2이것과 같지만 더 빠릅니다
        }
    }
    for(i=1; i<=q; i++){
        fscanf(in , "%d %d" , &l , &r);
        l+=ST;
        r+=ST;
        k = Max;//일단 Max값을 넣습니다.
        while(l < r){//l과 r이 만나거나 엇갈리지 않았다면
            if(l & 1){//l 과 1의 and연산입니다. 이 연산이 0이 아니라 1이 나온다면 l은 홀수라는 뜻이고, 오른쪽 자식이란 뜻입니다.
                if(Tree[l] < k){
                    k = Tree[l];//갱신
                }
                l++;//l 오른쪽으로 이동
            }
            if(!(r & 1)){//r 과 1의 and연산에 not을 붙인겁니다. 이 연산이 0이 아니라 1이 나온다면 r은 짝수라는 뜻이고, 왼쪽 자식이란 뜻입니다.
                if(Tree[r] < k){
                    k = Tree[r];//갱신
                }
                r--;//r 왼쪽으로 이동
            }
            l>>=1;//위로 올라간다
            r>>=1;//위로 올라간다
        }
        if(l == r){//l과 r이 만났다면
            if(Tree[l] < k){
                k = Tree[l];
            }
        }
        fprintf(op , "%dn" , k);
    }
    fclose(in);
    fclose(op);
}

void process(void){
}

void out(void){
}
