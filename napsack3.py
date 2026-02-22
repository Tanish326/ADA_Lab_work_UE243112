import matplotlib.pyplot as plt
import numpy as np


sizes = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000])
avg_times = np.array([1012,2128,3658,4221,6020,3915,3202,3489,3753,4270])  

plt.figure(figsize=(10,6))
plt.plot(sizes, avg_times, 'o-', color='green', label='Practical Time')
plt.title("Fractional Knapsack (Profit Sorted with Merge Sort) Time Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Average Time (microseconds)")
plt.grid(True)
plt.legend()
plt.show()