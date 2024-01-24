#include &lt;stdio.h&gt;
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
int main()
{
printf(&quot;\nEnter the number of nodes:&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter the adjacency matrix::\n&quot;);
for(i=1;i&lt;=n;i++)
for(j=1;j&lt;=n;j++)
{
scanf(&quot;%d&quot;,&amp;cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
visited[1]=1;
printf(&quot;\n&quot;);
while(ne&lt;n)
{
for(i=1,min=999;i&lt;=n;i++)
for(j=1;j&lt;=n;j++)
if(cost[i][j]&lt;min)
if(visited[i]!=0)
{
min=cost[i][j];

a=u=i;
b=v=j;
}
if(visited[u]==0||visited[v]==0)
{
printf(&quot;\nEdge %d:(%d %d) cost:%d&quot;,ne++,a,b,min);
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf(&quot;\nMinimum cost:%d\n&quot;,mincost);
return 0;
}
Enter the number of nodes:4
Enter the adjacency matrix::0
2
13
3
2
0
1
11
13
1
0
7
3
11
7
0
1
Edge 1:(1 2) cost:2
Edge 2:(1 4) cost:3
Edge 3:(2 3) cost:11
Minimum cost:16
