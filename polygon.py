import matplotlib.pyplot as plt
import numpy as np

sizes = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000])
practical_times = np.array([931,1948,2415,3980,5046,5392,5607,6875,6163,6532])  

n_log_n = sizes * np.log2(sizes)


scale_factor = practical_times[0] / n_log_n[0]
theoretical_times = n_log_n * scale_factor

plt.figure(figsize=(10,6))
plt.plot(sizes, practical_times, 'o-', color='purple', label='Practical Time')
plt.plot(sizes, theoretical_times, 's--', color='orange', label='Theoretical O(n log n)')
plt.title("QuickHull: Practical vs Theoretical Time")
plt.xlabel("Number of Points")
plt.ylabel("Time (microseconds)")
plt.grid(True)
plt.legend()
plt.show()