#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

const int inf = INT_MAX;

vector<int> hungarian(const int* table, const int& n)
{
    vector<int> deltaByHeight(n, 0), deltaByWidth(n, 0);
    vector<int> usingIndices(n, -1);

    for(int i = 0; i < n; i++)
    {
        vector<int> links(n, -1);
        vector<int> mins(n, inf);
        vector<int> visited(n, 0);
        int usedI = i, usedT = -1, t;

        while(usedI != -1)
        {
            t = -1;

            for(int k = 0; k < n; k++)
            {
                if(!visited[k])
                {
                    if(table[usedI*n+k] - deltaByHeight[usedI] - deltaByWidth[k] < mins[k])
                    {
                        mins[k] = table[usedI*n+k] - deltaByHeight[usedI] - deltaByWidth[k];
                        links[k] = usedT;
                    }
                    if((t==-1) || (mins[k] < mins[t]))
                    {
                        t = k;
                    }
                }
            }

            int delta = mins[t];

            for(int k = 0; k < n; k++)
            {
                if(visited[k])
                {
                    deltaByHeight[usingIndices[k]] += delta;
                    deltaByWidth[k] -= delta;
                }
                else
                {
                    mins[k] -= delta;
                }
            }

            deltaByHeight[i] += delta;
            visited[t] = 1;
            usedI = usingIndices[t];
            usedT = t;

        }

        for(; links[t] != -1; t = links[t])
        {
            usingIndices[t] = usingIndices[links[t]];
        }
        usingIndices[t] = i;
    }
    return usingIndices;
}

int main()
{
    freopen("assignment.in","r",stdin);
    freopen("assignment.out","w+",stdout);


    int n;
    scanf("%d",&n);
    int * table = new int[n*n];

    for(int i=0;i<n*n;++i){
        scanf("%d",table+i);
    }

    vector<int> answer = hungarian(table,n);

    unsigned answerSum=0;

    for(int i=0;i<n;++i)
    {
        answerSum += table[answer[i]*n+i];
    }

    printf("%u\n",answerSum);

    for(int i=0;i<n;++i){
        printf("%d %d\n",answer[i]+1,i+1);
    }


    delete[] table;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
