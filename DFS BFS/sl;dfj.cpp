# include <iostream>
using namespace std;
int si, sj, ei, ej, l;
char a[3], b[3];
void bfs()
{
    int queue[70][3];
    int i, j, w = 0;
    long f, r;
    int mark[301][301];
    f = r = -1;
    memset(mark,0,sizeof(mark));
    mark[si][sj] = 1;
    queue[++f][0] = si,queue[f][1] = sj;
    queue[f][2] = 0;
    while(f!=r)
    {
        ++r;
        i = queue[r][0],j = queue[r][1],w = queue[r][2];
        if(i-1>=0)
        {
            if(j-2>=0)
            {
                if(mark[i-1][j-2]==0)
                {
                    mark[i-1][j-2] = 1;
                    queue[++f][0]=i-1,queue[f][1]=j-2,queue[f][2]=w+1;
                    if(i-1==ei&&j-2==ej) 						break;
                }
            }
            if(j+2<l)
            {
                if(mark[i-1][j+2]==0)
                {
                    mark[i-1][j+2] = 1;
                    queue[++f][0]=i-1,queue[f][1]=j+2,queue[f][2]=w+1;
                    if(i-1==ei&&j+2==ej) 						break;
                }
            }
        }
        if(i-2>=0)
        {
            if(j-1>=0)
            {
                if(mark[i-2][j-1]==0)
                {
                    mark[i-2][j-1] = 1;
                    queue[++f][0]=i-2,queue[f][1]=j-1,queue[f][2]=w+1;
                    if(i-2==ei&&j-1==ej) 						break;
                }
            }
            if(j+1<l)
            {
                if(mark[i-2][j+1]==0)
                {
                    mark[i-2][j+1] = 1;
                    queue[++f][0]=i-2,queue[f][1]=j+1,queue[f][2]=w+1;
                    if(i-2==ei&&j+1==ej) 						break;
                }
            }
        }
        if(i+1<l)
        {
            if(j-2>=0)
            {
                if(mark[i+1][j-2]==0)
                {
                    mark[i+1][j-2] = 1;
                    queue[++f][0]=i+1,queue[f][1]=j-2,queue[f][2]=w+1;
                    if(i+1==ei&&j-2==ej) 						break;
                }
            }
            if(j+2<l)
            {
                if(mark[i+1][j+2]==0)
                {
                    mark[i+1][j+2] = 1;
                    queue[++f][0]=i+1,queue[f][1]=j+2,queue[f][2]=w+1;
                    if(i+1==ei&&j+2==ej) 						break;
                }
            }
        }
        if(i+2<l)
        {
            if(j-1>=0)
            {
                if(mark[i+2][j-1]==0)
                {
                    mark[i+2][j-1] = 1;
                    queue[++f][0]=i+2,queue[f][1]=j-1,queue[f][2]=w+1;
                    if(i+2==ei&&j-1==ej) 						break;
                }
            }
            if(j+1<l)
            {
                if(mark[i+2][j+1]==0)
                {
                    mark[i+2][j+1] = 1;
                    queue[++f][0]=i+2,queue[f][1]=j+1,queue[f][2]=w+1;
                    if(i+2==ei&&j+1==ej) 						break;
                }
            }
        }
    }
    cout<<"To get from "<<a<<" to "<<b<<" takes "<<w+1<<" knight moves.\n";
}
int main()
{
    while(cin>>a>>b)
    {
        l = 8;
        si = a[0]-'a';
        sj = a[1]-'1';
        ei = b[0]-'a';
        ej = b[1]-'1';
        if(si!=ei||sj!=ej) 			bfs();
        else 			cout<<"To get from "<<a<<" to "<<b<<" takes 0 knight moves.\n";
    }
    return 1;
}

