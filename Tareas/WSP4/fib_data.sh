parallel 'g++ -O{} fibonacci.cpp -o fibonacci_{}.x' ::: 0 1 2 3 fast; 

for ((n=2; n <= 50; n += 2)); 
    do echo "$n"; 
done > data_n.txt;

parallel --progress './fibonacci_{1}.x {2} >> data_{1}.txt' ::: 0 1 2 3 fast :::: data_n.txt;

rm -f data_n.txt;

for opt in 0 1 2 3 fast; 
    do sort -nk 2 data_$opt.txt > data_sorted_$opt.txt; 
    rm -f data_$opt.txt;
done;

