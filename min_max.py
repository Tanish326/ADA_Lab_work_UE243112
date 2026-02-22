import matplotlib.pyplot as plt
import numpy as np


sizes = np.array([1000, 2000, 3000, 4000, 5000,
                  6000, 7000, 8000, 9000, 10000,
                  11000, 12000, 13000, 14000, 15000,
                  16000, 17000, 18000, 19000, 20000])


times = np.array([24.59, 39.764, 60.327, 58.969, 78.564,
                  83.347, 108.287, 88.667, 97.065, 130.447,
                  107.083, 159.037, 169.724, 159.551, 157.035,
                  165.677, 156.281, 179.104, 193.337, 205.094])


c = np.sum(sizes * times) / np.sum(sizes * sizes)
theoretical = c * sizes

# Plot
plt.plot(sizes, times, label="Practical")
plt.plot(sizes, theoretical, label="Theoretical O(n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Theoretical vs Practical Time Complexity")
plt.legend()

plt.show()