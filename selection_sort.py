import matplotlib.pyplot as plt

n = [100,200,300,400,500,600,700,800,900,1000,
     1100,1200,1300,1400,1500,1600,1700,1800,1900,2000]

practical = [0,100900,201900,434300,611800,731500,1062700,1369000,1674400,2159000,
             2650800,2959500,3919600,5385400,6296500,7124400,6441100,5869000,7490200,7542800]

theoretical = [x**2 for x in n]

scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]

plt.plot(n, practical, 'o-', label="Practical")
plt.plot(n, theoretical_scaled, 'o-', label="Theoretical (scaled)")
plt.xlabel("Array Size n")
plt.ylabel("Time (ns)")
plt.title("Selection Sort: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
