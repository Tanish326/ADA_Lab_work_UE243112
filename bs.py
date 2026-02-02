import matplotlib.pyplot as plt
import numpy as np

n = np.array([10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,
              110000,120000,130000,140000,150000,160000,170000,180000,190000,
              200000,210000,220000,230000,240000,250000])


case1 = np.array([225.767,178.086,197.438,200.782,203.197,210.16,213.913,203.8,197.439,
                  232.238,235.716,213.403,238.755,211.167,223.369,213.441,221.041,269.632,
                  224.646,221.148,230.843,199.889,230.045,221.415,265.662])  # Best
case2 = np.array([255.714,226.111,232.255,219.746,195.823,193.352,200.355,221.53,222.123,
                  259.723,213.053,229.232,196.938,208.693,235.378,185.691,200.861,208.563,
                  227.469,234.886,215.787,197.756,208.535,216.814,289.27])  # Worst absent
case3 = np.array([223.986,207.455,215.42,210.369,221.457,233.737,216.585,210.091,222.504,
                  224.261,211.896,228.747,213.971,197.866,237.708,204.928,218.951,199.341,
                  225.168,211.53,230.711,204.606,172.189,210.135,250.155])  # Worst last
case4 = np.array([345.203,286.63,270.012,266.373,295.443,318.487,322.352,326.935,313.034,
                  308.653,316.271,285.386,281.18,257.772,269.754,284.984,291.081,341.321,
                  305.44,252.308,282.372,302.055,314.241,304.926,412.325])  # Average

cases = [case1, case2, case3, case4]
titles = ["Best Case", "Worst Case (Absent)", "Worst Case (Last)", "Average Case"]


fig, axes = plt.subplots(2, 2, figsize=(16,10))
axes = axes.flatten()

for ax, practical, title in zip(axes, cases, titles):
    
    if title == "Best Case":
        theoretical = np.full_like(n, np.min(practical))  # constant best case
    else:
        c = np.max(practical) / np.max(np.log2(n))       # scale factor
        theoretical = np.log2(n) * c

    ax.plot(n, practical, 'o-', label='Practical', color='blue')
    ax.plot(n, theoretical, 's--', label='Theoretical', color='red')
    ax.set_title(title)
    ax.set_xlabel('Input Size (n)')
    ax.set_ylabel('Time (ms)')
    ax.grid(True)
    ax.legend()

plt.tight_layout()
plt.show()
