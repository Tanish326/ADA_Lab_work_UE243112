import matplotlib.pyplot as plt
import numpy as np


sizes = np.array([5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140])
best_case_practical = np.array([73,66,67,75,67,84,58,62,68,54,60,85,58,48,77,66,63,55,73,67,67,52,67,73,72,58,55,57])
worst_case_practical = np.array([64,87,108,181,111,108,69,81,343,409,62,306,189,444,451,507,95,670,82,75,554,78,863,691,491,466,1000,81])


best_case_theoretical = np.ones_like(sizes)

worst_case_theoretical = sizes

best_case_theoretical_scaled = best_case_theoretical * np.mean(best_case_practical)
worst_case_theoretical_scaled = worst_case_theoretical * (np.mean(worst_case_practical)/np.mean(sizes))
plt.figure(figsize=(12,5))
plt.subplot(1,2,1)
plt.plot(sizes, best_case_practical, 'bo-', label='Practical Best Case')
plt.plot(sizes, best_case_theoretical_scaled, 'r--', label='Theoretical Best Case (O(1))')
plt.xlabel('Array Size (n)')
plt.ylabel('Time (ns)')
plt.title('Linear Search Best Case: Practical vs Theoretical')
plt.legend()
plt.grid(True)

plt.subplot(1,2,2)
plt.plot(sizes, worst_case_practical, 'go-', label='Practical Worst Case')
plt.plot(sizes, worst_case_theoretical_scaled, 'r--', label='Theoretical Worst Case (O(n))')
plt.xlabel('Array Size (n)')
plt.ylabel('Time (ns)')
plt.title('Linear Search Worst Case: Practical vs Theoretical')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
