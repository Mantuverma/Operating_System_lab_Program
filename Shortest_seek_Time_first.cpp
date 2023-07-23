
#include<iostream>
#include<cstdlib> 
#include<climits> 
#include<cstring> 
#include<vector>
#include<iomanip>  
//#include<bits/stdc++.h>
using namespace std;
int findclosestTrack(int initial_pos, vector<bool> visited,vector<int> request_queue,int n)
{
  int min=INT_MAX,min_index=-1;  
  for(int i=0;i<n;i++)
  {
      if(visited[i] == false && abs(initial_pos - request_queue[i]) < min)
      {
          min = abs(initial_pos - request_queue[i]);
          min_index = i;
      }
  }
  return min_index;

}

int applySSTFAlgo(vector<int> request_queue, int initial_pos,vector<bool> visited,vector<int> &seek_sequence,int n)
{
    int i=0;            //used in seek_sequence
    int completed=0,total_head_movement=0;
    while(completed!=n)
    {
      int min_index=findclosestTrack(initial_pos,visited,request_queue,n);
      //find total head movement
      total_head_movement += abs(initial_pos - request_queue[min_index]);
      initial_pos = request_queue[min_index];
      seek_sequence[i++] = request_queue[min_index];
      visited[min_index]=true;    // so that we don't pick this Track in next iteration
      completed++;
    }    
    
    return total_head_movement; 
}


int main()
{
    cout << fixed << setprecision(2);
    int total_Tracks,total_head_movement=0,initial_pos,n,completed=0,i;
    
    // *********** INPUT ********** 
    cout<<endl<<"Enter the total no. of Track in HDD:"<<endl;
    cin>>total_Tracks;
    if(total_Tracks <= 0) 
    {
      cout<<"Total Track must be greater than 0";
      exit(0);
    }
    cout<<"\nEnter the no. of Track to enter in Request queue:\n";
    cin>>n;

    vector<int> request_queue;  
    vector<int> seek_sequence(n);

    cout<<"\nEnter the Track no. in Request queue :\n";
    for(int i=0;i<n;i++)
    {
     int Track;
     cin>>Track;   
     request_queue.push_back(Track);
    }
    cout<<"\nEnter the initial Position of RW head: ";
    cin>>initial_pos;
    
    vector<bool> visited(n,false);        //to keep track of visited Track
   
    
    if(initial_pos < 0 || initial_pos > total_Tracks - 1)
    {
        cout<<"Wrong Initial Position Enetered !!";
        exit(0);
    }
    total_head_movement = applySSTFAlgo(request_queue,initial_pos,visited,seek_sequence,n);
    
   // *********** OUTPUT ********** 
   cout<<"\n\n*********** OUTPUT **********";
   cout<<"\nSeek Sequence: ";
   for(int i=0;i<n;i++)
     cout<<seek_sequence[i]<<" ";
   cout<<"\nTotal No. of Head Movements: "<<total_head_movement;
   cout<<"\nAverage head movements:"<<total_head_movement/n;

   return 0;
}