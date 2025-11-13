# Libft

**Milestone 00** del cursus de 42.

---

## 📘 Descripción

**Libft** es el primer proyecto del cursus de 42, y su objetivo es implementar una librería propia en C que replique las funciones más utilizadas de la librería estándar (`<string.h>`, `<stdlib.h>`, `<ctype.h>`, etc.).  

El propósito de este proyecto es comprender a fondo cómo funcionan internamente las funciones básicas del lenguaje C, reforzar la gestión de memoria y desarrollar una base sólida para los proyectos futuros del cursus.  

Esta librería servirá como herramienta de apoyo para proyectos posteriores, como*Push_swap*, *so_long* o *pipex*.

---
📖 [Documentación completa de libft](https://lperalta14.github.io/42Cursus/libft_8h.html)

## ⚙️ Compilación

Para compilar la librería, ejecuta el siguiente comando en la raíz del proyecto:

make

Esto generará un archivo `libft.a`, que es la librería estática que podrás enlazar en otros proyectos.

Comandos útiles:

make all       # Compila todos los archivos .c en .o y crea libft.a  
make clean     # Elimina los archivos objeto (.o)  
make fclean    # Elimina los archivos objeto y libft.a  
make re        # Limpia y recompila todo desde cero  

---

## 🚀 Ejecución

Este proyecto no genera un programa ejecutable, sino una **librería estática** que puedes usar en otros proyectos.  

Para usarla, simplemente incluye el header y enlaza la librería al compilar tus programas:

cc main.c -L. -lft -o mi_programa

Y asegúrate de incluir el header en tu código:

#include "libft.h"

---

## 🧩 Conceptos clave

- Reimplementación de funciones estándar de C  
- Gestión de memoria dinámica con `malloc` y `free`  
- Manipulación de cadenas, listas y arrays  
- Buenas prácticas en modularidad y compilación con `Makefile`  
- Creación y uso de librerías estáticas (`.a`)  

---

## 👤 Autor

[Luis ](https://github.com/lperalta14)

