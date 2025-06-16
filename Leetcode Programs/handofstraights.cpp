class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    { int n=hand.size();
      if (n%groupSize!=0) return false;
      sort(hand.begin(),hand.end());
      for(int i=0;i<n;i++)
      {
        if(hand[i]>=0)
        {
            if(!func(hand,groupSize,i,n)) return false;
        }
      }
        return true;
    }
    bool func(vector<int>& hand,int groupSize,int i,int n)
    {
        int next=hand[i]+1;
        hand[i]=-1;
        int count=1;
        i++;
        while(i<n && count<groupSize)
        {
            if(hand[i]==next)
            {
                next=hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count==groupSize;
    }
};
