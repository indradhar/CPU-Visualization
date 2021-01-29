#include<stdio.h>
int p_no[20],art[20],burt[20],compt[20],tat[20],wt[20],ct=0,tburst=0;sol[20],size;
void process();
void display();

void main()
{
  int choice;
  while(1)
  {
    printf("1.Enter the processess for SRTF\n2.Display\n3.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:process();
      break;
      case 2:display();
      break;
      case 3:exit(0);
      default:printf("Enter a valid option\n");
    }
  }
}
void process()
{
  int i,j,n=0;
  p_no[0]=1;
  printf("Enter the number of processess\n");
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
    p_no[i+1]=p_no[i]+1;
    printf("Enter the arrival time and Burst time of %d Process\n",p_no[i]);
    scanf("%d%d",&art[i],&burt[i]);
    tburst=tburst+burt[i];
  }
  for(i=0;i<size-1;i++)
  {
    for(j=0;j<size-i-1)
    {
      if(art[j]>art[j+1])
      {
        int c;
        c=p_no[j];
        p_no[j]=p_no[j+1];
        p_no[j+1]=c;

        c=art[j];
        art[j]=art[j+1];
        art[j+1]=c;

        c=burt[j];
        burt[j]=burt[j+1];
        burt[j+1]=c;
      }
    }
  }

  if(art[0]!=0)
  {
    int temp=art[0];
    for(i=0;i<temp;i++)
    {
      sol[i]=0;
      ct++;
    }
  }
  while(n<=tburt)
  {
    for(i=0;i<ct;i++)
    {

    }
  }
}
