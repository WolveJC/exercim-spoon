// Headers de la biblioteca estandar
#include <cmath>
using namespace std;

// 1. Tarifa diaria
double daily_rate(double hourly_rate) {
    double daily = hourly_rate * 8.0;
    return daily;
}

// 2. Aplicar descuento
double apply_discount(double price, double discount) {
    double price_descount = price - (price * (discount/100.0));
    return price_descount;
}

// 3. Tarifa mensual redondeada (a tope de techo)
int monthly_rate(double hourly_rate, double discount) {
    double daily = daily_rate(hourly_rate); // Tarifa diaria
    daily *= 22; // Diaria por mesualidad (22)
    double monthly = apply_discount(daily, discount); // Tarifa mensual con descuento
    return ceil(monthly);
}

// 4. Días en presupuesto redondeados (a tope de suelo)
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily = daily_rate(hourly_rate); // Tarifa diaria
    double daily_discount = apply_discount(daily, discount); // Descuento diario
    return floor(budget/daily_discount);
}
