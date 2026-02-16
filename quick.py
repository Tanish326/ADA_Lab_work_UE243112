import math
import matplotlib.pyplot as plt


N = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]


avg_practical = [0.2,0.2,0.4,0.8,0.6,1.0,0.8,2.2,1.6,1.4]
worst_practical = [4.8,8,17.6,35.8,51.2,60.2,84,131.8,132.4,160.4]


avg_theoretical = [n * math.log2(n) / 10000 for n in N]
worst_theoretical = [(n*n) / 500000 for n in N]
plt.plot(N, avg_practical, marker='o', label="Average Practical")
plt.plot(N, avg_theoretical, linestyle='--', label="Average Theoretical (n log n)")

plt.plot(N, worst_practical, marker='o', label="Worst Practical")
plt.plot(N, worst_theoretical, linestyle='--', label="Worst Theoretical (n^2)")


plt.xlabel("Input Size (N)")
plt.ylabel("Time (ms)")
plt.title("Quick Sort: Practical vs Theoretical")
plt.legend()
plt.grid(True)

plt.show()