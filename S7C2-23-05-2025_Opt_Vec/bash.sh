parallel 'g++ -O{} matmul_block.cpp -o matmul_block_{}.x' ::: 0 1 2 3 fast; 
parallel --progress './matmul_block_{1}.x 1024 {2} 10 >> data_{1}.txt' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024;

for opt in 0 1 2 3 fast; 
    do sort -nk 2 data_$opt.txt > data_sorted_$opt.txt; done;

gnuplot graficas.gp