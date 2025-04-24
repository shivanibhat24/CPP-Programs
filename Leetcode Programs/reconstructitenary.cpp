class Solution {
public:    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for(int i=0;i<tickets.size();i++){
            string from = tickets[i][0];
            string  to = tickets[i][1];
            graph[from].push_back(to);
        }
        for(auto& [airport, destinations]: graph){
            sort(destinations.rbegin(), destinations.rend());
        }
        stack<string> st;
        st.push("JFK");
        vector<string> itenary;
        while(!st.empty()){
            string currAirport = st.top();
            auto& destinations = graph[currAirport];
            if(!destinations.empty()){
                string nextDest = destinations.back();
                destinations.pop_back();
                st.push(nextDest);
            }
            else{
                itenary.push_back(currAirport);
                st.pop();
            }
        }
       reverse(itenary.begin(), itenary.end());
       return itenary;        
    }
};
