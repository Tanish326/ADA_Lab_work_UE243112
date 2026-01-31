import matplotlib.pyplot as plt
import math

n = [1,2,3,4,5,6,7,8,9,10]
practical = [0,0,0,0,0,136100,101000,1114900,11292800,99558500]
theoretical = [math.factorial(i) for i in n]

scale = sum(practical[5:]) / sum(theoretical[5:])
theoretical_scaled = [x * scale for x in theoretical]

plt.plot(n, practical, marker='o', label="Practical")
plt.plot(n, theoretical_scaled, marker='o', label="Theoretical (scaled)")

plt.xlabel("n")
plt.ylabel("Time (ns)")
plt.title("Permutation: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
