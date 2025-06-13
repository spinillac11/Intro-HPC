HPC
Programas eficientes

## 9. Optimización (profiling -> dónde optimizar): ##############################################

9.1 Banderas de compilación
3 Niveles (-Ox, con x en {0,1,2,3,fast}):
    1: básico
    2: estándar
    3: más rápido pero de cuidado, puede hacer cosas raras.

Programación por bloques (caché CPU) (tamaño bloque ?)


¿cómo puedo sacar el índice 1d para (i,j) con m filas y n columnas. Para el caso de RowMajor tenemos en cuenta el número de columnas
    Estrategia: recordar conversion de binario a decimal.
    1d = id = id(i,j) = i*n^1 + j*n^0
                      = i*n + j
Para calcular la función inversa hago uso del módulo y deel truncamiento para int / int
    i = id / n
    j = id % n

Detalles / trucos:
    1. Cosas viejas
    2. Lenguaje prog consola
    >> for val in 0 1 2 3 fast; do echo "Optim level: $val"; gcc -O$val file_name; ./a.out; done

Refs:
Donald Knuth


Procesamiento en Parlelo (gnu parallel):
    parallel 'echo 2' ::: 1 // Ejecuta en paralelo
    parallel 'echo {}' ::: 1 2 3 4
    parallel './a.out {}' ::: 2 4 8 16 32 // Ejecuta l programa en paralelo para cada argumento
    parallel 'echo {}' ::: 1 2 3 4 ::: A B C D // TOdas las combinaciones de los posible argumentos

    -- dry-run  para ver que se ejecutaría sin hacerlo  
    WARNING: Cambiar el nombre a los archivos generados según el caso (a.out, .txt) porque todos sobre escribirian en el mismo

    # Multiple parameter sets
        parallel echo "Processing {1} with {2}" ::: file1 file2 file3 ::: option-a option-b

    # Cartesian product of parameters
        parallel "convert {1} -resize {2} resized_{1}" ::: *.jpg ::: 50% 75% 100%

    # Using input files for parameters
        echo -e "param1\nparam2\nparam3" | parallel echo "Processing: {}"
    
    # Limit number of parallel jobs
        parallel -j4 command ::: args

    # Use all available CPU cores
        parallel -j0 command ::: args

    # Run jobs sequentially (useful for debugging)
        parallel -j1 command ::: args

Tarea -> tiempo de ejecución en función de block size para distintas optimizaciones:
    Instrucción parallel
        parallel 'g++ -O{} matmul_block.cpp -o matmul_block_{}.x' ::: 0 1 2 3 fast 
        parallel --progress './matmul_block_{1}.x 1024 {2} 10 >> data_{1}.txt' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024 



## S8C1 - Profiling (Determinar donde se puede ahorrar tiempo en la ejecuión) ##############################################

Cuando se hace el profiling es bueno tartar que se demore bastante para tener una buena muestra

Medir tiempo comleto de ejecución y saca un pequeño reporte en la cosola
    /usr/bin/time ./a.out 
    llamadas de usuario (funcion local) y llamadas al sistema operativo (Pide memoria)

Measuring elapsed time:
    std::chrono -> Mide tiempo de reloj
    steady_clock -> no corresponde al tiempo del sistema operativo
    high_resolution_clock y system_clock no necesariamente garantizan estabilidad para comparar

Ctime:
    Permite obtener el tiempo de procesador para tareas en paralelo

Profilers (Informe sobre tiempo de funciones):
    
    gprof (Linux/Unix):
        gcc -Wall -pg -g test_gprof.c -o test_gprof.x   (-pg para obtener la información de profiling gmon.out) 
        gprof test_gprof.x gmon.out > analysis.txt (Pasar informe a .txt)

## S8C2 - Profiling_perf:
    Reporte:
        gcc -g -fno-omit-frame-pointer test1.c (Bandera para que encuentre las funciones que llama por dentro)
        perf record ./a.out
        perf report
    
    Flame graphs:
        perf record --call-graph dwarf  -F 99 -g -- ./a.out
        perf script > out.perf
        ~/Downloads/FlameGraph/stackcollapse-perf.pl ./out.perf > out.folded
        ~/Downloads/FlameGraph/flamegraph.pl out.folded > flamegraph.svg
        firefox flamegraph.svg

    Volver una secarga ejecutable (chmod +x):
        Ejemplo intalación Appimage de Hotspot:
        chmod +x ~/Downloads/hotspot-v1.5.1-x86_64.AppImage 

    Dejar procesos en la sala:
        nohup command &   o   tmux command

## S9C2 - MatrixOperations
    eigen library: 
        Ejecución en paralelo: 
            compilar con -fopenmp
            OMP_NUM_THREADS=n /usr/bin/time ./a.out ... 2>dev/null

    Metricas: speedup, eficiencia.

## S10C2 - Intro_HPC:
    Un mismo programa ejecutandose en varios cores (no uno mismo con distintos parametros).
    Paraview - Visualización en paralelo

    Metricas: EspeedUp - eficiencia en paalelo

    MathGPT

    1. OpenMP: Ejecución en paralelo dentro del programa divide en varios trheads
        #pragma omp parallel --> g++ -fopenmp -g -fsanitize=undefined,thread openmp.cpp
        OMP_NUM_THREADS=4 ./a.out //número de threads a utilizar
        (NO es compatible con leak ni address) //Se necesita la bandera para que tome en cuenta la paralelización

        Notas: Lo que se declara dentro de #pragma omp parallel es PRIVADO PARA CADA THREAD

        Memoria compartida: 

    2. MPI: is a library API that allows process to interchange data in a distributed memory context. 
        mpic++  mpi.cpp 
        mpirun -np 4 ./a.out