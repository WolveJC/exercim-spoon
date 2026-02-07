#include "vehicle_purchase.h"

using namespace std;

namespace vehicle_purchase {

// Determina si el tipo de vehículo requiere licencia (solo "car" y "truck").
bool needs_license(string kind) {
    return kind == "car" || kind == "truck";
}

// Selecciona el vehículo que va primero en orden lexicográfico.
string choose_vehicle(string option1, string option2) {
    string chosen = (option1 < option2) ? option1 : option2;
    return chosen + " is clearly the better choice.";
}

// Calcula el precio de reventa basado en la antigüedad del vehículo.
double calculate_resell_price(double original_price, double age) {
    double factor;
    if (age < 3) factor = 0.8;
    else if (age < 10) factor = 0.7;
    else factor = 0.5;
    
    return original_price * factor;
}

}  // namespace vehicle_purchase
