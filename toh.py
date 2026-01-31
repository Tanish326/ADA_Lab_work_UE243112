import matplotlib.pyplot as plt


discs = [5,10,15,20,25,30]


practical = [0,0,105500,2907800,90040900,2794909300]


theoretical = [31,1023,32767,1048575,33554431,1073741823]

scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]


plt.plot(discs, practical, 'o-', label="Practical")
plt.plot(discs, theoretical_scaled, 'o-', label="Theoretical (scaled)")

plt.xlabel("Number of Discs")
plt.ylabel("Time (ns) / Moves (scaled)")
plt.title("Tower of Hanoi: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
