#include<stdio.h>
#include<stdlib.h>
int main()
{
system("getmac");
int*p=malloc(2*sizeof(int));
p[0]=10;
p[1]=20;
p=realloc(p,4*sizeof(int));
p[2]=30;p[3]=40;
for(int i=0;i<4;i++)
printf("%d ",p[i]);
return 0;
}
