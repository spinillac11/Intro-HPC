set terminal pdfcairo enhanced color font 'Arial,12'
set output "Optimizaciongf.pdf"

set title "Distintos niveles de optimización"
set title "Distintos niveles de optimización"
set xlabel "Tamaño del bloque"
set ylabel "Tiempo"
set logscale x
set grid

plot \
    "data_0.txt" using 2:3 with points title "OPT=0", \
    "data_1.txt" using 2:3 with points title "OPT=1", \
    "data_2.txt" using 2:3 with points title "OPT=2", \
    "data_3.txt" using 2:3 with points title "OPT=3", \
    "data_fast.txt" using 2:3 with points title "OPT=fast", 
