#include <stdio.h>
#include <math.h>
 
int size = 5;
 
void FCFS(int arr[],int head)
{
    int seek_count = 0;
      int cur_track, distance;
   
    for(int i=0;i<size;i++)
       {
        cur_track = arr[i];
       
          // calculate absolute distance
        distance = fabs(head - cur_track);
       
          // increase the total count
        seek_count += distance;
       
          // accessed track is now new head
        head = cur_track;
    }
   
    printf("Total number of seek operations: %d\n",seek_count);
       
      // Seek sequence would be the same
    // as request array sequence
    printf("Seek Sequence is\n");
   
      for (int i = 0; i < size; i++) {
        printf("%d\n",arr[i]);
    }
}
 
//Driver code
int main()
{
      // request array
    int arr[5] = { 55,58,60,70,18};
      int head = 0;
     
    FCFS(arr,head);
   
    return 0;
}
 

