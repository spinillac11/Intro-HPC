set terminal pdfcairo enhanced color font 'Arial,12'
set output "Optimizaciongf.pdf"

set title "Distintos niveles de optimización"
set title "Distintos niveles de optimización"
set xlabel "Tamaño del bloque"
set ylabel "Tiempo"
set logscale x
set grid

plot \
    "data_sorted_0.txt" using 2:3 with lines title "OPT=0", \
    "data_sorted_1.txt" using 2:3 with lines title "OPT=1", \
    "data_sorted_2.txt" using 2:3 with lines title "OPT=2", \
    "data_sorted_3.txt" using 2:3 with lines title "OPT=3", \
    "data_sorted_fast.txt" using 2:3 with lines title "OPT=fast", 
