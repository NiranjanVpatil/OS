
//============================================================================
// Name        : Niranjan Vinod Patil.
// Description : Page Replacemnt Algorithm
// Roll No : CETTYB305
//============================================================================
#include <iostream>
using namespace std;


int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}

int main()
{
	int frames[10],pages[25],temp[25];
	int total_pages, m, n, position, k, l, total_frames;
    int page_fault = 0,page_hit = 0;
    int a = 0, b = 0,counter = 0, time[10], flag1, flag2,flag3, i, j, pos,max;
    int ch;
    
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

    cout<<"Page Replacement algorithms: "<<endl;
	cout<<"1. FIFO. "<<endl;
	cout<<"2. LRU. "<<endl;
	cout<<"3. Optimal"<<endl;
	cout<<"Enter Your Choice : "<<endl;
	cin>>ch;
	switch(ch)
 {
 	case 1:
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
		 break;
	case 2:
		for(i = 0; i < total_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < total_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < total_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                page_hit++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < total_frames; ++j){
                if(frames[j] == -1){
                    counter++;
                    page_fault++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            pos = findLRU(time, total_frames);
            counter++;
            page_fault++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
    }
    
    cout<<"Total Number of Page Faults : "<<page_fault<<endl;
    cout<<"Total Number of Page Hits : "<<page_hit;

		break;
	case 3:
			for(i = 0; i < total_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < total_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < total_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   page_hit++;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < total_frames; ++j){
                if(frames[j] == -1){
                    page_fault++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            flag3 =0;
            
            for(j = 0; j < total_frames; ++j){
                temp[j] = -1;
                
                for(k = i + 1; k < total_pages; ++k){
                    if(frames[j] == pages[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            
            for(j = 0; j < total_frames; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            
            if(flag3 ==0){
                max = temp[0];
                pos = 0;
                
                for(j = 1; j < total_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }                
            }
            
            frames[pos] = pages[i];
            page_fault++;
        }
	}
    
    cout<<"Total Number of Page Faults : "<<page_fault<<endl;
    cout<<"Total Number of Page Hits : "<<page_hit;
		break;

 }
	   
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
Total Number of Page Faults : 12
Total Number of Page Hits : 8
--------------------------------
Process exited after 25.39 seconds with return value 0
Press any key to continue . . .






*/

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
Total Number of Page Hits : 11
--------------------------------
Process exited after 34.24 seconds with return value 0
Press any key to continue . . .
*/
