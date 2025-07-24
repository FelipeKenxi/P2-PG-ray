#!/bin/bash

echo "Compilando..."
g++ main.cc -o raytracer

if [ $? -ne 0 ]; then
    echo "Erro na compilação!"
    exit 1
fi

echo "Executando e gerando image.ppm..."
./raytracer > image.ppm

echo "Imagem gerada com sucesso!"
