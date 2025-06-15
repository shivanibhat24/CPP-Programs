struct Location {
    std::string name;
    int score;
};
struct LocationComparator {
    bool operator()(const Location& a, const Location& b) const {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.name < b.name;  
    }
};
class SORTracker {
public:
    std::set<Location, LocationComparator> locations_set_;
    std::set<Location, LocationComparator>::iterator kth_element_iter_; 
    bool first_get_call_ = true; 
    SORTracker() {    
    }    
    void add(std::string name, int score) {
        Location loc = {name, score};       
        bool should_decrement_iter = false;
        if (!first_get_call_) {              
            if (LocationComparator()(loc, *kth_element_iter_)) {
                 should_decrement_iter = true;
            }
        }        
        locations_set_.insert(loc);
        if (should_decrement_iter) {
    
            if (kth_element_iter_ != locations_set_.begin()) { 
                 --kth_element_iter_;
            } else {
                 
            }
        }           
    }    
    std::string get() {
        if (first_get_call_) {
            kth_element_iter_ = locations_set_.begin();
            first_get_call_ = false;
        } else {
            ++kth_element_iter_;
        }
        return kth_element_iter_->name;
    }
};
