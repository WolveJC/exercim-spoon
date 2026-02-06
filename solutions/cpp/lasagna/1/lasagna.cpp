// 1. El tiempo total estándar es una constante de 40 minutos.
int ovenTime() {
    return 40;
}

// 2. Tiempo que le falta al sistema para completar el ciclo.
int remainingOvenTime(int actualMinutesInOven) {
    return ovenTime() - actualMinutesInOven;
}

// 3. Cada capa requiere una inversión de 2 minutos de trabajo manual.
int preparationTime(int numberOfLayers) {
    return numberOfLayers * 2;
}

// 4. Suma del tiempo de preparación + tiempo real en el horno.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    // La señalización química del proceso nos dice que el tiempo total 
    // es lo que tardaste en armarla más lo que lleva cocinándose.
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}