Solution 1-:
Steps-:
1)Using lomuto partition

Code-:
void binSort(int A[], int N)
{
       int i=-1;
       for(int j=0;j<N;j++)
       {
           if(A[j]==0)
           {
               i++;
               swap(A[i],A[j]);
           }
       }
}