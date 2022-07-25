#include<stdio.h>
void msort(int i,int j,int a[],int aux[])
 {
    if(j<=i) 
	{
        return;     
    }
    int mid=(i+j)/2;
    msort(i,mid,a,aux);     
    msort(mid+1,j,a,aux);     
    int pleft=i;       
    int pright=mid+1;        
    int k;     
    for(k=i;k<=j;k++) 
	{
        if(pleft==mid+1) 
		{      
            aux[k]=a[pright];
            pright++;
        } 
		else if(pright==j+1)
		 {        
            aux[k]=a[pleft];
            pleft++;
        } 
		else if(a[pleft]<a[pright]) 
		{       
            aux[k]=a[pleft];
            pleft++;
        } else 
		{        
            aux[k]=a[pright];
            pright++;
        }
    }
    for(k=i;k<=j;k++) 
	{      
        a[k]=aux[k];
    }
}
int main() 
{
  int a[100],aux[100],n,i,d,swap;
  printf("Enter number of elements in the array:\n");
  scanf("%d",&n); 
  printf("Enter %d integers\n",n); 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]); 
  msort(0,n-1,a,aux);
  printf("Printing the sorted array:\n");
  for(i=0;i<n;i++)
     printf("%d\n",a[i]);
  return 0;
}
