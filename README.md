README.md creado exitosamente con:

- Título y badges de tecnologías detectadas (C++98, Makefile, OOP, AddressSanitizer)
- Elevator pitch sobre el propósito del módulo
- Features de cada ejercicio (Megaphone, PhoneBook, Account)
- Stack tecnológico extraído de los Makefiles y código
- Decisiones técnicas explicando C++98 y Rule of Three
- Diagrama Mermaid con arquitectura de los 3 ejercicios
- Guíade instalación con comandos make
- Sección de contacto
Elevator Pitch:** Este módulo representa la introducción formal a C++ en el currículum deEscuela 42, sentando las bases del desarrollo orientado a objetos. A través de tres ejercicios progresivos, se exploran los fundamentos esenciales: depuiso de I/O streams hasta la implementación completa de clases con encapsulación, gestión de memoria y uso de contenedores STL.

---

## Características Principales

### Megaphone (ex00)
- Transformación de texto a mayúsculas via línea de comandos
- Manejo de argumentos `argc/argv`
- Introducción a `std::iostream`

### PhoneBook (ex01)
- Agenda telefónica interactiva con capacidad para8 contactos
- Implementación completa de orientación a objetos:
  - Clases `Contact`, `PhoneBook`, `Menu`
  - Constructor de copia y operador de asignación
  - Encapsulación con getters/setters
- Validación de entrada y formato tabular
- Interfaz de terminal con frames ASCII

### Account (ex02)
- Sistema de cuentas bancarias con operaciones de depósito/retiro
- Miembros estáticos para tracking global de cuentas
- Logging con timestamps
- Integración de STL: `std::vector`, `std::for_each`, `std::mem_fun_ref`

---

## Stack Tecnológico

| Componente | Tecnología |
|------------|------------|
| Lenguaje | C++98 |
| Compilador | c++ (clang/g++) |
| Build System | Makefile |
| Librerías Estándar | `<iostream>`, `<string>`, `<vector>`, `<algorithm>`, `<iomanip>`, `<ctime>` |
| Herramientas de Debug | AddressSanitizer (-fsanitize=address) |

---

## Decisiones Técnicas / Arquitectura

El proyecto sigue el estándar **C++98**, un requisito intencionado de Escuela 42 que fuerza al desarrollador adominar los fundamentos del lenguaje sin el azúcar sintáctico de estándares modernos (C++11 y superiores). Esta restricción pedagógica garantiza la comprensión profunda de:

- **Gestión manual de recursos**: Sin smart pointers, se internaliza la responsabilidad del ciclo de vida de objetos.
- **Rule of Three**: Implementación explícita de constructores de copia y operadores de asignación.
- **STL clásico**: Uso de algoritmos como `std::for_each` con `std::mem_fun_ref`, patrones fundamentales que perviven en código legacy empresarial.

La arquitectura modular separa cada ejercicio en su propio directorio con Makefiles independientes, facilitando la compilación incremental y el testing aislado de cada componente.

---

## Diagrama de Arquitectura

```mermaid
flowchart TB
    subgraph ex00["ex00: Megaphone"]
        A[main] --> B[Argumentos CLI]
        B --> C[toupper loop]
        C --> D[stdout]
    end

    subgraph ex01["ex01: PhoneBook"]
        E[main.cpp] --> F[Menu]
        F --> G[PhoneBook]
        G --> H[Contact Array 8 slots]
        F --> I[Input Validation]
        I --> J[Format & Display]
    end

    subgraph ex02["ex02: Account"]
        K[tests.cpp] --> L[std::vector Account]
        L --> M[Account Class]
        M --> N[Static Members]
        N --> O[Global Tracking]
        M --> P[Deposits/Withdrawals]
        P --> Q[Timestamped Logging]
    end
``---

## Guía de Instalación

### Requisitos Previos
- Compilador C++ (g++ o clang++)
- Make

### Compilación y Ejecución

```bash
# Clonar el repositorio
git clone https://github.com/samuelhm/CPP-Module-00.git
cd CPP-Module-00

# Ejercicio 00 - Megaphone
cd ex00 && make && ./megaphone "hola mundo"

# Ejercicio 01 - PhoneBook
cd ../ex01 && make && ./phonebook

# Ejercicio 02 - Account
cd ../ex02 && make && ./account
```

### Comandos Make Disponibles
```bash
make        # Compilar
make clean  # Limpiar objetos
make fclean # Limpiar todo
make re     # Recompilar desde cero
```

---

## Contacto

| Plataforma | Enlace |
|------------|--------|
| GitHub | [github.com/samuelhm](https://github.com/samuelhm/) |
| LinkedIn | [linkedin.com/in/shurtado-m](https://www.linkedin.com/in/shurtado-m/) |

---

*Este proyecto forma parte del currículum deEscuela 42 Barcelona.*