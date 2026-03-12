import matplotlib.pyplot as plt


n_values = list(range(5, 105, 5))  
practical_time = [
    101.9,101.2,100.9,425.9,508.6,849.5,1109.3,1495.7,1974.9,2007.6,
    1919.1,2275.1,2521.6,2988.6,5670.9,5962.1,6338.7,8715.8,7244.3,6472.4
]
theoretical_time = [n**2 for n in n_values]  


plt.figure(figsize=(10,6))
plt.plot(n_values, practical_time, marker='o', linestyle='-', color='blue', label='Practical Time (μs)')
plt.plot(n_values, theoretical_time, marker='s', linestyle='--', color='red', label='Theoretical Time (n^2)')

plt.title("Prim's Algorithm: Practical vs Theoretical Time")
plt.xlabel("Number of Nodes (n)")
plt.ylabel("Time (μs / n^2 units)")
plt.legend()
plt.grid(True)
plt.show()