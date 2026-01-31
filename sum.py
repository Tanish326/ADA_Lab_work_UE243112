import matplotlib.pyplot as plt

n = [100,200,300,400,500,600,700,800,900,1000]
practical = [1842,3686,4663,6502,4853,6147,12001,9176,13037,9019]
theoretical = [5050,20100,45150,80200,125250,180300,245350,320400,405450,500500]

scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]

plt.plot(n, practical, 'o-', label="Practical")
plt.plot(n, theoretical_scaled, 'o-', label="Theoretical (scaled)")
plt.xlabel("n")
plt.ylabel("Time (ns)")
plt.title("Recursive Sum: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
