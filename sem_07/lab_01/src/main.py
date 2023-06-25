from scipy.stats import uniform, expon
from matplotlib import pyplot as plt
import numpy as np

a = -1
b = 1
x = np.linspace(a - 1, b + 1, 100)

dist = uniform(loc=a, scale=abs(a - b))

figure, ax = plt.subplots(figsize=(8, 8))
ax.grid(linewidth=0.5)
plt.title('Uniform Distribution function')
plt.plot(x, dist.cdf(x), color='r', label=f"a={a}, b={b}")
plt.legend()


figure, ax = plt.subplots(figsize=(8, 8))
ax.grid(linewidth=0.5)
plt.title('Probability density function')
plt.plot(x, dist.pdf(x), color='b', label=f"a={a}, b={b}")
plt.legend()

xstart = 0
xend = 100
x = np.linspace(xstart, xend, 1000)
l = 0.05

dist = expon(scale=1/l)

figure, ax = plt.subplots(figsize=(8, 8))
ax.grid(linewidth=0.5)
plt.title('Exponential Distribution function')
plt.plot(x, dist.cdf(x), color='r', label=f"lamda={l}")
plt.legend()

figure, ax = plt.subplots(figsize=(8, 8))
ax.grid(linewidth=0.5)
plt.title('Probability density function')
plt.plot(x, dist.pdf(x), color='b', label=f"lamda={l}")
plt.legend()

plt.show()