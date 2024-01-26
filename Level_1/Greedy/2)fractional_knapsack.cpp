Solution 1-:
Steps-:
1)here we know that we need maximum value within given weight W.
2)So we have to sort not according-:
  1)Not according to minimum weight.
  2)Not according to maximum value.
3)Correct ways of sorting to get maximum value is -> (value/weight).

Code-: Time->O(Nlog(N))
static bool comp(Item a,Item b)
{
        double r1=(double)a.value/a.weight;
        double r2=(double)b.value/b.weight;
        return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
       sort(arr,arr+n,comp);
       double ans=0.0;
       
       for(int i=0;i<n;i++)
       {
           if(W>=arr[i].weight)
           {
               ans+=double(arr[i].value);
               W-=arr[i].weight;
           }
           else
           {
               double val1=double(arr[i].value)/double(arr[i].weight);
               ans+=val1* double(W);
               break;
           }
       }
       return ans;
}