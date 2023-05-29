#include<stdio.h>

void find_dup_mode(int a[30],int n)
{
int i,j,count=0;
for(i=0;i<n;i++)
{

   for(j=0;j<n;j++)
   {
       if(a[i]==a[j])

         count++;

   }

    printf("the %d is %d\n",a[i],count);
    count=0;
}

}



int main()
{
  int n,a[30];
  printf("Enter how many nos\n");
  scanf("%d",&n);
  printf("Enter nos\n");
   int i;
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
    printf("The nos are %d\n",a[i]);
   }
 find_dup_mode(a,n);
}
