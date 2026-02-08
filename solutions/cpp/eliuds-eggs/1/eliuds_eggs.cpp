#include "eliuds_eggs.h"

namespace chicken_coop {
    int positions_to_quantity(int display_number){
        int count = 0;
        while (display_number > 0){
            count += (display_number & 1); // Extraer el bit y contamos: 1 si hay huevo, 0 si no hay
            display_number >>= 1;          // Desplazar para analizar el siguiente lugar
        } return count;
    }
}  // namespace chicken_coop
