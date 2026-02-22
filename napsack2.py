import matplotlib.pyplot as plt
import numpy as np


sizes = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000])
avg_times = np.array([330,542,1020,1054,1406,1738,1979,2036,2645,2890])  # microseconds

plt.figure(figsize=(10,6))
plt.plot(sizes, avg_times, 'o-', color='blue', label='Practical Time')
plt.title("Fractional Knapsack (Weight Sorted with Merge Sort) Time Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Average Time (microseconds)")
plt.grid(True)
plt.legend()
plt.show()