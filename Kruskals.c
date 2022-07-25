#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[10][10],parent[10];
int find(int);
int uni(int,int);
void main()
{
printf("\n Implementation of kruskals algorithm\n\n");
printf("\n Enter the number of vertices\n");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
}
printf("\n The edges of minimum cost spanning tree are \n\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<n;j++)
{
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
u=find(u);
v=find(v);
if(uni(u,v))
{
printf("\n%d edge(%d%d)=&d\n",ne++,a,b,min);
mincost+=min;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n\t minimum cost=%d\n",mincost);
}
int find(int i)
{
while(parent[i])
i=parent[i];
return i;
}
int uni(int i,int j)
{
if(i=j)
{
parent[i]=i;
return i;
}
return 0;
}
