
#include<iostream>
using namespace std;
int main()
{
 int p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n;
 float awt=0,atat=0;
 cout<<"enter no of proccess you want:";
 cin>>n;
 cout<<"enter  the process id of : "<<n;
 for(i=0;i<n;i++)
 {
    cin>>p[i];
 }
 cout<<"enter arrival time of : "<<n;
 for(i=0;i<n;i++)
 {
    cin>>at[i];
 }
 cout<<"enter  burst time of : "<<n;
 for(i=0;i<n;i++)
 {
    cin>>at[i];
 }
 // sorting atbt
 for(i=0;i<n;i++)
 {
    for(j=0;j<(n-i);j++)
    {
        if(at[j]>=at[j+1])
        {
            temp=p[j+1];
            p[j+1]=p[j];
            p[j]=temp;
            temp=at[j+1];
            at[j+1]=at[j];
            at[j]=temp;
            temp=bt[j+1];
            bt[j+1]=bt[j];
            bt[j]=temp;
        }
    }
}
 /* calculating 1st ct */
 ct[0]=at[0]+bt[0];
 for(i=1;i<n;i++)
 { 
 
    temp=0;
    if(ct[i-1]<at[i])
    {
        temp=at[i]-ct[i-1];
    }
    ct[i]=ct[i-1]+bt[i]+temp;
 }
 /* calculating tat and wt */
 cout<<"\np\t A.T\t B.T\t C.T\t TAT\t WT";
 for(i=0;i<n;i++)
 {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    atat+=tat[i];
    awt+=wt[i];
 }
 atat=atat/n;
 awt=awt/n;
 for(i=0;i<n;i++)
 {
    cout<<"\n"<<"\t"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
 }
 cout<<"naverage turnaround time is",atat;
 cout<<"\naverage wating timme is ",awt;
 return 0;
}