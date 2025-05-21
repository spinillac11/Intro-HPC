
for val in 0 1 2 3 fast; 
    do echo "Optimization level: $val"; 
    gcc -O$val transpose_blocking.c; 
    OPT=$val; MSIZE=512; 
    for ((csize=1; csize <= $MSIZE; csize *= 2)); 
        do echo -n $MSIZE $csize; 
        ./a.out $MSIZE $csize " "; 
    done > data_$OPT.txt; 
done
echo "Graficando";
gnuplot graficas.gp;

