# 🧠 Pipex

Recreación del comportamiento de pipes de shell en C.
Sistema de comunicación entre procesos mediante pipes y redirecciones.


# 📘 Descripción general

Este proyecto forma parte del Cursus de 42 Málaga y se incluye dentro del MILESTONE_2, enfocado en el desarrollo de competencias como:

Gestión de procesos con fork() y execve().
Comunicación entre procesos mediante pipes.
Redirección de entrada/salida con file descriptors.
Manejo robusto de errores y memory leaks.

El objetivo principal es replicar el comportamiento del operador pipe (|) de Unix/Linux, permitiendo que la salida de un comando se convierta en la entrada del siguiente, tal como lo hace el shell.
Equivalencia:
```bash
./pipex infile "cmd1" "cmd2" outfile
# Es equivalente a:
< infile cmd1 | cmd2 > outfile
```
# ⚙️ Tecnologías y herramientas

| Categoría | Herramienta / Tecnología |
|------------|--------------------------|
| Lenguaje | C |
| Compilador | GCC / Clang |
| Estilo | Norminette |
| Depuración | Valgrind / GDB |
| Control de versiones | Git + GitHub |
| Librería personal | My_library |

# 🧩 Estructura del proyecto
```bash
📦 Pipex
├── src/
│   ├── pipex.c             # Punto de entrada del programa y creación y gestión de pipes
│   ├── errors.c            # Gestión de fork y execve
│   ├── path.c              # Búsqueda de comandos en PATH
│   └── utils.c             # Funciones auxiliares
├── includes/
│   └── pipex.h             # Cabeceras y prototipos
├── my_lib/                 # Librería personal (clonada automáticamente)
├── Makefile                # Compilación automatizada
└── README.md               # Esta documentación
```
# 🚀 Compilación y ejecución
🛠️ Compilar
```bash
# El Makefile descarga automáticamente la librería personal
make
```
▶️ Ejecutar
```bash
./pipex archivo_entrada "comando1" "comando2" archivo_salida
```
🧪 Ejemplos
**Ejemplo 1: Contar líneas**
```bash
./pipex infile "ls -l" "wc -l" outfile
```
Equivalente a:
```bash
< infile ls -l | wc -l > outfile
```
**Ejemplo 2: Buscar y contar**
```bash
./pipex input.txt "cat" "grep error" output.txt
```
Equivalente a:
```bash
< input.txt cat | grep error > output.txt
```
**Ejemplo 3: Con archivos reales**
```bash
echo "Hola mundo" > test.txt
./pipex test.txt "cat" "wc -w" result.txt
cat result.txt
# Output: 2
```
# 🔍 Tests y validaciones

**Valgrind** para comprobar fugas de memoria:
```bash
valgrind --leak-check=full --track-fds=yes ./pipex infile "cat" "wc -l" outfile
```
**Comparación con shell:**
```bash
  # Crear archivo de prueba
  echo -e "line1\nline2\nline3" > test.txt

  # Ejecutar pipex
  ./pipex test.txt "cat" "wc -l" out1.txt
  
  # Ejecutar comando equivalente en shell
  < test.txt cat | wc -l > out2.txt
  
  # Comparar resultados
  diff out1.txt out2.txt
```
**Gestión de errores:**
```bash
  # Archivo inexistente
  ./pipex noexiste.txt "cat" "wc -l" out.txt
  
  # Comando inválido
  ./pipex test.txt "comandoinvalido" "wc -l" out.txt
  
  # Permisos denegados
  chmod 000 test.txt
  ./pipex test.txt "cat" "wc -l" out.txt
```
# 🧠 Conceptos clave del proyecto

 - Gestión de procesos con fork()
 - Ejecución de comandos con execve()
 - Comunicación mediante pipes (pipe())
 - Redirección de file descriptors (dup2())
 - Búsqueda de comandos en variable PATH
 - Manejo de errores estilo shell
 - Gestión correcta de memoria sin leaks
 - Espera de procesos hijos con wait()/waitpid()


# 📈 Retos y aprendizajes
**Lo más difícil:**

- Entender el flujo de file descriptors y cuándo cerrar cada uno
- Gestionar correctamente los procesos padre e hijo
- Replicar exactamente el comportamiento de bash con los errores

**Lo que aprendí:**

- La importancia de cerrar todos los file descriptors innecesarios
- Cómo funciona la comunicación entre procesos (IPC)
- El manejo de variables de entorno y búsqueda en PATH
- Debugging de programas con múltiples procesos usando GDB

**Lo que mejoraría:**

- Implementar bonus con múltiples pipes (más de 2 comandos)
- Añadir soporte para here_doc (<<)
- Optimizar la búsqueda de comandos en PATH


# 🧩 Funciones del sistema utilizadas
 Función          | Uso                                      |
|------------------|-------------------------------------------|
| `fork()`         | Crear procesos hijo                       |
| `pipe()`         | Crear canal de comunicación                |
| `dup2()`         | Redirigir *file descriptors*               |
| `execve()`       | Ejecutar comandos                          |
| `access()`       | Verificar existencia de archivos           |
| `open()`         | Abrir archivos                             |
| `close()`        | Cerrar *file descriptors*                  |
| `wait()` / `waitpid()` | Esperar procesos hijo              |
| `perror()`       | Mostrar errores del sistema                |

# 👤 Autor
**Luis Peralta (lperalta14)**
📍 42 Málaga
💼 LinkedIn
💻 GitHub
📧 luisperaltamunoz@gmail.com

💡 "Cada pipe es un puente entre procesos, cada fork es una oportunidad de aprender."
