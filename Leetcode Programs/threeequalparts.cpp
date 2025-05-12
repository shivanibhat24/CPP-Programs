class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
     
        int countone=count(arr.begin(),arr.end(),1);
        int n=arr.size();
        if(countone%3)
        {
            return {-1,-1};
        }
        if(countone==0)
        {
            return {0,n-1};
        }
        int total=countone/3;
        int p1=0,p2=0,p3=0;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                if(count==0)
                {
                    p1=i;
                }
                else if(count==total)
                {
                    p2=i;
                }
                else if(count==2*total)
                {
                    p3=i;
                }
                count+=1;
            }
        }
        while(p3<n-1)
        {
            p1+=1;
            p2+=1;
            p3+=1;
            if(arr[p1]!=arr[p2] || arr[p2]!=arr[p3] || arr[p1]!=arr[p3])
            {
                return {-1,-1};
            }
        }
        return {p1,p2+1};
    } 
};
