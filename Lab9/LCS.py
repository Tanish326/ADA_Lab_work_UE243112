import matplotlib.pyplot as plt


length = [5, 55, 105, 155, 205, 255, 305, 355, 405, 455,
          505, 555, 605, 655, 705, 755, 805, 855, 905, 955]

practical_time = [0, 0, 1516, 2015, 4835, 8216, 10013, 15081,
                  18781, 23487, 29897, 35669, 40439, 52623,
                  59603, 64893, 73113, 81509, 84838, 94203]


theoretical_time = []

for n in length:
    theoretical_time.append(n**2)


plt.figure(figsize=(10,6))

plt.plot(length, practical_time, marker='o', label="Practical Time")
plt.plot(length, theoretical_time, marker='s', label="Theoretical O(n^2)")

plt.xlabel("String Length (N)")
plt.ylabel("Time")
plt.title("LCS: Practical vs Theoretical Time Complexity")
plt.legend()
plt.grid(True)

plt.show()