🖨️ ft_printf

Milestone 02 del cursus de 42.

📖 Descripción

ft_printf es una reimplementación parcial de la función estándar printf de la librería C.
El objetivo es reproducir su comportamiento utilizando solo funciones permitidas y sin usar la libc original, construyendo una versión personalizada que gestione la formateación de texto, números y punteros.

El proyecto profundiza en:

Manejo de argumentos variables (va_list)

Conversión y formateo de distintos tipos de datos

Manipulación de cadenas y caracteres

Buenas prácticas en modularidad y reutilización de funciones (libft)

⚙️ Compilación

Para compilar la librería estática:

make


Esto generará libftprintf.a, lista para ser enlazada con tus proyectos.

Comandos útiles:

make all      # Compila todos los .c y crea libftprintf.a
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los archivos objeto y la librería
make re       # Limpia y recompila todo desde cero

🚀 Ejecución

Al igual que libft y get_next_line, ft_printf no produce un ejecutable.
Para probarlo, enlázalo con tu programa principal:

cc main.c -L. -lftprintf -o test_printf


Y en tu código incluye el header correspondiente:

#include "ft_printf.h"

🧩 Funcionalidades implementadas

El proyecto debe soportar los siguientes format specifiers:

Especificador	Descripción
%c	Imprime un carácter
%s	Imprime una cadena de caracteres
%p	Imprime una dirección de memoria (en hexadecimal)
%d / %i	Imprime un número decimal (entero con signo)
%u	Imprime un número entero sin signo
%x / %X	Imprime un número hexadecimal (minúsculas/mayúsculas)
%%	Imprime un símbolo % literal
💡 Conceptos clave

Uso de va_start, va_arg, va_end

Conversión numérica y base (decimal/hexadecimal)

Implementación modular (división en funciones por tipo)

Control de buffer y conteo de caracteres impresos

Reutilización de funciones de libft

📎 Documentación completa

📄 ft_printf.pdf
 (o el enlace a la carpeta docs/ de tu repo si aún no tienes el PDF)

👤 Autor

Luis Peralta
📍 42 Málaga
💻 GitHub: lperalta14
