## task 4: performance computing

### report

| Realization   | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| Python3       | 4 ms          | 7 ms          | 26 ms         | 228 ms        |
| Numba         | 0 ms          | 0 ms          | 3 ms          | 25 ms         |
| PyPy3         | 6 ms          | 12 ms         | 42 ms         | 132 ms        |
| ctypes        | 1 ms          | 1 ms          | 2 ms          | 12 ms         |
| SWIG          | 0 ms          | 1 ms          | 2 ms          | 6 ms          |

**Python3**

| CPU quantity  | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| 1 CPU         | 4 ms          | 7 ms          | 26 ms         | 228 ms        |
| 2 CPU         | 1 ms          | 3 ms          | 15 ms         | 129 ms        |

**Numba**

| CPU quantity  | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| 1 CPU         | 0 ms          | 0 ms          | 3 ms          | 25 ms         |
| 2 CPU         | 0 ms          | 0 ms          | 2 ms          | 19 ms         |


**PyPy3**

| CPU quantity  | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| 1 CPU         | 6 ms          | 12 ms         | 42 ms         | 132 ms        |
| 2 CPU         | 6 ms          | 14 ms         | 39 ms         | 107 ms        |


**ctypes**

| CPU quantity  | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| 1 CPU         | 1 ms          | 1 ms          | 2 ms          | 12 ms         |
| 2 CPU         | 1 ms          | 1 ms          | 2 ms          | 7 ms          |


**SWIG**

| CPU quantity  | 10 func       | 100 func      | 1000 func     | 10000 func    |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| 1 CPU         | 0 ms          | 1 ms          | 2 ms          | 6 ms          |
| 2 CPU         | 0 ms          | 1 ms          | 1 ms          | 4 ms          |
