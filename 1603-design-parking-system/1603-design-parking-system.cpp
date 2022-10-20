class ParkingSystem {
private:
    int big_,medium_,small_;
public:
    ParkingSystem(int big, int medium, int small) {
        big_ = big;
        medium_ = medium;
        small_ = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && big_!=0) {
            big_--;
            return true;
        }
        else if(carType==2 && medium_!=0) {
            medium_--;
            return true;
        }
        else if(carType==3 && small_!=0) {
            small_--;
            return true;
        }
        return false;
            
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */