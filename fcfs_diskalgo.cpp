#include<iostream>
using namespace std;
int main()
{
    int total_head_movement=0,initial_pos,n ;
    cout<<"\nEnter the no. of Track in Request queue:\n";
    cin>>n;
    int request_queue[n]; 
    cout<<"\nEnter the Track no. in Request queue :\n";
    for(int i=0;i<n;i++)
        cin>>request_queue[i];
    cout<<"\nEnter the initial Position of RW head: ";
    cin>>initial_pos;
    for(int i=0;i<n;i++)
    {
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }    
   cout<<"\nTotal No. of Head Movements ="<<total_head_movement;
   cout<<"\nAverage head movements = "<<(float)total_head_movement/n;
   return 0;
}