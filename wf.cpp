#include<iostream>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int mode;
int torf=1;
struct word
{
    long long cnt;
    char W[50];
} Word[100000];
bool cmp(word a,word b)
{
    if(a.cnt>b.cnt)
        return true;
    return false;
}
char str[50];
char str1[50];
void fcounter()
{
    long long total=0;
    long long num=0;
    char *out = "out.txt.wangyp";
    // getcwd(out,sizeof(out));
    // strcat(out,"\\");
    // strcat(out,"out.txt.wangyp");
    while(~scanf("%s",str))
    {
        int len=strlen(str);
        int j=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            if(str[i]>='a'&&str[i]<='z')
            {
                str1[j++]=str[i];
            } //转换成小写
            else
            {
                str1[j]='\0';
                if(str1[0]=='\0')
                    continue;
                else
                    total++;
                bool flag=true;
                for(int i=0; i<num; i++)
                {
                    if(strcmp(Word[i].W,str1)==0)
                    {
                        Word[i].cnt++;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    strcpy(Word[num].W,str1);
                    Word[num].cnt=1;
                    num++;
                }
                j=0;
            }
        }
        // 知道了，这边应该是完整单词吧
        str1[j]='\0';
        if(str1[0]=='\0')
        {
            continue;
        }

        bool flag=true;
        for(int i=0; i<num; i++)
        {
            if(strcmp(Word[i].W,str1)==0)
            {
                Word[i].cnt++;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            strcpy(Word[num].W,str1);
            Word[num].cnt=1;
            num++;
        }
    }

    sort(Word,Word+num,cmp);
    //printf("2");
    freopen(out,"w",stdout);
    //printf("3");
    total=num;
    if(num>20)
        num=20;
    printf("total %ld\n",total);
    for(int i=0; i<num; i++)
    {
        printf("%s %d\n",Word[i].W,Word[i].cnt);
    }
}
int main(int argc, char *argv[])
{
    char string3[30];
    mode=1;
    if(argc==2)
    {
        strcpy(string3,argv[1]);
        if(strcmp(string3,"-s")==0)
        {
            fcounter();
            mode=3;
        }

    }
    else
        cout << "ERROR!" << endl;
    return 0;
}
