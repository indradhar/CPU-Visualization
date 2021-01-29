#include<stdio.h>
#include<stdlib.h>
int p_no[100],art[100],burt[100],comt[100],tat[100],wt[100],size;
void process();
void display();
void main()
{
	int ch;

	while(1)
	{
		printf("1.Enter the process to give the values\n2.display the avg wt time and avg tat\n3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
	    case 1: process();
			break;
			case 2:display();
			break;
			case 3: exit(0);
			default:printf("Enter a valid option\n");

		}
	}
}
void process()
{
	auto void sort();
	int i,j,sum=0;
	p_no[0]=1;
	printf("Enter the number of processess\n");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		p_no[i+1]=p_no[i]+1;
		printf("Enter the arrival time ,Burst time of %d process\n",p_no[i]);
		scanf("%d%d",&art[i],&burt[i]);
	}


	sort();

	void sort()
	{
		for(i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
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
	}

	for(i=0;i<size;i++)
	{
		sum = sum+burt[i];
		comt[i]=sum;
		tat[i]=comt[i]-art[i];
		wt[i]=tat[i]-burt[i];
	}

}

void display()
{
	int i,sumwt=0,sumtat=0;
	for(i=0;i<size;i++)
	{
		sumwt=sumwt+wt[i];
		sumtat=sumtat+tat[i];
	}
	int avgwt=sumwt/size;
	int avgtat=sumtat/size;

	printf("Process number\tArrival time\tBurst time\tcompletion time\tturn around time\twaiting time\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p_no[i],art[i],burt[i],comt[i],tat[i],wt[i]);
	}
	printf("\nAverage waiting time:%d\n",avgwt);
	printf("Average turn around time:%d\n",avgtat);
}
