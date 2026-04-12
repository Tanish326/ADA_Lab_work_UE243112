import matplotlib.pyplot as plt
import numpy as np


n = np.array([100,200,300,400,500,600,700,800,900,1000])
time_exp = np.array([0,1002,2992,3350,5143,6970,8932,13560,16034,16965])

c = 1002 / (200**2)

time_theo = c * (n**2)


plt.figure()

plt.plot(n, time_exp, marker='o', label="Experimental Time")
plt.plot(n, time_theo, linestyle='--', label="Theoretical O(n^2)")


plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Multistage Graph (Backward Approach): Experimental vs Theoretical")

plt.legend()
plt.grid()

plt.show()