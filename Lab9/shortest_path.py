import matplotlib.pyplot as plt

N = [5, 55, 105, 155, 205, 255, 305, 355, 405, 455,
     505, 555, 605, 655, 705, 755, 805]

practical_time = [1069, 20482, 123712, 206330, 416915,
                  1061231, 1832211, 2278021, 3644802,
                  4967265, 7092925, 8916696, 11374587,
                  15592857, 19401959, 23384730, 28142676]


theoretical_time = []

for n in N:
    theoretical_time.append(n**3)


plt.figure(figsize=(10,6))

plt.plot(N, practical_time, marker='o', label="Practical Time")
plt.plot(N, theoretical_time, marker='s', label="Theoretical O(n^3)")

plt.xlabel("Number of Nodes (N)")
plt.ylabel("Time")
plt.title("Floyd Warshall: Practical vs Theoretical Time Complexity")
plt.legend()
plt.grid(True)

plt.show()