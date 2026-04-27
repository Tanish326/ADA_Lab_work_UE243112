import matplotlib.pyplot as plt

n = [5, 6, 7, 8, 9, 10]
practical = [99.5, 367.4, 2586.3, 17449.8, 99276.1, 995002]


theoretical = []
for i in n:
    theoretical.append((i**2) * (2**i))


scale_factor = practical[0] / theoretical[0]
theoretical_scaled = [x * scale_factor for x in theoretical]


plt.figure(figsize=(8,5))

plt.plot(n, practical, marker='o', label="Practical Time")
plt.plot(n, theoretical_scaled, marker='s', linestyle='--', label="Theoretical Time (scaled)")


plt.xlabel("Number of Cities (n)")
plt.ylabel("Time (microseconds)")
plt.title("TSP DP: Theoretical vs Practical Analysis")

plt.grid(True)
plt.legend()

plt.show()