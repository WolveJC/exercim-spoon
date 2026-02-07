#include <cmath>
#include "darts.h"
using namespace std;

namespace darts {
    double get_distance(double x, double y){
        return hypot(x,y);
    }
    int score (double x, double y){
        double distance = get_distance(x,y);
        if (distance <= 1){return 10;}
        if (distance <= 5 ){return 5;}
        if (distance <= 10 ){return 1;}
        return 0;
    }
    
}  // namespace darts
