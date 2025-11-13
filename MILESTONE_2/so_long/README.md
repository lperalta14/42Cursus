# 🧠 So_Long

> Videojuego muy sencillo en 2D.  
> Primer contacto con desarrollo de videojuegos usando MLX42.

---

## 📘 Descripción general

Este proyecto forma parte del **Cursus de 42 Málaga** y se incluye dentro del **MILESTONE_2**, enfocado en el desarrollo de competencias como:
- Programación gráfica con la biblioteca MLX42.
- Gestión de eventos de teclado y ventana.
- Renderizado de sprites y texturas.
- Validación de mapas y pathfinding.
- Game loop y lógica de juego básica.

El objetivo principal es **crear un juego 2D donde el jugador debe recoger todos los coleccionables y encontrar la salida**, navegando por un mapa definido en un archivo `.ber`.

**Reglas del juego:**
- 🎮 Muévete con WASD o flechas
- 🪙 Recoge todos los coleccionables (C)
- 🚪 Encuentra la salida (E)
- 📊 Minimiza tus movimientos

---

## ⚙️ Tecnologías y herramientas

| Categoría | Herramienta / Tecnología |
|------------|--------------------------|
| Lenguaje | C |
| Compilador | GCC / Clang |
| Estilo | Norminette |
| Depuración | Valgrind / GDB |
| Librería gráfica | MLX42 (OpenGL wrapper) |
| Control de versiones | Git + GitHub |
| Librería personal | [My_library](https://github.com/lperalta14/My_library) |

---

## 🧩 Estructura del proyecto

```bash
📦 so_long
├── src/
│   ├── so_long.c               # Punto de entrada
│   ├── error.c                 # Gestión de errores
│   ├── check_create/
│   │   ├── parseo.c            # Parseo del mapa
│   │   ├── flood_fill.c        # Validación de camino válido
│   │   └── map.c               # Creación de estructura del mapa
│   ├── init.c                  # Inicialización de MLX y texturas
│   ├── drawmap.c               # Renderizado del mapa
│   ├── hooks.c                 # Gestión de eventos
│   └── moveplayer.c            # Movimiento del jugador
├── includes/
│   └── so_long.h               # Cabeceras y estructuras
├── assets/
│   ├── sprites/                # Texturas .png
│   │   ├── player.png
│   │   ├── wall.png
│   │   ├── collectible.png
│   │   ├── exit.png
│   │   └── floor.png
│   └── maps/                   # Mapas .ber
│       ├── map1.ber
│       ├── map2.ber
│       └── invalid_map.ber
├── my_lib/                     # Librería personal (auto-descargada)
├── MLX42/                      # Biblioteca gráfica
├── Makefile                    # Compilación automatizada
└── README.md                   # Esta documentación
```

---

## 🚀 Compilación y ejecución

### 📦 Requisitos previos

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install -y build-essential libglfw3-dev libglfw3 cmake
```

**MLX42:**
```bash
git clone https://github.com/codam-coding-college/MLX42.git
```

### 🛠️ Compilar
```bash
# El Makefile descarga automáticamente la librería personal
# y compila MLX42 si existe en el directorio
make
```

### ▶️ Ejecutar
```bash
./so_long maps/map.ber
```

### 🧪 Ejemplos

**Ejemplo 1: Mapa básico**
```bash
./so_long assets/maps/map1.ber
```

**Ejemplo 2: Crear tu propio mapa**
```bash
# Archivo: custom_map.ber
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

./so_long custom_map.ber
```

---

## 🗺️ Formato del Mapa

Los mapas deben tener extensión `.ber` y seguir estas reglas:

### Componentes

| Carácter | Significado |
|----------|-------------|
| `0` | Espacio vacío (camino) |
| `1` | Muro (obstáculo) |
| `C` | Coleccionable |
| `E` | Salida |
| `P` | Posición inicial del jugador |

### Reglas de Validación

✅ El mapa debe ser rectangular  
✅ Rodeado completamente por muros (`1`)  
✅ Contener **exactamente 1 salida** (`E`)  
✅ Contener **al menos 1 coleccionable** (`C`)  
✅ Contener **exactamente 1 posición inicial** (`P`)  
✅ Debe existir un camino válido de `P` a `E` recogiendo todos los `C`

### Ejemplo de Mapa Válido

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Ejemplo de Mapa Inválido

```
1111111111
100100C001  ← No rectangular
1000111101
1P001E0001
111111111   ← Faltan muros
```

---

## 🎮 Controles

| Tecla | Acción |
|-------|--------|
| `W` / `↑` | Mover arriba |
| `A` / `←` | Mover izquierda |
| `S` / `↓` | Mover abajo |
| `D` / `→` | Mover derecha |
| `ESC` | Salir del juego |

---

## 🔍 Tests y validaciones

- **Valgrind** para comprobar fugas de memoria:
  ```bash
  valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map1.ber
  ```

- **Norminette** para verificar estilo:
  ```bash
  norminette src/ includes/
  ```

- **Tests de mapas**:
  ```bash
  # Mapa válido - debe iniciar el juego
  ./so_long assets/maps/valid_map.ber
  
  # Mapa sin salida - debe mostrar Error
  ./so_long assets/maps/no_exit.ber
  
  # Mapa no rectangular - debe mostrar Error
  ./so_long assets/maps/not_rectangular.ber
  
  # Mapa sin camino válido - debe mostrar Error
  ./so_long assets/maps/no_path.ber
  ```

- **Test de jugabilidad**:
  ```bash
  # Verificar contador de movimientos
  ./so_long maps/small.ber
  # Mover jugador y verificar que se imprime en terminal
  
  # Verificar colisiones con muros
  ./so_long maps/walls.ber
  # Intentar atravesar muros
  
  # Verificar sistema de coleccionables
  ./so_long maps/collectibles.ber
  # Intentar salir sin recoger todos
  ```

---

## 🧠 Conceptos clave del proyecto

- [x] Programación gráfica con MLX42
- [x] Game loop y renderizado continuo
- [x] Event-driven programming (eventos de teclado)
- [x] Parseo y validación de archivos
- [x] Algoritmo Flood Fill (BFS/DFS) para validar caminos
- [x] Gestión de sprites y texturas
- [x] Colisiones y lógica de juego
- [x] Gestión de memoria de recursos gráficos

---

## 📈 Retos y aprendizajes

**Lo más difícil:**
- Implementar el algoritmo Flood Fill para validar que existe un camino válido
- Gestionar correctamente la memoria de MLX42 (imágenes y texturas)
- Sincronizar el renderizado con los eventos del teclado
- Parsear correctamente el mapa y detectar todos los casos de error

**Lo que aprendí:**
- Fundamentos de desarrollo de videojuegos
- Cómo funciona un game loop básico
- Gestión de eventos en tiempo real
- Algoritmos de pathfinding (Flood Fill)
- Trabajo con librerías gráficas externas
- Importancia del asset management

**Mejoras implementadas:**
- Contador de movimientos visible en terminal
- Validación exhaustiva de mapas con mensajes de error específicos
- Sprites personalizados
- Sistema de colisiones robusto

---

## 🎨 Características implementadas

### Obligatorias
- ✅ Renderizado de mapas 2D con texturas
- ✅ Movimiento del jugador en 4 direcciones
- ✅ Colisiones con muros
- ✅ Sistema de coleccionables
- ✅ Salida activable solo después de recoger todos los coleccionables
- ✅ Contador de movimientos en terminal
- ✅ Validación completa de mapas
- ✅ Gestión de errores robusta

### Bonus (opcional)
- 🌟 Animaciones de sprites
- 🌟 Enemigos patrullando
- 🌟 Contador visual en pantalla
- 🌟 Múltiples niveles

---

## ⚠️ Gestión de Errores

El programa detecta y gestiona:

```
Error: Map file not found
Error: Invalid map extension (must be .ber)
Error: Map is not rectangular
Error: Map not surrounded by walls
Error: Invalid number of players (must be 1)
Error: Invalid number of exits (must be 1)
Error: No collectibles found
Error: No valid path to exit
Error: Memory allocation failed
```

---

## 🔗 Recursos útiles

- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [Game Programming Patterns](https://gameprogrammingpatterns.com/)

---

## 👤 Autor

**Luis Peralta (lperalta14)**  
📍 42 Málaga  
💼 [LinkedIn](https://www.linkedin.com/in/lperaltamuñoz/)  
💻 [GitHub](https://github.com/lperalta14)  
📧 luisperaltamunoz@gmail.com

---

💡 *"So Long, and Thanks for All the Fish!" - Douglas Adams*  
🎮 *Mi primer videojuego en C, muchos bugs, mucho aprendizaje.*
