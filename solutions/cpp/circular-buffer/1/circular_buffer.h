#pragma once
#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename T>
class circular_buffer {
private:
    std::vector<T> m_buffer;
    size_t m_capacity;
    size_t m_head;
    size_t m_tail;
    size_t m_size;

public:
    // Constructor con tamaño fijo predefinido
    explicit circular_buffer(size_t capacity) 
        : m_buffer(capacity), m_capacity(capacity), m_head(0), m_tail(0), m_size(0) {}

    // Lee y extrae el elemento más antiguo (Aduana de lectura)
    T read() {
        if (m_size == 0) {
            throw std::domain_error("Intento de leer un búfer vacío.");
        }
        
        T item = m_buffer[m_head];
        m_head = (m_head + 1) % m_capacity; // Avanza cíclicamente
        m_size--;
        return item;
    }

    // Escribe un elemento nuevo si hay espacio libre
    void write(const T& item) {
        if (m_size == m_capacity) {
            throw std::domain_error("Intento de escribir en un búfer lleno.");
        }
        
        m_buffer[m_tail] = item;
        m_tail = (m_tail + 1) % m_capacity; // Avanza cíclicamente
        m_size++;
    }

    // Sobrescribe el elemento más antiguo si el búfer está lleno
    void overwrite(const T& item) {
        if (m_size < m_capacity) {
            // Si no está lleno, se comporta exactamente como una escritura normal
            write(item);
        } else {
            // Si está lleno, el nuevo dato ocupa la posición de m_tail (que coincide con m_head)
            m_buffer[m_tail] = item;
            m_tail = (m_tail + 1) % m_capacity;
            
            // Como destruimos el dato más viejo sin leerlo, obligamos a m_head a avanzar
            m_head = (m_head + 1) % m_capacity;
            // El tamaño (m_size) se mantiene igual a m_capacity
        }
    }

    // Limpia o vacía la estructura restableciendo el estado
    void clear() {
        m_head = 0;
        m_tail = 0;
        m_size = 0;
    }
};

}
