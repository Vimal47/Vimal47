#include<stdio.h>
#include<conio.h>
int main()
{

int i,n,j,min,line[10],line1[10],p[10]={1,2,3,4,5,6,7,8,9,10};
int B_T[1000],A_V_T[1000],W_T[1000],temp,T_A_T[10];
int bt=0,ta=0,sum=0,k=1;
float AVR_W_T=0,AVR_T_A_T=0,T_A_T_SUM=0,W_T_SUM=0;
printf("Enter the Number of processes for shortest job first(NP)-: ");
scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter The Arrival Time Of Process %d : ",i+1);
        -scanf(" %d",&A_V_T[i]);
        printf("Enter The Burst Time Of Process%d : ",i+1);
        scanf(" %d",&B_T[i]);

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A_V_T[i]<A_V_T[j])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=A_V_T[j];
                A_V_T[j]=A_V_T[i];
                A_V_T[i]=temp;
                temp=B_T[j];
                B_T[j]=B_T[i];
                B_T[i]=temp;
            }
        }
    }

    for(j=0;j<n;j++)
    {
        bt=bt+B_T[j];
        min=B_T[k];
    for(i=k;i<n;i++)
    {
        if (bt>=A_V_T[i] && B_T[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                temp=A_V_T[k];
                A_V_T[k]=A_V_T[i];
                A_V_T[i]=temp;
                temp=B_T[k];
                B_T[k]=B_T[i];
                B_T[i]=temp;
            }
    }
    k++;
    }
W_T[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+B_T[i-1];
        W_T[i]=sum-A_V_T[i];
        line[i]=W_T[i];
        W_T_SUM=W_T_SUM+W_T[i];
    }

AVR_W_T=(W_T_SUM/n);
    for(i=0;i<n;i++)
    {
        ta=ta+B_T[i];
        T_A_T[i]=ta-A_V_T[i];
        line1[i]=T_A_T[i];
        T_A_T_SUM=T_A_T_SUM+T_A_T[i];
    }

AVR_T_A_T=(T_A_T_SUM/n);
printf("\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time" );
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t %d\t\t %d\t\t %d",p[i],B_T[i],A_V_T[i],W_T[i],T_A_T[i]);
    }
printf("\n\nAVERAGE WAITING TIME : %.2f",AVR_W_T);
printf("\nAVERAGE TURN AROUND TIME : %.2f\n",AVR_T_A_T);
printf("\n");
    for(i=0;i<T_A_T_SUM/2;i++)
    {
        printf(" ");
    }
    printf("GANTT CHART\n\n");
    line[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(line[i]+line1[i])/2;j++)
        {
            printf(" ");
        }
        
    p[i]=1+(W_T[i]/T_A_T[i]);

    printf("P%d",p[i]);
    }
printf("\n");
printf("0");
    for(i=0;i<n; i++)
    {
        for(j=0;j<line1[i];j++)
        {
            printf("-");
        }
        printf("%d",line1[i]);
    }
    printf("\n");
getch();
return 0;
}

