#include <iostream>
using namespace std;
int main()
{
	
 int ch,B[20],T[20],A[20],W[20];
 float n;
 int complete = 0;
 int t = 0;
 int minm = INT_MAX;
 int shortest = 0;
 int finish_time;
 bool check = false;
        
 cout<<"Enter How Many Process(Assuming NOT MORE THAN 20) in Scheduling :"<<endl;
 cin>>n;

 cout<<"The Scheduling Algorithm choices are : "<<endl;
 cout<<"1. FCFS Scheduling."<<endl;
 cout<<"2. SJF Scheduling"<<endl;
 cout<<"3. Priority Scheduling"<<endl;
 cout<<"4. Round robin Scheduling"<<endl;
 cout<<"Enter your Scheduling Algorithm Choice : "<<endl;
 cin>>ch;
 switch(ch)
 {
 	case 1:
 		for(int i=0;i<n;i++)
        {
           cout<<"Enter Burst Time For Process P"<<(i+1)<<":"<<endl;
           cin>>B[i];
           cout<<"Enter Arrival time For Process P"<<(i+1)<<":"<<endl;
           cin>>A[i];
        } 
		T[0]=B[0];
 		W[0]=0;
        for(int i=1;i<n;i++)
        {
           for(int j=0;j<i;j++)
           {
               T[i]=T[j]+B[i];
    
           }
           W[i]=T[i]-B[i]-A[i];
        }

        float sum;
        sum=0;
        for(int i=0;i<n;i++)
        {
          sum+=W[i];
        }
        float avg;
        avg=sum/n;
        cout<<"Process No"<< "\t"<<"Arrival time"<<"\t"<<" Burst Time"<< "\t" <<" Turned Around Time"<<"\t"<<"Waiting Time"<<endl;
        for(int j=0;j<n;j++)
        {
 	       cout<<j+1<<"\t\t\t"<<A[j]<<"\t\t"<<B[j]<<"\t\t"<<T[j]<<"\t\t"<<W[j]<<endl;
        }
        cout<<"Average : "<<avg;
 		break;
    case 2:
    	for(int i=0;i<n;i++)
        {
           cout<<"Enter Burst Time For Process P"<<(i+1)<<":"<<endl;
           cin>>B[i];
           cout<<"Enter Arrival time For Process P"<<(i+1)<<":"<<endl;
           cin>>A[i];
        } 
        /*
        
        int complete = 0;
 int t = 0;
 int minm = INT_MAX;
 int shortest = 0;
 int finish_time;
 bool check = false;
 
        */
        
        int rt[20];
 
        // Copy the burst time into rt[]
        for (int i = 0; i < n; i++)
            rt[i] = B[i];
  
        
 
    // Process until all processes gets
    // completed
    while (complete != n) 
   {
 
        // Find process with minimum
        // remaining time among the
        // processes that arrives till the
        // current time`
        for (int j = 0; j < n; j++) 
		{
            if ((A[j] <= t) && (rt[j] < minm) && rt[j] > 0)
			{
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
 
        if (check == false)
		{
            t++;
            continue;
        }
 
        // Reduce remaining time by one
        rt[shortest]--;
 
        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
 
        // If a process gets completely
        // executed
        if (rt[shortest] == 0) 
		{
 
            // Increment complete
            complete++;
 
            // Find finish time of current
            // process
            finish_time = t + 1;
 
            // Calculate waiting time
            W[shortest] = finish_time -
                        B[shortest] -
                        A[shortest];
 
            if (W[shortest] < 0)
                W[shortest] = 0;
        }
        // Increment time
        t++;
    }


// calculating turnaround time by adding
    // bt[i] + wt[i] + A[i]
        for (int i = 0; i < n; i++)
         {
          	T[i] = B[i] + W[i] + A[i];
       
        	}
          
        float sum_sjf;
        sum_sjf=0;
        for(int i=0;i<n;i++)
        {
          sum_sjf+=W[i];
        }
        float avg_sjf;
        avg_sjf=sum_sjf/n;
        cout<<"Process No"<< "\t"<<"Arrival time"<<"\t"<<" Burst Time"<< "\t" <<" Turned Around Time"<<"\t"<<"Waiting Time"<<endl;
        for(int j=0;j<n;j++)
        {
 	       cout<<j+1<<"\t\t\t"<<A[j]<<"\t\t"<<B[j]<<"\t\t"<<T[j]<<"\t\t"<<W[j]<<endl;
        }
        cout<<"Average : "<<avg_sjf;
        break;
        
    case 3:
    	for(int i=0;i<n;i++)
        {
           cout<<"Enter Burst Time For Process P"<<(i+1)<<":"<<endl;
           cin>>B[i];
           cout<<"Enter Priority For Process P"<<(i+1)<<":"<<endl;
           cin>>A[i];
        } 
        int l;
        l=0;
        for(int i=1;i<=n;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        	    if(i==A[j])	
        	    {
        	    	T[j]=l+B[j];
        	    	l=T[j];
        	    	W[j]=T[j]-B[j];
        	    	break;
				}
			}
		}
		float sum2;
        sum2=0;
        for(int i=0;i<n;i++)
        {
          sum2+=W[i];
        }
        float avg2;
        avg2=sum2/n;
        cout<<"Process No"<< "\t"<<"Burst Time"<<"\t"<<"Priority"<< "\t" <<" Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
        for(int j=0;j<n;j++)
        {
 	       cout<<j+1<<"\t\t\t"<<B[j]<<"\t\t"<<A[j]<<"\t\t"<<T[j]<<"\t\t"<<W[j]<<endl;
        }
        cout<<"Average : "<<avg2;
    	break;
    case 4:
	   for(int i=0;i<n;i++)
        {
           cout<<"Enter Burst Time For Process P"<<(i+1)<<":"<<endl;
           cin>>B[i];
           cout<<"Enter Arrival time For Process P"<<(i+1)<<":"<<endl;
           cin>>A[i];
        } 
        int TQ;
        int TB[20];
        int time = 0;
        cout<<"Enter Time Quantum : "<<endl;
        cin>>TQ;
        for(int i=0;i<n;i++)
        {
        	TB[i]=B[i];
        	W[i]=0;
		}
		while(1)
		{
			bool done = true;
			for(int i=0;i<n;i++)
	     	{
			if(TB[i]>0)
			{
				done = false; 
				if(TB[i]>TQ)
				{
					time = time + TQ;
					TB[i] = TB[i] - TQ;
				}
				else
				{
					time = time + TB[i];
					W[i] = time - B[i] - A[i];
					TB[i] = 0;
				//	T[i] = time;
				}
		      }
	     	}
	     	if(done = true)
	     	{
	     		break;
			}
		}
		float sum_rr;
        sum_rr=0;
        for(int i=0;i<n;i++)
        {
          sum_rr+=W[i];
        }
        float avg_rr;
        avg_rr=sum_rr/n;
        cout<<"Process No"<< "\t"<<"Arrival time"<<"\t"<<" Burst Time"<< "\t" <<" Turned Around Time"<<"\t"<<"Waiting Time"<<endl;
        for(int j=0;j<n;j++)
        {
 	       cout<<j+1<<"\t\t\t"<<A[j]<<"\t\t"<<B[j]<<"\t\t"<<T[j]<<"\t\t"<<W[j]<<endl;
        }
        cout<<"Average : "<<avg_rr;
	    break;    
        
        
        
        
        
    
    	
 
 }
 	
 
 
 
 return 0;

}
