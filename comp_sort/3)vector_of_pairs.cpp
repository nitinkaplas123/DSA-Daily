If we are given pair of vector-:

vector<pair<int,int>>v;

Now if we want to fetch the values of pair then using -:

for(int i=0;i<v.size();i++)
{
    int val1=v[i].first;
    int val2=v[i].second;
    cout<<val1<<" "<<val2<<endl;
}