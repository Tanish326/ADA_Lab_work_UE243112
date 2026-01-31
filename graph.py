import matplotlib.pyplot as plt
import numpy as np


n = np.arange(1, 21)
practical_time = [0, 0, 0, 0, 0, 0, 0, 1197000, 0, 1159000,
                  1434000, 2050000, 5000000, 13284000, 24821000,
                  69600000, 183195000, 383965000, 1181857000, 1907456000]

scale_factor = 500
theoretical_time = [2**i*scale_factor for i in n]
plt.figure(figsize=(10, 6))
plt.plot(n, practical_time, 'o-', label='Practical Time (ns)', color='blue')
plt.plot(n, theoretical_time, 's-', label='Theoretical Time (2^n)', color='red')

plt.yscale('log')  
plt.xlabel('n')
plt.ylabel('Time')
plt.title('Practical vs Theoretical Time for Truth Table Generation')
plt.grid(True, which="both", ls="--")
plt.legend()
plt.show()
