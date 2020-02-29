#include <stdio.h>
#include <stdlib.h>

int main()
{
int a[100],b[100],c[200],c1[100],c2[100],i=0,j=0,m,n,k,k1,k2=0,i1,count=0,x,y,comp1=0,comp2=0,comp3=0,comp;
FILE *in;
FILE *op;
in=fopen("file1","r");
   while(!feof(in)){
fscanf(in,"%d",&x);
a[i]=x;
i++;
}
fclose(in);
FILE *fp;
 fp=fopen("file2","r");
  while(!feof(fp))
{
fscanf(fp,"%d",&y);
b[j]=y;
j++;
}
fclose(fp);
m=i;n=j;
i=0;j=0;k=0,k1=0,k2=0;
 while((i<m)&&(j<n))
 {
if(a[i]<b[j])
     {
         c[k]=a[i];
         i++;k++;comp1++;
     }
     else if(b[j]<a[i])
     {

         c[k]=b[j];
         j++;k++;comp1++;
     }
     else{
    c[k]=a[i];
   c1[k1]=a[i];
    i++;j++;k1++;k++;comp2++;
    }
 }
 if(i!=m)
 {
    for(i1=i;i1<m;i1++){
    c[k]=a[i1];
    k++;
    }
    }
 if(j!=n)
 {
    for(i1=j;i1<n;i1++){
    c[k]=b[i1];
    k++;
    }
 }
for(i=0;i<m;i++)
{
    for(j=0;j<k1;j++)
    {
        if(a[i]==c1[j])
        {
            count++;comp3++;
            break;
    }
    }
if(count==0){
comp3++;
        c2[k2]=a[i];
        k2++;
}
else
count=0;
}
op=fopen("file3","w");
fprintf(op,"AUB :{");
 for(i=0;i<k;i++){
    while(c[i]==c[i+1])
    {
    i++;
 }
 fprintf(op,"%d,",c[i]);
}
fprintf(op,"}");
fprintf(op,"\nA^B :{");
for(i=0;i<k1;i++){
    while(c1[i]==c1[i+1]){
    i++;
    }
 fprintf(op,"%d,",c1[i]);
}
fprintf(op,"}");
fprintf(op,"\nA-B :{");
for(i=0;i<k2;i++){
    while(c2[i]==c2[i+1])
    {
    i++;
}
 fprintf(op,"%d,",c2[i]);
}
comp=comp1+comp2+comp3;
fprintf(op,"}");
fprintf(op,"\nNo. of comparisions for AUB are ");
fprintf(op,"%d",comp1);
fprintf(op,"\nNo. of comparisions for A^B are ");
fprintf(op,"%d",comp2);
fprintf(op,"\nNo. of comparisions for A-B are ");
fprintf(op,"%d",comp3);
fprintf(op,"\nTotal no. of comparisions are ");
fprintf(op,"%d",comp);
fclose(op);
    return 0;
}
