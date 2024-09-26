class Solution {
private:
    unordered_map<string, vector<string>> flightGraph;
    vector<string> travelItinerary;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            string fromAirport = tickets[i][0];
            string toAirport = tickets[i][1];
            flightGraph[fromAirport].push_back(toAirport);
        }
        for (auto &entry : flightGraph) {
            sort(entry.second.rbegin(), entry.second.rend());
        }
        stack<string> dfsStack;
        dfsStack.push("JFK");
        while (!dfsStack.empty()) {
            string currentAirport = dfsStack.top();
            vector<string> &destinations = flightGraph[currentAirport];
            if (!destinations.empty()) {
                string nextDestination = destinations.back();
                destinations.pop_back();
                dfsStack.push(nextDestination);
            } 
            else {
                travelItinerary.push_back(currentAirport);
                dfsStack.pop();
            }
        }
        reverse(travelItinerary.begin(), travelItinerary.end());
        return travelItinerary;    
    }
};
