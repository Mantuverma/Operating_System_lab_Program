
#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib> 
#include<algorithm>
using namespace std;

int applySCANAlgo(int total_Tracks, vector<int> request_queue, int initial_pos, vector<int> &seek_sequence, int direction,int n)
{
	int total_head_movement=0;
	vector<int> left, right;	   
	if(direction == 0)
    {
    
        if(initial_pos > *min_element(request_queue.begin(), request_queue.end()))
		   right.push_back(total_Tracks - 1);
        right.push_back(initial_pos);
    }
    else if(direction == 1)
    {
        //find max in request queue
        if(initial_pos < *max_element(request_queue.begin(), request_queue.end()))
		    left.push_back(0);  //here  0 is initial Track of HDD
        left.push_back(initial_pos);
    }

	for (int i = 0; i<n; i++) {
		if (request_queue[i] < initial_pos)
			left.push_back(request_queue[i]);
		if (request_queue[i] > initial_pos)
			right.push_back(request_queue[i]);
	}
  
	// sorting left and right vectors
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	// run the while loop two times one by one scanning right and left of the head
	int completed = 2;
	while (completed--)
    {
        if (direction == 0) 
        {
			for (int i = 0; i < right.size(); i++) 
            {
                // calculate absolute distance
                total_head_movement += abs(initial_pos - right[i]);	
                initial_pos = right[i];
                // appending current track to seek sequence
                seek_sequence.push_back(right[i]); 
            }
            direction = 1;
		}

		else if (direction == 1)
        {
			for (int i = left.size() - 1; i >= 0; i--) 
            {
                // calculate absolute distance
				total_head_movement +=  abs(initial_pos - left[i]);	
                initial_pos = left[i];
                // appending current track to seek sequence
                seek_sequence.push_back(left[i]); 
            }
            direction = 0;
		}
      }  //end of while
    return total_head_movement;
}  //end of applySCANALgo()

int main()
{
    cout << fixed << setprecision(2);
    int total_Tracks,total_head_movement=0,initial_pos,n,direction,pos;
    cout<<"\nEnter the total no. of Tracks in HDD:\n";
    cin>>total_Tracks;

    cout<<"\nEnter the no. of Tracks to enter in Request queue:\n";
    cin>>n;
    
    vector<int> request_queue(n);
    vector<int> seek_sequence;

    cout<<"\nEnter the Tracks no. in Request queue :\n";
    for(int i=0;i<n;i++)
     cin>>request_queue[i];
    cout<<"\nEnter the initial Position of RW head: ";
    cin>>initial_pos;
    cout<<"\nEnter the direction in which Read Write head is moving:\n ";
    cout<<"\nEnter 0 if moving to higher Track else Enter 1: ";
    cin>>direction;

    if(initial_pos < 0 || initial_pos > total_Tracks - 1)
    {
        cout<<"Wrong Initial Position Enetered !!";
        exit(0);
    }
    
    total_head_movement = applySCANAlgo(total_Tracks, request_queue,initial_pos,seek_sequence,direction,n);
    
    
    // *********** OUTPUT ********** 
    cout<<"\n\n*********** OUTPUT **********\n";
    cout<<"\nSeek Sequence: ";
    for(int i=0;i<seek_sequence.size();i++)
     cout<<seek_sequence.at(i)<<" ";

    cout<<"\n\nTotal No. of Head Movements = "<<total_head_movement;
    cout<<"\nAverage head movements = "<<(float)total_head_movement/n;

    return 0;
}