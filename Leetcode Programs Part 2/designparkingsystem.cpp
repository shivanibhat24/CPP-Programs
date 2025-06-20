class ParkingSystem {
public:
    vector<int> freq;
    ParkingSystem(int big, int medium, int small) {
        freq = {0,big,medium,small};
    }    
    bool addCar(int carType) {
        if (freq[carType] > 0)
        {
            freq[carType]--;
            return true;
        }
        else return false;
    }
};
