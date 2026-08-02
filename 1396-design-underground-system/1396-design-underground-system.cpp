class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> check;
    unordered_map<string, unordered_map<string, pair<int, int>> > stTime;

    UndergroundSystem() {
        // {id, {station, ts}}
        // station start, end total time, count
    }
    
    void checkIn(int id, string stationName, int t) {
        // check[id].first = stationName;
        // check[id].second = t;
        check[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(check.find(id) == check.end()) return;
        string startStation = check[id].first;
        int ts = check[id].second;

        int totalTime = stTime[startStation][stationName].first;
        int totalCnt = stTime[startStation][stationName].second;
        stTime[startStation][stationName] = {totalTime + t - ts, totalCnt + 1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double) stTime[startStation][endStation].first / (double)stTime[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */