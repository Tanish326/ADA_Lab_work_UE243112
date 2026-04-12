import matplotlib.pyplot as plt
sizes = [100,200,300,400,500,600,700,800,900,1000]
times = [0,104,0,105,399,470,114,205,501,565]

filtered_sizes = []
filtered_times = []

for i in range(len(times)):
    if times[i] > 0:
        filtered_sizes.append(sizes[i])
        filtered_times.append(times[i])


scale = max(filtered_times) / max(filtered_sizes)
theoretical = [x * scale for x in filtered_sizes]


plt.figure()

plt.plot(filtered_sizes, filtered_times, marker='o', linewidth=2, label="Experimental")
plt.plot(filtered_sizes, theoretical, linestyle='--', linewidth=2, label="Theoretical O(n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Experimental vs Theoretical Time Complexity (Multistage Graph)")

plt.legend()
plt.grid()

plt.show()