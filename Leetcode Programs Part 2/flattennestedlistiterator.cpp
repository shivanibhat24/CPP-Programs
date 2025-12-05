class NestedIterator {
public:
    int n;
    int j;
    vector<int>vec;
    stack<NestedInteger>st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--){
            st.push(nestedList[i]);
        }
        while(!st.empty()){
            NestedInteger curr=st.top();
            st.pop();
            if(curr.isInteger()){
                vec.push_back(curr.getInteger());
            }else{
                auto &list=curr.getList();
                for(int k=list.size()-1;k>=0;k--){
                    st.push(list[k]);
                }
            }
        }
        j=0;
        n=vec.size();
    }    
    int next() {
        j++;
        return vec[j-1];
    }    
    bool hasNext() {
        if(j<n) return true;
        return false;
    }
};
