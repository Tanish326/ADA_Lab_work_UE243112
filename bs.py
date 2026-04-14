import matplotlib.pyplot as plt
import numpy as np

n = np.array([10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,
              110000,120000,130000,140000,150000,160000,170000,180000,190000,
              200000,210000,220000,230000,240000,250000])


best_case = np.array([225.767,178.086,197.438,200.782,203.197,210.16,213.913,203.8,197.439,
                      232.238,235.716,213.403,238.755,211.167,223.369,213.441,221.041,269.632,
                      224.646,221.148,230.843,199.889,230.045,221.415,265.662])

worst_case = np.array([255.714,226.111,232.255,219.746,195.823,193.352,200.355,221.53,222.123,
                       259.723,213.053,229.232,196.938,208.693,235.378,185.691,200.861,208.563,
                       227.469,234.886,215.787,197.756,208.535,216.814,289.27])


best_theoretical = np.ones_like(n) * 180   

c = np.max(worst_case) / np.max(np.log2(n))  
worst_theoretical = np.log2(n) * c            


plt.figure(figsize=(10,6))

plt.plot(n, best_case, 'o-', label='Best Case (Practical)', color='blue')
plt.plot(n, best_theoretical, 'b--', label='Best Case O(1)')

plt.plot(n, worst_case, 's-', label='Worst Case (Practical)', color='red')
plt.plot(n, worst_theoretical, 'r--', label='Worst Case O(log n)')

plt.title("Binary Search Time Complexity")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.legend()

plt.show()