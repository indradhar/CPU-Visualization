#include<stdio.h>
#include<stdlib.h>

int pno[30],art[30],burt[30],n;
void process();

void values();

void main()
{
	int ch;
	while(1)
	{
		printf("Enter the choice\n1.Enter values\n2.process\n3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:values();
				break;
			case 2:process();
				break;
			case 3:exit(0);

			default:printf("Enter any valid option\n");
				break;

		}
	}
}
void values()
{
	int i;
	pno[0]=1;
	printf("Enter the number of processess to be done in SJF\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		pno[i+1]=pno[i]+1;
		printf("Enter arrival time and burst time of process %d\n",pno[i]);
		scanf("%d%d",&art[i],&burt[i]);
	}

}
void process()
{
	int i,temp;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(art[i]>art[i+1])
			{
				temp=art[i+1];
				art[i+1]=art[i];
				art[i]=temp;

				temp=pno[i+1];
				pno[i+1]=pno[i];
				pno[i]=temp;

				temp=burt[i+1];
				burt[i+1]=burt[i];
				burt[i]=temp;
			}
		}

	}


}
