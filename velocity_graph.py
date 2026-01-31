import matplotlib.pyplot as plt

velocity = [100,200,300,400,500,600,700,800,900,1000,
            1500,2000,2500,3000,4000,5000,6000,7000]

practical = [103,146,124,120,174,121,142,87,200,130,
             160,174,137,170,120,131,155,141]

theoretical = [8.32182,9.57437,10.3071,10.8269,11.2302,11.5596,11.8382,12.0795,12.2923,12.4827,
               13.2154,13.7353,14.1385,14.468,14.9878,15.3911,15.7205,15.9991]


scale = sum(practical)/sum(theoretical)
theoretical_scaled = [x*scale for x in theoretical]

plt.plot(velocity, practical, 'o-', label="Practical")
plt.plot(velocity, theoretical_scaled, 'o-', label="Theoretical (scaled)")

plt.xlabel("Initial Velocity")
plt.ylabel("Time / Bounces")
plt.title("Bouncing Ball: Practical vs Theoretical")
plt.legend()
plt.grid(True)
plt.show()
