import matplotlib.pyplot as plt
import numpy as np

# Archivos y etiquetas correspondientes
archivos = ['data_sorted_0.txt', 'data_sorted_1.txt', 'data_sorted_2.txt', 'data_sorted_3.txt', 'data_sorted_fast.txt']
labels = ['O0', 'O1', 'O2', 'O3', 'Ofast']
colors = ['C0', 'C1', 'C2', 'C3', 'C4']

plt.style.use('seaborn-v0_8-darkgrid')  

fig, ax = plt.subplots(figsize=(10, 6))

for archivo, label, color in zip(archivos, labels, colors):
    # Cargar datos
    data = np.loadtxt(archivo, delimiter='\t')
    n = data[:, 0]
    t_rec = data[:, 2]
    t_fast = data[:, 3]

    # Graficar ambas implementaciones
    ax.plot(n, t_rec, linestyle='--', marker='o', label=f'Recursivo ({label})', color=color)
    ax.plot(n, t_fast, linestyle='-', marker='s', label=f'Rápido ({label})', color=color, alpha=0.7)

# Ejes y leyenda
ax.set_xlabel('n (tamaño del problema)', fontsize=12)
ax.set_ylabel('Tiempo de ejecución (s)', fontsize=12)
ax.set_title('Comparación de tiempos de ejecución - Fibonacci', fontsize=14)
ax.legend(fontsize=9)
ax.grid(True)
ax.set_yscale('log')
plt.tight_layout()

# Guardar como PDF
plt.savefig('fibonacci_tiempos.pdf')
plt.close()