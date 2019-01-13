//============================================================================
// Name        : Niranjan Vinod Patil.
// Description : Banker Algorithm
// Roll No : CETTYB305
//============================================================================
#include <iostream>
using namespace std;
int main()
{
	int n,r;
	int Max[20][26];
	int Alloc[20][26];
	int avail[26];
	int work[26];
	int need[20][26];
	int safeq[20];
	char resources[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	cout<<"Enter How many processes in system : "<<endl;
	cin>>n;
	cout<<"Enter Fow Many resorces in System : "<<endl;
	cin>>r;
	
	for(int i=0;i<n;i++)
	{
		
		for(int j = 0; j < r; j++)
		{
			cout<<"Enter Maximum instances of resource "<<resources[j];
			cout<<" for process P"<<i<<endl;
			cin>>Max[i][j];
			cout<<"Enter Allocation instances of resource "<<resources[j];
			cout<<" for process P"<<i<<endl;
			cin>>Alloc[i][j];
			need[i][j] = Max[i][j] - Alloc[i][j];
		}
		
	}
    for(int j = 0; j < r; j++)
    {
    	cout<<"Enter Availabel instances of resource "<<resources[j]<<" : "<<endl;
    	cin>>avail[j];
    	work[j] = avail[j];
	}
	
	
	cout<<"Maximum Matrix is : "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Process P"<<i+1<<"\t";
		for(int j = 0; j < r; j++)
		{
		    cout<<resources[j]<<"\t";
			cout<<Max[i][j]<<"\t";
			
		}
		cout<<endl;
	}
	
	cout<<"Allocation Matrix is : "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Process P"<<i+1<<"\t";
		for(int j = 0; j < r; j++)
		{
		    cout<<resources[j]<<"\t";
			cout<<Alloc[i][j]<<"\t";
			
		}
		cout<<endl;
	}
	cout<<"Availabel instances of resource is :"<<endl;
	for(int j = 0; j < r; j++)
	{
		cout<<avail[j]<<endl;
	}
	
	cout<<"NEED Matrix is : "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Process P"<<i+1<<"\t";
		for(int j = 0; j < r; j++)
		{
		    cout<<resources[j]<<"\t";
			cout<<need[i][j]<<"\t";
			
		}
		cout<<endl;
	}
	
    bool finish[n] = {0};
   // int safeSeq[n];
    int count = 0;
    
    while (count < n)
    {
      
        bool found = false;
        for (int p = 0; p < n; p++)
        {
        
            if (finish[p] == 0)
            {
              
                int j;
                for (j = 0; j < r; j++)
                {
                	if (need[p][j] > work[j])
                        break;
				}
                 
                if (j == r)
                {
            
                    for (int k = 0 ; k < r ; k++)
                    {
                    	work[k] += Alloc[p][k];
					}
					
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
 
      
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }
 

    cout << "System is in safe state."<<endl;
	cout<<"sequence is: ";
    for (int i = 0; i < n ; i++)
    {
    	cout <<"P"<<safeSeq[i] << " ";
	}
        
	return 0;
	
}


//============================================================================
//OUTPUT:
/*

Enter How many processes in system :
5
Enter Fow Many resorces in System :
3
Enter Maximum instances of resource A for process P0
7
Enter Allocation instances of resource A for process P0
0
Enter Maximum instances of resource B for process P0
5
Enter Allocation instances of resource B for process P0
1
Enter Maximum instances of resource C for process P0
3
Enter Allocation instances of resource C for process P0
0
Enter Maximum instances of resource A for process P1
3
Enter Allocation instances of resource A for process P1
2
Enter Maximum instances of resource B for process P1
2
Enter Allocation instances of resource B for process P1
0
Enter Maximum instances of resource C for process P1
2
Enter Allocation instances of resource C for process P1
0
Enter Maximum instances of resource A for process P2
9
Enter Allocation instances of resource A for process P2
3
Enter Maximum instances of resource B for process P2
0
Enter Allocation instances of resource B for process P2
0
Enter Maximum instances of resource C for process P2
2
Enter Allocation instances of resource C for process P2
2
Enter Maximum instances of resource A for process P3
2
Enter Allocation instances of resource A for process P3
2
Enter Maximum instances of resource B for process P3
2
Enter Allocation instances of resource B for process P3
1
Enter Maximum instances of resource C for process P3
2
Enter Allocation instances of resource C for process P3
1
Enter Maximum instances of resource A for process P4
4
Enter Allocation instances of resource A for process P4
0
Enter Maximum instances of resource B for process P4
3
Enter Allocation instances of resource B for process P4
0
Enter Maximum instances of resource C for process P4
3
Enter Allocation instances of resource C for process P4
2
Enter Availabel instances of resource A :
3
Enter Availabel instances of resource B :
3
Enter Availabel instances of resource C :
2
Maximum Matrix is :
Process P1      A       7       B       5       C       3
Process P2      A       3       B       2       C       2
Process P3      A       9       B       0       C       2
Process P4      A       2       B       2       C       2
Process P5      A       4       B       3       C       3
Allocation Matrix is :
Process P1      A       0       B       1       C       0
Process P2      A       2       B       0       C       0
Process P3      A       3       B       0       C       2
Process P4      A       2       B       1       C       1
Process P5      A       0       B       0       C       2
Availabel instances of resource is :
3
3
2
NEED Matrix is :
Process P1      A       7       B       4       C       3
Process P2      A       1       B       2       C       2
Process P3      A       6       B       0       C       0
Process P4      A       0       B       1       C       1
Process P5      A       4       B       3       C       1
System is in safe state.
sequence is: 1 3 4 0 2
--------------------------------
Process exited after 50.94 seconds with return value 0
Press any key to continue . . .


*/
