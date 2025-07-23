# Raytracing

## Descrição do Projeto

Este projeto segue o tutorial "Ray Tracing in One Weekend" (https://raytracing.github.io/books/RayTracingInOneWeekend.html), que propõe a construção de um renderizador de imagens baseado na técnica de **Ray Tracing**, em C++.

Durante a execução do projeto, o objetivo foi:
1. Compreender os fundamentos de Ray Tracing;
2. Implementar os principais componentes do renderizador;
3. Criar uma cena personalizada com esferas de diferentes materiais;
4. Alterar a posição e direção da câmera para gerar imagens interessantes;
5. Gerar imagens finais no formato '.ppm', que podem ser visualizadas com softwares de imagem compatíveis ou podem ser convetidas no formato '.png'.

## Funcionalidades

- Interseção de raios com esferas;
- Materiais: difusos, metálicos e dielétricos;
- Reflexão e refração de raios;
- Câmera com profundidade de campo;
- Geração de imagens '.ppm'.

## Cena Gerada
-

## Visualização da imagem
A imagem renderizada é salva no arquivo 'image.ppm'. É possível abrir esse arquivos com programas como:
- InfanView;
- GIMP;
- Visualizadores de imagem que suportem '.ppm';
- Ou converter para '.png'.

## Como executar o projeto

### Pré-requisitos

- Compilador C++ (recomendado: g++)
- Terminal (Linux/Mac) ou WSL/Git Bash (no Windows)

### Compilando
-

### Executando
./raytracer > image.ppm
