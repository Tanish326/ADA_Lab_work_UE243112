import math
import matplotlib.pyplot as plt

n = [100000,200000,300000,400000,500000,600000,700000,
     800000,900000,1000000,2000000,3000000,4000000]

practical = [23.8,46,70.7,94.6,122.5,142.1,168.7,
             188.7,216.7,246,491.6,742.4,1002.9]

theoretical = [x * math.log2(x) for x in n]


scale = practical[-1] / theoretical[-1]
theoretical = [x * scale for x in theoretical]

plt.plot(n, practical, label="Practical (ms)")
plt.plot(n, theoretical, label="Theoretical n log n (scaled)")
plt.xlabel("Input size (n)")
plt.ylabel("Time (ms)")
plt.title("Merge Sort Practical vs Theoretical")
plt.legend()
plt.show()
