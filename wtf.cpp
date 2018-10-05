#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// struct word
// {
//     long long cnt;
//     char W[50];
// };

// word word_struct[10086];
map<string, int> Word;

void fcounter();
bool word_cmp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second > p2.second;
}

int main(int argc, char *argv[])
{
    // char string3[30];
    string str3;
    if (2 == argc)
    {
        str3 = argv[1];
        if (str3 == "-s")
        {
            // cout << "afdsafdasfasdf";
            fcounter();
            cout << "DONE" << endl;
        }
    }
    else
    {
        cout << "你TM输入错了" << endl;
    }

    return 0;
}

void fcounter()
{
    long long total = 0;
    long long num = 0;
    string fileName = "out.txt.zuosy";
    char str[50];
    char str1[50];
    string temp;//以防万一，防止最恶心的error或warning
    while (~scanf("%s",str))
    {
        int len = strlen(str);
        int j = 0;
        for (int i = 0; i < len; ++i)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            if (str[i] >= 'a' && str[i] <= 'z')
                str1[j++] = str[i];
            else
            {
                //str1[j] == '0';
                str1[j] = 0; // 装（找）逼（骂）就该这么写
                j = 0;
                if (str1[0] == 0)
                    continue; // 这里没看懂
                else
                    ++total;
                // 这里直接用map
                temp = str1;
                if (Word.count(temp) > 0)
                    Word[temp]++;
                else
                    Word[temp] = 1;
                // else if (Word.count(temp) == 0)
                //     Word[temp] = 1;
                // else
                //     ;
            }
        }

        // 这里应该是完整的单词
        str1[j] = 0;
        if (str1[0] == 0)
            continue;
        temp = str1;
        if (Word.count(temp) > 0)
            Word[temp]++;
        else
            Word[temp] = 1;

    }

    map<string, int>::iterator p;
    vector<pair<string, int>> word_vector;
    pair<string, int> element;
    for (p = Word.begin(); p != Word.end(); ++p)
    {
        element.first = p->first;
        element.second = p->second;
        word_vector.push_back(element);
    }

    sort(word_vector.begin(), word_vector.end(),
    word_cmp);
    
    total = word_vector.size();
    if (word_vector.size() > 20)
        num = 20;

    ofstream fout;
    fout.open(fileName.c_str()); // 这个函数只支持C风格字符串.
    if (fout.is_open())
        cout << "文件已打开" << endl;
    for (int i = 0; i < num; ++i)
        fout << word_vector[i].first << ' ' 
        << word_vector[i].second
        << endl;
    fout.close();

    //排序， 输出频率最高的前20个
/**
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
*/

}