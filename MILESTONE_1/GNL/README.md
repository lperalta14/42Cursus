📘 Get Next Line

Milestone 01 del cursus de 42.

📖 Descripción

Get Next Line (GNL) es un proyecto cuyo objetivo es desarrollar una función en C capaz de leer una línea completa de un descriptor de archivo, sin importar su longitud.
Esta función debe manejar correctamente la lectura parcial, el almacenamiento del buffer y las sucesivas llamadas, devolviendo siempre una línea por ejecución.

El proyecto permite comprender cómo funciona la lectura de archivos a bajo nivel, el uso de buffers, la gestión de memoria dinámica y la manipulación de cadenas.

Este proyecto fortalece el entendimiento de:

Manipulación de descriptores de archivo (open, read, close)

Uso de buffers y almacenamiento intermedio

Gestión de memoria con malloc, free

Reutilización de funciones auxiliares de libft

⚙️ Compilación

Para compilar el proyecto y generar la librería, ejecuta el siguiente comando en la raíz del proyecto:

make


Esto generará un archivo get_next_line.a, que podrás enlazar en otros proyectos.

Comandos útiles:

make all      # Compila los archivos .c y crea get_next_line.a
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los archivos objeto y la librería
make re       # Limpia y recompila todo desde cero

🚀 Ejecución

Este proyecto no genera un programa ejecutable, sino una librería estática que puedes integrar en otros proyectos.

Para usarla, incluye el header y enlaza la librería al compilar:

cc main.c -L. -lgnl -o mi_programa


Y asegúrate de incluir el header en tu código:

#include "get_next_line.h"

🧩 Conceptos clave

Lectura de archivos con read()

Manejo de buffers y almacenamiento temporal

Manipulación de cadenas dinámicas

Control de memoria dinámica con malloc y free

Implementación modular y reutilizable con Makefile

Creación y uso de librerías estáticas (.a)

📎 Documentación completa

📄 get_next_line.pdf
 (si lo tienes generado, o puedes poner el enlace a la carpeta docs/ en tu repo)

👤 Autor

Luis Peralta
📍 42 Málaga
💻 GitHub: lperalta14
