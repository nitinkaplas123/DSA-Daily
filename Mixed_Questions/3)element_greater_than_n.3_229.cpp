Solution -1
Steps-:
1)Using hashmap count the freq and then if key freq is greater than N/3 store key into ans array
2)Same as we done for N/2 element

Js Code-:  Time ->O(n)  Space ->O(n)

var majorityElement = function(nums) {
    let n=nums.length;
    let m=new Map()
    
    nums.forEach((num)=>{
        if(m.has(num))
        m.set(num,m.get(num)+1)
        else
        m.set(num,1)
    })

    let ans=new Array()
    m.forEach((value,key)=>{
        if(value>n/3)
        ans.push(key)
    })
    return ans
};



C++ Code-:
vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }

        for(auto x:m)
        {
            if(x.second>n/3)
            v.push_back(x.first);
        }
        return v;
    }


Solution -2-: called Bayer Moore Voting Algo
Steps-:
1)As we know we have to count the elements which count is greater than N/3
 eg. [1,1,1,3,3,2,2,2]
 just think if we have n=8 here 
 8/3 =2 means more than 2 means atleast 3 
 means if we split 8 as N/3 =>(3+3+2)
 which means max we have two elements which is greater than N/3 

2)So here same approach as in N/2 just we take two variables 
num1=-1 num2=-1;
c1=0 ,c2=0;

Case-1
If elemnt is equal to num1  then c1++;

Case-2 
If element is equal to num2 then c2++;

Case-3 
If c1==0
Then we assume this may be the majority element 
num1=nums[i] and c1=1

Case-4
If c2==0
Then we assumw this may be the majority element 
num2=nums[i] and c2=1

Case-5 
means both nominations for majority are booked with another element now we currently have diff element
so if decreases both the majority element count 
c1--; 
c2--;


3)Now we have two elements which may be majority element
  so we check using traversal loop 
  if num1 count>n/3  store into vector v
  if num2 count>n/3  store into vector v

4)Return v


Code-: Time->O(N)   Space->O(1)

  vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        int num1=INT_MIN;
        int num2=INT_MIN;
        int c1=0;
        int c2=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
            c1++;
            else if(nums[i]==num2)
            c2++;
            else if(c1==0)
            {
                num1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
            count1++;
            if(nums[i]==num2)
            count2++;
        }
        if(count1>n/3)
        v.push_back(num1);
        if(count2>n/3)
        v.push_back(num2);
        return v;
    }
