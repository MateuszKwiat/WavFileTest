import matplotlib.pyplot as plt


lines = []
with open("waveForm") as file:
    for line in file:
        line = line.strip()
        lines.append(int(line))

#lines = lines[0::10]
lines = lines[:len(lines)//50]

plt.plot(lines)
plt.show()
