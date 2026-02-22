import matplotlib.pyplot as plt
import numpy as np

sizes = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000])
times = np.array([315,703,1221,1582,1969,2207,2777,2851,3042,3610])  


theoretical = sizes * np.log2(sizes)
theoretical = theoretical * (times[-1]/theoretical[-1])


plt.figure(figsize=(10,6))
plt.plot(sizes, times, 'o-', label='Practical Time', color='blue')
plt.plot(sizes, theoretical, '--', label='Theoretical O(n log n)', color='red')
plt.title("Fractional Knapsack (Merge Sort) Time Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.legend()
plt.grid(True)
plt.show()