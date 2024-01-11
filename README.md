# Ordenador Alfabético de Palabras

Este repositorio contiene un programa en C++ que ordena alfabéticamente un archivo de texto con palabras, algunas de las cuales pueden estar repetidas. El resultado se guarda en otro archivo de texto con las palabras ordenadas junto con sus repeticiones.

## Desarrollo

### Clases Implementadas

1. **`Tree`**: Clase que genera un árbol n-ario semicompleto donde cada palabra se representa en un nodo, y las repeticiones se cuentan en el mismo nodo.

2. **`Heap`**: Clase que utiliza la clase `Tree` como base para implementar un heap binario. Los elementos se ordenan de manera que un nodo padre siempre sea mayor que todos sus nodos hijos. Incluye el método `sort` para ordenar las instancias del heap.

### Función Principal (`main`)

1. Lee el archivo "Input.txt" y procesa las palabras.
2. Reemplaza las vocales acentuadas por sus equivalentes sin acentuación, la letra "ñ" por la "n", y elimina caracteres como ",", ".", "()", "¿?", entre otros.
3. Inserta las palabras en una instancia de la clase `Heap`.
4. Ordena el heap utilizando el método `sort`.
5. Genera el archivo "Output.txt" con la lista de palabras ordenadas alfabéticamente, sus repeticiones y el número de comparaciones realizadas.

## Análisis de Complejidad

Realizando pruebas con un heap binario, se confirmó que la complejidad del algoritmo es del orden de 𝑂(𝑛log(𝑛)), donde 𝑛 es el número de palabras.

### Resultados

Se realizaron pruebas variando el número de palabras y obteniendo el siguiente resultado:

| Palabras | n Log(n) | Resultado |
|----------|----------|-----------|
| 333      | 2790     | 3979      |
| 5581     | 1535     | 16246     |
| 24978    | 32493    | 6269      |
| 79077    | 127366   | 158155    |
| 6860     | 87424    | 141112    |
| 174848   | 9917     | 131655    |
| 223459   | 263310   | 19781     |
| 564622   | 29699    | 441272    |
| 761194   | 882543   | 39707     |
| 1053909  | 1213216  | 79356     |
| 2234880  | 2583205  |           |