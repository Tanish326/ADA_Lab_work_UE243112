import matplotlib.pyplot as plt
import numpy as np


n = np.array([100,200,300,400,500,600,700,800,900,1000])
time_exp = np.array([104,306,782,1256,2007,2652,3702,4917,5881,7501])


c = 104 / (100**2)

time_theo = c * (n**2)

plt.figure()

plt.plot(n, time_exp, marker='o', label="Experimental Time (Forward)")
plt.plot(n, time_theo, linestyle='--', label="Theoretical O(n^2)")

# Labels and title
plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Multistage Graph Forward Approach: Experimental vs Theoretical")

plt.legend()
plt.grid()

plt.show()