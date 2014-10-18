#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<char*> words;

bool comp(char* a, char* b)
{
    size_t len_a = strlen(a), len_b = strlen(b);
    size_t min_len = min(len_a,len_b), max_len = max(len_a,len_b);
    char max_c = '\0';

    for(size_t i = 0; i<min_len;++i)
    {
        if(a[i]>b[i])
        {
            return true;
        }
        if(a[i]<b[i])
        {
            return false;
        }
        if(a[i]>max_c)
        {
            max_c=a[i];
        }
    }
    if(len_a == len_b)
    {
        return true;
    }
    if(len_a < len_b)
    {
        for(int i=min_len;i<max_len;++i)
        {
            if(b[i]>max_c)
            {
                return false;
            }
            if(b[i]<b[0])
            {
                return true;
            }
        }
        return false;
        /*if(b[min_len]>=b[0])
        {
            return false;
        }
        else
        {
            return true;
        }*/
    }
    else
    {
        for(int i=min_len;i<max_len;++i)
        {
            if(a[i]>max_c)
            {
                return true;
            }
            if(a[i]<a[0])
            {
                return false;
            }
        }
        return true;
        /*if(a[min_len]>=a[0])
        {
            return true;
        }
        else
        {
            return false;
        }*/
    }
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w+",stdout);

    char* s = new char[100];    
    int i=0;
    while(scanf("%s",s)!=EOF)
    {
        words.push_back(s);
        s = new char[100];
    }

    sort(words.begin(),words.end(),comp);

    for(vector<char*>::iterator i=words.begin();i!=words.end();++i)
    {
        printf("%s\n", *i);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
