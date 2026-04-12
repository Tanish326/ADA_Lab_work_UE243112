import matplotlib.pyplot as plt
import numpy as np


n = np.array([5,55,105,155,205,255,305,355,405,455,505,555,605,655,705,755,805,855,905])
time_exp = np.array([
    0,598,4392,14765,30845,61535,101437,153128,220355,
    310581,426795,562378,728975,924658,1156134,
    1418727,1726991,2081456,2444742
])


c = 598 / (55**3)

time_theo = c * (n**3)


plt.figure()

plt.plot(n, time_exp, marker='o', label="Experimental Time")
plt.plot(n, time_theo, linestyle='--', label="Theoretical O(n^3)")


plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Matrix Chain Multiplication: Experimental vs Theoretical")

plt.legend()
plt.grid()

plt.show()