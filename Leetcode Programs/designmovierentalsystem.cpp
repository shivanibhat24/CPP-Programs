class MovieRentingSystem {
public:
    unordered_map<int, vector<pair<int, int>>> movieData; 
    unordered_map<int, set<int>> currRented;
    set<tuple<int, int, int>> rentedSet; 
    unordered_map<int, unordered_map<int, int>> priceLookup;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            movieData[movie].push_back({price, shop});
            priceLookup[movie][shop] = price;
        }
        for (auto &entry : movieData) {
            sort(entry.second.begin(), entry.second.end()); 
        }
    }
    vector<int> search(int movie) {
        vector<int> result;
        auto &entries = movieData[movie];
        for (auto &[price, shop] : entries) {
            if (currRented[movie].find(shop) == currRented[movie].end()) {
                result.push_back(shop);
                if (result.size() == 5) break;
            }
        }
        return result;
    }
    void rent(int shop, int movie) {
        currRented[movie].insert(shop);
        int price = priceLookup[movie][shop];
        rentedSet.insert({price, shop, movie});
    }
    void drop(int shop, int movie) {
        currRented[movie].erase(shop);
        int price = priceLookup[movie][shop];
        rentedSet.erase({price, shop, movie});
    }
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto &[price, shop, movie] : rentedSet) {
            result.push_back({shop, movie});
            if (++count == 5) break;
        }
        return result;
    }
};
