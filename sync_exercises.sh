#!/bin/bash

if [ -z "$EXERCISM_TOKEN" ]; then
    echo "Error: Deficiencia de señal (TOKEN no encontrado)."
    exit 1
fi

echo "--- Iniciando sincronización cerebral de ejercicios ---"

# 1. Obtención de datos con cabeceras de aceptación JSON
echo "Consultando soluciones en la API..."
RESPONSE=$(curl -s -X GET \
    -H "Authorization: Bearer $EXERCISM_TOKEN" \
    -H "Accept: application/json" \
    "https://api.exercism.org/v1/solutions")

# Debug: Verificar si la respuesta es válida antes de procesar
if [ -z "$RESPONSE" ] || [ "$RESPONSE" == "null" ]; then
    echo "Error: La API devolvió una respuesta vacía. Revisa el TOKEN."
    exit 1
fi

# 2. Extracción segura
# Usamos -e para que jq devuelva un error si la estructura no es la esperada
EXERCISES_TO_DOWNLOAD=$(echo "$RESPONSE" | jq -r '.results // [] | .[] | select(.status=="published" or .status=="completed") | "\(.track.slug):\(.exercise.slug)"' 2>/dev/null)

if [ -z "$EXERCISES_TO_DOWNLOAD" ]; then
    echo "No se detectaron ejercicios resueltos"
    exit 0
fi

# 3. Iteración
for entry in $EXERCISES_TO_DOWNLOAD; do
    track=$(echo "$entry" | cut -d':' -f1)
    exercise=$(echo "$entry" | cut -d':' -f2)

    if [ ! -d "$track/$exercise" ]; then
        echo "Sincronizando: [$track] $exercise..."
        exercism download --track="$track" --exercise="$exercise"
    else
        echo "Omitiendo: $exercise (ya en el sistema)."
    fi
done

echo "--- Sincronización finalizada ---"
