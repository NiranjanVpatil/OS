//============================================================================
// Name        : Niranjan Vinod Patil.
// Description : Page Replacemnt FIFO
// Roll No : CETTYB305
//============================================================================
#include <iostream>
using namespace std;
int main()
{
	int frames[10],pages[25],temp[25];
	int total_pages, m, n, position, k, l, total_frames;
    int a = 0, b = 0, page_fault = 0,page_hit = 0;
    
    cout<<"Enter Total Number of Frames : ";
    cin>>total_frames;
    cout<<"Enter Total Number of Pages : ";
    cin>>total_pages;
    
    cout<<"Enter Values for Reference String"<<endl;
    for(m = 0; m < total_pages; m++)
      {
            cout<<"Reference String Bit "<<(m+1)<<" : ";
            cin>>pages[m];
      }
      
    for(m = 0; m < total_frames; m++)
    {
            frames[m] = -1;
    }
    
    for(int n = 0; n < total_pages; n++)
    {
            a = 0, b = 0;
            for(m = 0; m < total_frames; m++)
            {
                  if(frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        page_hit++;
                        break;
                  }
            }
            if(a == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                             page_hit--;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for(m = 0; m < total_frames; m++)
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                                    
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            
      }
   	cout<<"Total Number of Page Faults : "<<page_fault<<endl;
    cout<<"Total Number of Page Hits : "<<page_hit;
	return 0;
	
}

/*

Enter Total Number of Frames : 3
Enter Total Number of Pages : 20
Enter Values for Reference String
Reference String Bit 1 : 7
Reference String Bit 2 : 0
Reference String Bit 3 : 1
Reference String Bit 4 : 2
Reference String Bit 5 : 0
Reference String Bit 6 : 3
Reference String Bit 7 : 0
Reference String Bit 8 : 4
Reference String Bit 9 : 2
Reference String Bit 10 : 3
Reference String Bit 11 : 0
Reference String Bit 12 : 3
Reference String Bit 13 : 2
Reference String Bit 14 : 1
Reference String Bit 15 : 2
Reference String Bit 16 : 0
Reference String Bit 17 : 1
Reference String Bit 18 : 7
Reference String Bit 19 : 0
Reference String Bit 20 : 1
Total Number of Page Faults : 9
Total Number of Page Hits : 5
--------------------------------
Process exited after 39.71 seconds with return value 0
Press any key to continue . . .

*/


/*
 int i=0;
   while(i<total_frames)
   {
     frames[i]=pages[i];
	 i=i+1;
    }
    
    int a,b;
    a=0;
    b=0;
    int p;
    
    p=0;
    for(int n = i; n <= total_pages; n++)
    {
       for(int m = 0; m < total_frames; m++)
        {
        	if(pages[n] == frames[m])
        	{
        		a=1;
        		cout<<"pages[n]"<<pages[n]<<endl;
        		page_hit=page_hit+1;
        		break;
			}
		
		}   
		if  (a == 0) 
		{
	        frames[p]=pages[n];
	        cout<<"Frames"<<frames[p]<<endl;
	        page_fault= page_fault+1;
			p=p+1;
			if(p = total_frames)
			{
			   p=0;	
			}	
		} 
		
		     
    }
    


*/
