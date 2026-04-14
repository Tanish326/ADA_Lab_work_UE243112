import matplotlib.pyplot as plt
import numpy as np

sizes = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000])
practical_times = np.array([931,1948,2415,3980,5046,5392,5607,6875,6163,6532])  


n_log_n = sizes * np.log2(sizes)
scale_factor_qh = practical_times[0] / n_log_n[0]
theoretical_qh = n_log_n * scale_factor_qh

n3 = sizes**3
scale_factor_ch = practical_times[0] / n3[0]
theoretical_ch = n3 * scale_factor_ch



plt.figure(figsize=(12,5))


plt.subplot(1,2,1)
plt.plot(sizes, practical_times, 'o-', color='purple', label='Practical')
plt.plot(sizes, theoretical_qh, 's--', color='orange', label='O(n log n)')
plt.title("QuickHull Performance")
plt.xlabel("Number of Points")
plt.ylabel("Time (microseconds)")
plt.grid(True)
plt.legend()


plt.subplot(1,2,2)
plt.plot(sizes, theoretical_ch, 'd--', color='red', label='O(n^3)')
plt.title("Brute Force Convex Hull")
plt.xlabel("Number of Points")
plt.ylabel("Time (microseconds)")
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()