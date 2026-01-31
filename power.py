import matplotlib.pyplot as plt
import math

n = list(range(1, 51))  


practical = [576400,846100,1276700,1210500,1330500,1396100,1597100,1618700,
             1718600,1732900,1967800,1761600,1894700,1994700,2294000,1795000,
             1994800,1994600,2293800,1938100,2363200,2258500,2716000,1994600,
             2394800,2427400,2763300,2520700,2671300,2918600,3181900,1986200,
             2381300,2291600,2603700,2349500,2587000,2646100,2947100,2223800,
             2611900,2632200,2772200,2656900,3016900,2983600,3241000,2223400,
             2503700,2676200]


theoretical = [math.log2(x) for x in n]


scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]

plt.plot(n, practical, 'o-', label="Practical")
plt.plot(n, theoretical_scaled, 'o-', label="Theoretical (scaled)")

plt.xlabel("Exponent b")
plt.ylabel("Time (ns)")
plt.title("Optimized Recursive Power: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
