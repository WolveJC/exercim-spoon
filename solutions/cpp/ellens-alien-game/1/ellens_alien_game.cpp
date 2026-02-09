namespace targets {
    class Alien {
    public:
        // Miembros públicos (Coordenadas)
        int x_coordinate;
        int y_coordinate;

        // Constructor
        Alien(int x, int y): x_coordinate(x), y_coordinate(y), health(3){}

        // Métodos de acceso y estado
        int get_health() const{
            return health;
        }
        bool is_alive() const{
            return health > 0; 
        }
    
        // Métodos de acción
        bool hit(){
            if (health > 0) {
                health--;
            }return true;
            
        }
        bool teleport(int x_new, int y_new){
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }
        bool collision_detection(const Alien& other) const{
            return (x_coordinate == other.x_coordinate) && (y_coordinate == other.y_coordinate);
        }

    private:
        int health;
    };

}