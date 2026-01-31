import matplotlib.pyplot as plt
import numpy as np
N = np.array([1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000])

best = np.array([125.8,0,106,0,212.9,0,0,0,0,103.6,101.2,0,0,0,0,0])
avg  = np.array([1879.1,3433.6,6654.6,11892.4,21757.6,37250.4,35483.7,48781.1,66481.9,78902.5,86930.7,104694,131280,150759,210727,197974])
worst= np.array([3899.1,6219.5,13945.4,23690.5,49389.6,72773.1,75726.5,101713,121253,156087,178772,218182,268666,294109,421129,386517])

theo_best = N.astype(float)       
theo_quad = (N**2).astype(float)  


scale_best = best.max() / theo_best.max()
scale_quad = worst.max() / theo_quad.max()

theo_best *= scale_best
theo_quad *= scale_quad

plt.plot(N, best, marker='o', label="Practical Best")
plt.plot(N, avg, marker='o', label="Practical Average")
plt.plot(N, worst, marker='o', label="Practical Worst")

plt.plot(N, theo_best, linestyle =  '--', label="Theoretical O(n)")
plt.plot(N, theo_quad, linestyle =  '--', label="Theoretical O(n²)")

plt.xlabel("Input Size (N)")
plt.ylabel("Time (microseconds)")
plt.title("Insertion Sort: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
