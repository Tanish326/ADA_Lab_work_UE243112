import matplotlib.pyplot as plt

n = [100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000]
practical = [192,200,164,124,118,74,74,86,74,104,139,75,99,95,74,106]


theoretical = [x * max(practical)/max(n) for x in n]

plt.plot(n, practical, 'o-', label="Practical (ns)")
plt.plot(n, theoretical, 'o-', label="Theoretical O(n) scaled")
plt.xlabel("Array Size n")
plt.ylabel("Time (ns)")
plt.title("Find Missing Bit0 Index: Practical vs Theoretical")

plt.grid(True)
plt.legend()
plt.show()
