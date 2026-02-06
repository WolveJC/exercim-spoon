#!/bin/bash

# Extraemos el nombre de usuario de la captura: WolveJC
USERNAME="WolveJC"

if [ -z "$EXERCISM_TOKEN" ]; then
    echo "Error: Token ausente."
    exit 1
fi

echo "--- Sincronización: Track C++ ---"

# 1. Consultar soluciones del usuario específico
# Este endpoint suele ser más robusto que el general
RESPONSE=$(curl -s -H "Authorization: Bearer $EXERCISM_TOKEN" \
    "https://api.exercism.org/v1/solutions?user=$USERNAME&track_slug=cpp")

# 2. Diagnóstico inmediato
COUNT=$(echo "$RESPONSE" | jq '.results | length')
echo "Ejercicios detectados en la API para $USERNAME: $COUNT"

# 3. Filtrado y descarga
# Usamos select para asegurar que solo bajamos lo que ya pasó tests/completado
EXERCISES=$(echo "$RESPONSE" | jq -r '.results[] | select(.status=="published" or .status=="completed") | .exercise.slug')

for exercise in $EXERCISES; do
    if [ ! -d "cpp/$exercise" ]; then
        echo "Extrayendo: $exercise..."
        exercism download --track=cpp --exercise="$exercise"
    else
        echo "$exercise ya está en el repositorio."
    fi
done

# 4. Limpieza de sistema
find . -name "*.md" -type f -not -path "./README.md" -not -path "*/docs/*" -exec chmod 644 {} +

echo "--- Proceso completado para $USERNAME ---"
