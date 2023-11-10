Question -:
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Solution 1-:
Steps-:
1)Using hashmap

Code-:
 vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        for(auto x:m)
        {
            if(x.second>1)
            v.push_back(x.first);
        }
        
        for(int i=0;i<n;i++)
        {
            int val=abs(arr[i])-1;
            if(val<n and arr[val]>0)
            arr[val]=-arr[val];
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                v.push_back(i+1);
                break;
            }
        }
        return v;
    }


Solution 2-:
Steps-:
1. eg. N=3
   arr=[1,3,3]

   1st equation -:
   1. sum of all elements in array.
   sum1=1+3+3=7
   2. sum of first N natural number
    s1n=1+2+3=6

    sum1-s1n=1

    2nd equation 
    1. sum of square of elements in array.
    sum2=(1*1) +(3*3) + (3*3) =>19
    2. sum of sqaure of first N elements.
    s2n=(1*1) + (2*2) + (3*3) =>14

    sum2-s2n=19-14 =>5
    
    val1 => Suppose 1sts equation => x-y
    val2=>  Suppose 2nd equation => (x*x)-(y*y)
                                 => (x+y) (x-y)

    val2=val2/val1         =>   (x+y)(x-y)/(x-y)
                          => (x+y)

    val2=5/1
    val2=>5      =>(x+y)


3. Now 
   we have 

   val1=>x-y
   val2=>x+y

   Adding val1+val2=>  x-y+x+y=> 5+1
                        2x=6
                        x=3

   Now y=val2-x;
      y=2


Now we have x as repeating number and y as missing number.

return {x,y};



Code-: Time->O(N+M) Space->O(1)

vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>v;
        long long int sum1=0;
        long long int sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=(long long)arr[i];
            sum2+=(long long)arr[i] * (long long)arr[i];
        }
        
        long long int s1n=0;
        long long int s2n=0;
        for(int i=1;i<=n;i++)
        {
            s1n+=i;
            s2n+=(long long)i * (long long)i;
        }
        
        long long int val1=sum1-s1n;
        long long int val2=sum2-s2n;
        
        val2=val2/val1;
        
        int x=(val1+val2)/2;
        int y=val2-x;
        return {x,y};
    }

        






           

    



Code-:
vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>v;
        long long int sum1=0;
        long long int sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=(long long)arr[i];
            sum2+=(long long)arr[i] * (long long)arr[i];
        }
        
        long long int s1n=0;
        long long int s2n=0;
        for(int i=1;i<=n;i++)
        {
            s1n+=i;
            s2n+=(long long)i * (long long)i;
        }
        
        long long int val1=sum1-s1n;
        long long int val2=sum2-s2n;
        
        val2=val2/val1;
        
        int x=(val1+val2)/2;
        int y=val2-x;
        return {x,y};
    }