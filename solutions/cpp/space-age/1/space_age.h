#pragma once

namespace space_age {

class space_age {
private:
    double m_seconds;

    // Constantes de conversión grabadas directamente en el binario
    static constexpr double EARTH_YEAR_IN_SECONDS = 31557600.0;

    // Factores orbitales relativos de los planetas
    static constexpr double MERCURY_ORBITAL_FACTOR = 0.2408467;
    static constexpr double VENUS_ORBITAL_FACTOR   = 0.61519726;
    static constexpr double MARS_ORBITAL_FACTOR    = 1.8808158;
    static constexpr double JUPITER_ORBITAL_FACTOR = 11.862615;
    static constexpr double SATURN_ORBITAL_FACTOR  = 29.447498;
    static constexpr double URANO_ORBITAL_FACTOR   = 84.016846;
    static constexpr double NEPTUNE_ORBITAL_FACTOR = 164.79132;

public:
    // Constructor: Inicializa los segundos
    explicit space_age(double seconds);

    // Método de acceso para obtener los segundos
    double seconds() const;

    // Métodos de conversión planetaria
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;
};

}  // namespace space_age