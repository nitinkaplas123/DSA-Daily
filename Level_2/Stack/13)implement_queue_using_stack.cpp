class Queue {
    stack<int>s1;
    stack<int>s2;
public:

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if(s1.empty()==true) return -1;
        
        while(s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        s1.pop();
        
        while(s2.empty()==false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }