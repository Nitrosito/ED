###Ordenación por metodo Burbuja

- Ejecutable: ordenacionburbuja
- Datos: burbujaDiccionario.dat (peor caso,VERDE) y burbujaQuijote.dat (mejor caso,ROJO)

![Compatativa Datos Quijote y Diccionario]
(./images/burbuja_Quijote_Diccionario_v3.png)

La eficiencia del algoritmo de burbuja es de O(n²)

Si ajustamos los datos obtenidos a una curva f(x) = a * x^2 + b*x + c vemos como dicha función acota superiormente los valores que habíamos obtenido de manera empírica.


DICCIONARIO
Final set of parameters            Asymptotic Standard Error

a               = 2.71135e-08      +/- 2.306e-10    (0.8505%)
b               = -0.000111545     +/- 2.036e-05    (18.25%)
c               = 0.434936         +/- 0.374        (85.99%)


![Diccionario ajustado]
(./images/ajusteBurbuja.png)

#### Codigo ocurrencias.cpp
El algoritmo es de orden N, osea que la gráfica será lineal

- Ejecutable: ocurrencias.cpp
- Datos: ocurrenciasQuijote.dat

![Ocurrencias Quijote]
(./images/ocurrenciasQuijote.png)

Realizamos el ajuste para comprobarlo

![Ajuste Ocurrencias Quijote]
(./images/ajusteLinealOcurrencias.png)




