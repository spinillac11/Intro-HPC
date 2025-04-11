import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("data.txt", delimiter = " ")
N = data[:,0]
S1 = data[:,1]
S2 = data[:,2]
S3 = data[:,3]

plt.figure(figsize=(8,6))
plt.plot(N, S1, label=r'$S1$')
plt.plot(N, S2, label=r'$S2$')
plt.plot(N, S3, label=r'$S3$')
plt.xlabel('x')
plt.ylabel('Suma')
plt.title('Serie en funcipn de N')
plt.grid(True)
plt.legend()
plt.savefig("Sum.png")
