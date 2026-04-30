import matplotlib.pyplot as plt
import numpy as np
import math

n = np.array([5, 6, 7, 8, 9, 10, 11, 12, 13])
time_ms = np.array([0, 0, 0, 1, 5, 30, 141, 574, 2862])


theory = np.array([math.factorial(i) for i in n])
theory_scaled = theory / max(theory) * max(time_ms)


plt.figure(figsize=(10,6))

plt.plot(n, time_ms, marker='o', label='Practical Time (ms)')
plt.plot(n, theory_scaled, marker='s', linestyle='--', label='Theoretical O(n!) (scaled)')

plt.title("N-Queens: Theoretical vs Practical Time Complexity (Horowitz & Sahni)")
plt.xlabel("N (Board Size)")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.legend()

plt.show()