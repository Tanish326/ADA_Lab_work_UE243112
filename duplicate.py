import matplotlib.pyplot as plt

n = [100,500,1000,1500,2000,2500,3000]
practical = [19920,438820,1687320,3727320,7156820,7211200,13357180]

theoretical = [x*x for x in n]
theoretical = [t * max(practical)/max(theoretical) for t in theoretical]

plt.plot(n, practical, 'o-', label="Practical (ns)")
plt.plot(n, theoretical, 'o-', label="Theoretical O(n²) scaled")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (ns)")
plt.title("Duplicate Finder: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.yscale("log")
plt.show()
