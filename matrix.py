import matplotlib.pyplot as plt
import numpy as np


n = np.array([16, 32, 64, 128])
time = np.array([7367, 60459, 272546, 2122919])


n_cubed = n ** 3


scale = time[-1] / n_cubed[-1]
theoretical = n_cubed * scale

plt.figure()

plt.plot(n, time, marker='o', label='Experimental Time')
plt.plot(n, theoretical, linestyle='--', label='O(n^3) (scaled)')

plt.xlabel('Matrix Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Matrix Multiplication: Experimental vs Theoretical')
plt.legend()
plt.grid()

plt.show()