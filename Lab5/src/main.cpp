#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class LaneDepartureWarningSystem {
private:
    vector<double> readings= {-0.7,0.1,1,0.7}; // negative or positive (direction)
    double threshold;
    function<bool(double)> detection_rule;

public:
    LaneDepartureWarningSystem(double threshold): threshold(threshold){
        detection_rule = [this](double d){
            if(abs(d) > this->threshold) return true;
            return false;
        };
        runDetection();
    }
    void updateReadings(vector<double> d){
        readings = d;
    }
    void runDetection(){
        cout<< "Rejects : " << count_if(readings.begin(), readings.end(), detection_rule) << endl;
    }
};

int main() {
    LaneDepartureWarningSystem LMS(0.5);
    LMS.updateReadings({
        1, //R
        0.8, //R
        0.6, //R
        0.4,
        0.2,
        0,  
        -0.2,
        -0.4,
        -0.6, //R
        -0.8, //R
        -1, //R
    });
    LMS.runDetection();

    return 0;
}