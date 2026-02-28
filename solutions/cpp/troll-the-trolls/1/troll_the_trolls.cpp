namespace hellmath {

// Tarea 1: Identificador de estado de cuenta `troll`, `guest`, `user`, y `mod`.
    enum class AccountStatus {troll, guest, user, mod};

// Tarea 1: Identificador de acciones `read`, `write`, y `remove`.
    enum class Action {read, write, remove};

// Tarea 2: Control de visibilidad (Shadow-banning)
    bool display_post(AccountStatus poster, AccountStatus viewer){
        if (poster == AccountStatus::troll) return viewer == AccountStatus::troll;
        // El contenido de trolls solo es visible para otros trolls
        return true;
    }

// Tarea 3: Matriz de permisos por tipo de usuario
    bool permission_check(Action action, AccountStatus status){
        switch(action){
            case Action::read:   return true;
            case Action::write:  return status != AccountStatus::guest;
            case Action::remove: return status == AccountStatus::mod;
            default:             return false;
        }
    }

// Tarea 4: Emparejamiento de jugadores
    bool valid_player_combination(AccountStatus p1, AccountStatus p2){
        if (p1 == AccountStatus::guest || p2 == AccountStatus::guest)
            return false; //Los invitados no juegan
        if (p1 == AccountStatus::troll || p2 == AccountStatus::troll)
            //Los trolls SOLO están con trolls
            return p1 == AccountStatus::troll && p2 == AccountStatus::troll; 
        return true;
    }

// Tarea 5: Jerarquía de prioridad del sistema
    bool has_priority(AccountStatus s1, AccountStatus s2){
        auto priority = [](AccountStatus s){
            switch(s){
                case AccountStatus::mod:   return 4;
                case AccountStatus::user:  return 3;
                case AccountStatus::guest: return 2;
                case AccountStatus::troll: return 1;
                default:              return 0;
            }
        };
        return priority(s1) > priority(s2);
    }
}  // namespace hellmath
