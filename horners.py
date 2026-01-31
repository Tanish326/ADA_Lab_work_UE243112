import matplotlib.pyplot as plt


n = [10,20,30,40,50,60,70,80,90,100,
     110,120,130,140,150,160,170,180,190,200]


practical = [0,0,0,996,0,998,1002,1125,1000,1203,
             996,1003,0,1439,1152,1007,1013,2003,1002,2234]

theoretical = n

scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]


plt.plot(n, practical, 'o-', label="Practical")
plt.plot(n, theoretical_scaled, 'o-', label="Theoretical (scaled)")

plt.xlabel("Polynomial size n")
plt.ylabel("Time (ns)")
plt.title("Horner's Rule: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
