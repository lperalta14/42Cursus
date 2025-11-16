# 🧠 Push_Swap

> Algoritmo de ordenación optimizado usando dos stacks y operaciones limitadas.  
> El reto: ordenar con el menor número de movimientos posible.

---

## 📘 Descripción general

Este proyecto forma parte del **Cursus de 42 Málaga** y se incluye dentro del **MILESTONE_2**, enfocado en el desarrollo de competencias como:
- Diseño e implementación de algoritmos de ordenación eficientes.
- Análisis de complejidad algorítmica (Big O notation).
- Manipulación de estructuras de datos tipo stack.
- Optimización de número de operaciones.

El objetivo principal es **ordenar una lista de números enteros** utilizando únicamente dos stacks (A y B) y un conjunto limitado de operaciones, buscando minimizar el número total de movimientos.

**Evaluación:**
- 3 números: máximo 3 operaciones
- 5 números: máximo 12 operaciones
- 100 números: < 700 operaciones = nota máxima ⭐
- 500 números: < 5500 operaciones = nota máxima ⭐

---

## ⚙️ Tecnologías y herramientas

| Categoría | Herramienta / Tecnología |
|------------|--------------------------|
| Lenguaje | C |
| Compilador | GCC / Clang |
| Estilo | Norminette |
| Depuración | Valgrind / GDB |
| Control de versiones | Git + GitHub |
| Librería personal | [My_library](https://github.com/lperalta14/My_library) |
| Algoritmo implementado | Turk Algorithm / Radix Sort |

---

## 🧩 Estructura del proyecto

```bash
📦 Push_Swap
├── src/
│   ├── main.c                  # Punto de entrada
│   ├── checkers.c              # Validación de argumentos
│   ├── errors.c                # Gestión de errores
│   ├── get_arguments.c         # Parseo de entrada
│   ├── push_swap.c             # Lógica principal
│   ├── calculate_costs.c       # Cálculo de costos de movimientos
│   └── moves/
│       ├── push.c              # Operaciones pa/pb
│       ├── swap.c              # Operaciones sa/sb/ss
│       ├── rotate.c            # Operaciones ra/rb/rr
│       ├── reverserotate.c     # Operaciones rra/rrb/rrr
│       ├── movesrot.c          # Rotaciones combinadas
│       ├── targets.c           # Cálculo de posiciones objetivo
│       └── utils_movements.c   # Utilidades de movimientos
├── BONUS/
│   ├── checker_bonus.c         # Programa checker (bonus)
│   ├── arg_check_bonus.c       # Validación bonus
│   ├── moves_bonus.c           # Operaciones bonus
│   └── utils_bonus.c           # Utilidades bonus
├── includes/
│   ├── push_swap.h             # Cabeceras principales
│   └── push_swap_bonus.h       # Cabeceras bonus
├── mylib/                      # Librería personal (auto-descargada)
├── Makefile                    # Compilación automatizada
└── README.md                   # Esta documentación
```

---

## 🚀 Compilación y ejecución
### 📥 Clonar solo este proyecto

**Opción 1: Con Git (recomendado)**
```bash
git clone --filter=blob:none --sparse https://github.com/lperalta14/lperalta14.git
cd lperalta14
git sparse-checkout set MILESTONE_2/Push_Swap
cd MILESTONE_2/Push_Swap
```

**Opción 2: Con SVN (más rápido)**
```bash
svn export https://github.com/lperalta14/lperalta14/trunk/MILESTONE_2/Push_Swap
cd Push_Swap
```

### 🛠️ Compilar
```bash
# Compilar push_swap
make

# Compilar checker (bonus)
make bonus
```

### ▶️ Ejecutar

**Push_swap (imprime las operaciones)**
```bash
./push_swap [números a ordenar]
```

**Checker (valida si las operaciones ordenan correctamente)**
```bash
./push_swap [números] | ./checker [números]
```

### 🧪 Ejemplos

**Ejemplo 1: Ordenar 5 números**
```bash
./push_swap 3 2 5 1 4
```
**Salida:**
```
pb
pb
sa
pa
pa
```

**Ejemplo 2: Validar con checker**
```bash
./push_swap 4 2 7 1 | ./checker 4 2 7 1
```
**Salida:**
```
OK
```

**Ejemplo 3: Números negativos**
```bash
./push_swap -5 0 3 -1 8
```

**Ejemplo 4: Test con números aleatorios**
```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

---

## 🎯 Operaciones disponibles

### Stack A y Stack B

| Operación | Descripción |
|-----------|-------------|
| `sa` | Swap A - Intercambia los 2 primeros elementos de A |
| `sb` | Swap B - Intercambia los 2 primeros elementos de B |
| `ss` | `sa` y `sb` simultáneamente |
| `pa` | Push A - Mueve el primer elemento de B a A |
| `pb` | Push B - Mueve el primer elemento de A a B |
| `ra` | Rotate A - Primer elemento pasa al final |
| `rb` | Rotate B - Primer elemento pasa al final |
| `rr` | `ra` y `rb` simultáneamente |
| `rra` | Reverse Rotate A - Último elemento pasa al principio |
| `rrb` | Reverse Rotate B - Último elemento pasa al principio |
| `rrr` | `rra` y `rrb` simultáneamente |

---

## 🔍 Tests y validaciones

- **Valgrind** para comprobar fugas de memoria:
  ```bash
  valgrind --leak-check=full ./push_swap 3 2 1 5 4
  ```

- **Norminette** para verificar estilo:
  ```bash
  norminette src/ includes/ BONUS/
  ```

- **Test de rendimiento (100 números)**:
  ```bash
  #!/bin/bash
  sum=0
  for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    ops=$(./push_swap $ARG | wc -l)
    sum=$((sum + ops))
    echo "Test $i: $ops operaciones"
  done
  avg=$((sum / 100))
  echo "Promedio: $avg operaciones"
  ```

- **Validación de errores**:
  ```bash
  # Números duplicados
  ./push_swap 1 2 3 2
  # Output: Error
  
  # No numérico
  ./push_swap 1 2 abc
  # Output: Error
  
  # Fuera de rango INT
  ./push_swap 2147483648
  # Output: Error
  ```

- **Test con checker**:
  ```bash
  # Operaciones correctas
  ./push_swap 4 2 7 1 | ./checker 4 2 7 1
  # Output: OK
  
  # Operaciones incorrectas
  echo "sa\npb" | ./checker 4 2 7 1
  # Output: KO
  ```

---

## 🧠 Conceptos clave del proyecto

- [x] Algoritmos de ordenación (Turk, Radix, Quick Sort adaptado)
- [x] Análisis de complejidad algorítmica
- [x] Estructuras de datos: stacks (pilas)
- [x] Optimización de movimientos
- [x] Cálculo de costos de operaciones
- [x] Validación de entrada y gestión de errores
- [x] Gestión de memoria dinámica
- [x] Testing y benchmarking

---

## 📈 Retos y aprendizajes

**Lo más difícil:**
- Encontrar el algoritmo óptimo que minimice operaciones
- Calcular eficientemente el "costo" de mover cada elemento
- Gestionar casos edge (3 números, 5 números, ya ordenados)
- Optimizar las rotaciones dobles (rr, rrr)

**Lo que aprendí:**
- Diferentes estrategias de ordenación adaptadas a restricciones
- Cómo calcular y minimizar costos de movimientos
- La importancia del análisis previo antes de codificar
- Técnicas de optimización y refactorización

**Algoritmo implementado:**
He utilizado el **Turk Algorithm** (o algoritmo de costos mínimos):
1. Empujar todos los elementos a B excepto 3
2. Ordenar los 3 elementos en A
3. Para cada elemento en B, calcular el costo de moverlo a su posición correcta en A
4. Mover el elemento con menor costo
5. Repetir hasta que B esté vacío
6. Rotar A para que el mínimo quede arriba

---

## 📊 Resultados de rendimiento

| Cantidad | Operaciones | Objetivo | Estado |
|----------|-------------|----------|--------|
| 3 números | ~3 | < 3 | ✅ |
| 5 números | ~8-12 | < 12 | ✅ |
| 100 números | ~650 | < 700 | ⭐ |
| 500 números | ~5200 | < 5500 | ⭐ |

---

## 🧩 Bonus: Checker

El programa `checker` lee operaciones desde stdin y verifica si ordenan correctamente el stack:

```bash
# Introducir operaciones manualmente
./checker 4 2 7 1
sa
pb
pa
^D
# Output: KO

# Validar salida de push_swap
./push_swap 4 2 7 1 | ./checker 4 2 7 1
# Output: OK
```

---

## 👤 Autor

**Luis Peralta (lperalta14)**  
📍 42 Málaga  
💼 [LinkedIn](https://www.linkedin.com/in/lperaltamuñoz/)  
💻 [GitHub](https://github.com/lperalta14)  
📧 luisperaltamunoz@gmail.com

---

💡 *"El arte de ordenar no está en mover rápido, sino en mover bien."*
