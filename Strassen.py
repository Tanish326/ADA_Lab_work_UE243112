import matplotlib.pyplot as plt
import numpy as np

n = np.array([16, 32, 64, 128])
time = np.array([1173, 2878, 16825, 77190])


n_power = n ** 2.81


scale = time[-1] / n_power[-1]
theoretical = n_power * scale


plt.figure()

plt.plot(n, time, marker='o', label='Strassen Experimental')
plt.plot(n, theoretical, linestyle='--', label='O(n^2.81) (scaled)')

plt.xlabel('Matrix Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Strassen Algorithm: Experimental vs Theoretical')
plt.legend()
plt.grid()

plt.show()