//sorted array
#include<stdio.h>
void main()
{
 int i,j,n1,n2,n3,k=0,temp;
 int a[10],b[10],c[20];
 printf("\n Enter the size of first array: ");
 scanf("%d",&n1);
 printf("\n Enter the size of second array: ");
 scanf("%d",&n2);
 n3=n1+n2;
 printf("\n Enter the first array element: ");
  for(i=0;i<n1;i++)
  {
  scanf("%d",&a[i]);
  c[k]=a[i];
  k++;
  }
 printf("\n Enter the second array element: ");
  for(i=0;i<n2;i++)
 {
  scanf("%d",&b[i]);
  c[k]=b[i];
  k++;
  }
 printf("\nMerged array:\n ");
   for(i=0;i<n3;i++){
    printf("%d\t",c[i]);
   }
   printf("\n");
 printf("After Sorting\n");
   for(i=0;i<n3;i++){
    for(j=0;j<n3;j++){
     if(c[i]<c[j])
     {
      temp=c[i];
      c[i]=c[j];
      c[j]=temp;
     }
    }}
   for(i=0;i<n3;i++)
    printf("%d\t",c[i]);
} 