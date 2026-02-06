#!/bin/bash

# Verificación de seguridad para el token
if [ -z "$EXERCISM_TOKEN" ]; then
    echo "Error: La señal química (EXERCISM_TOKEN) es inexistente."
    exit 1
fi

echo "--- Iniciando sincronización cerebral de ejercicios ---"

# 1. Obtención de datos mediante la API (Filtrado de soluciones resueltas)
echo "Consultando soluciones completadas en la API de Exercism..."
SOLUTIONS_JSON=$(curl -s -H "Authorization: Bearer $EXERCISM_TOKEN" "https://api.exercism.org/v1/solutions")

# 2. Extracción de pares track:ejercicio usando jq
# Solo seleccionamos los que tienen estado 'published' o 'completed'
mapfile -t EXERCISES_TO_DOWNLOAD < <(echo "$SOLUTIONS_JSON" | jq -r '.results[] | select(.status=="published" or .status=="completed") | "\(.track.slug):\(.exercise.slug)"')

if [ ${#EXERCISES_TO_DOWNLOAD[@]} -eq 0 ]; then
    echo "No se han detectado nuevos macronutrientes (ejercicios resueltos) para procesar."
    exit 0
fi

echo "Se han detectado ${#EXERCISES_TO_DOWNLOAD[@]} ejercicios aptos para descarga."

# 3. Iteración y descarga
for entry in "${EXERCISES_TO_DOWNLOAD[@]}"; do
    # Separamos el track del ejercicio (formato track:ejercicio)
    track=$(echo "$entry" | cut -d':' -f1)
    exercise=$(echo "$entry" | cut -d':' -f2)

    # Verificamos si ya existe para evitar redundancia
    if [ ! -d "$track/$exercise" ]; then
        echo "Sincronizando: [$track] $exercise..."
        exercism download --track="$track" --exercise="$exercise"
    else
        echo "Saltando: $exercise (ya integrado en el sistema)."
    fi
done

# 4. Limpieza de residuos y normalización de permisos
# Mantenemos lógica de limpieza para asegurar un entorno pulcro
find . -name "*.md" -type f -not -path "./README.md" -not -path "*/docs/*" -exec chmod 644 {} +

echo "--- Sincronización finalizada. Sistema optimizado. ---"
