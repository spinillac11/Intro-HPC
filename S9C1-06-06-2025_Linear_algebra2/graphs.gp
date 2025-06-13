set log xy
plot for [ii in "1 2 4 8 16"] 'datos_'.ii.'.txt' u 1:2:3 w yerrorlines t 'threads='.ii.''