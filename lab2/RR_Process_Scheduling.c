#include<stdio.h>
#include<stdbool.h>
int main()
{
    int n,p[20],bt[20],wt[20],tat[20],i,j,quantum,rem_bt[20];
    float avwt=0,avtat=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;   //contains process number
        //setting bt as remaining bt initially
        rem_bt[i]=bt[i];
    }
    
    printf("\nEnter Time Quantum:");
    scanf("%d",&quantum);
    
    //calculating waiting time
        int t = 0; // setting current time
    	 //keep traversing in round robin manner
    	 //until all process are done
        while(1){
        	bool done=true;
        	//Traverse all processes one by one repeatedly
	    	for(i=0;i<n;i++)
	    	{
	    		//check if process burst time is remaining
	    		//then only need to process further
	    		if(rem_bt[i]>0){
	    			done=false;  //process is pending
		    		if(rem_bt[i]>quantum){
		    			t += quantum;   //increase the time
						rem_bt[i] -= quantum; //decrease remaining bt
					}else{
						t=t+rem_bt[i];
						wt[i]=t-bt[i];
						//as process is fully executed
						//set remaining bt as 0
						rem_bt[i]=0;	
					}
				}
			} 
			//if all process are done
			if(done==true)
				break;   		
		}
   
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
       tat[i]=bt[i]+wt[i];
       avwt+=wt[i];
       avtat+=tat[i];
       printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }   
    
    printf("\nAverage Waiting Time=%.2f",avwt/n);
    printf("\nAverage Turnaround Time=%.2f",avtat/n);
    
    return 0;
}

