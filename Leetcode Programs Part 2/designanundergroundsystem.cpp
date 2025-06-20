struct CheckIn {
    string station;
    int t;
};
struct Route {
    string start;
    string end;
    bool operator==(const Route& other) const {
        return start == other.start && end == other.end;
    }
};
struct RouteStats {
    int tripCount;
    double avgTime;
};
class HashRoute {
public:
    size_t operator()(const Route& r) const {
        size_t h1 = hash<string>()(r.start);
        size_t h2 = hash<string>()(r.end) * 13;
        return h1 ^ h2;
    }
};
class UndergroundSystem {
public:
    UndergroundSystem() {        
    }    
    void checkIn(int id, string stationName, int t) {
        activeTrips.insert(make_pair(id, CheckIn{stationName, t}));
    }    
    void checkOut(int id, string stationName, int t) {
        auto it = activeTrips.find(id);
        auto duration = t - it->second.t;
        Route route{it->second.station, stationName};
        activeTrips.erase(it);
        auto routeIt = routeStats.find(route);
        if (routeIt == routeStats.end()) {
            routeStats[route] = RouteStats{1, static_cast<double>(duration)};
        } else {
            routeIt->second.avgTime = routeIt->second.avgTime * routeIt->second.tripCount + duration;
            routeIt->second.tripCount++;
            routeIt->second.avgTime = routeIt->second.avgTime / routeIt->second.tripCount;
        }
    }    
    double getAverageTime(string startStation, string endStation) {
        auto routeIt = routeStats.find(Route{startStation, endStation});
        return routeIt->second.avgTime;
    }
private:
    unordered_map<int, CheckIn> activeTrips;
    unordered_map<Route, RouteStats, HashRoute> routeStats;
};
