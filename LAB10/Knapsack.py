import matplotlib.pyplot as plt

n_values = [5, 55, 105, 155, 205, 255, 305, 355, 405, 455,
            505, 555, 605, 655, 705, 755, 805, 855, 905, 955]

practical_time = [127.1, 337.4, 1599.6, 3318.3, 5758.9, 8252.5,
                  11835.5, 15554.9, 18767.1, 23939.2,
                  28975.5, 36035.3, 44710.5, 49329.4, 57032.1,
                  65668.7, 78798.6, 91892.9, 97376.2, 110915]


scale_factor = 0.12

theoretical_time = []

for n in n_values:
    theoretical_time.append(scale_factor * n * n)

plt.figure(figsize=(10, 6))

plt.plot(n_values, practical_time, marker='o', label='Practical Time')
plt.plot(n_values, theoretical_time, marker='s', label='Theoretical O(n²)')

plt.xlabel("Number of Items (n)")
plt.ylabel("Execution Time (microseconds)")
plt.title("0/1 Knapsack: Theoretical vs Practical Comparison")
plt.legend()
plt.grid(True)

plt.show()