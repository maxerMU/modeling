from operator import le
from builtins import print
from math import sqrt
from numpy import arange
from prettytable import PrettyTable
import matplotlib.pyplot as plt

def func(x, u):
    return x ** 2  + u ** 2


def picard_1(x):
    return x ** 3 / 3


def picard_2(x):
    return x ** 3 / 3 * (1 + x ** 4 / 21)


def picard_3(x):
    return x ** 3 / 3 * (1 + (x ** 4 / 21) + (2 / 693 * x ** 8) + (1 / 19845 * x ** 12))


def picard_4(x):
    return x ** 3 / 3 + (x ** 7 / 63) + (2 / 2079 * x ** 11) + (13 / 218295 * x ** 15) + (82 / 37328445 * x ** 19) + \
           (662 / 10438212015 * x ** 23) + (4 / 3341878155 * x ** 27) + (x ** 31 / 10987690975)


def explicit_scheme(x, y, h):
    return y + h * func(x, y)


def calculate_picard(x_values, func):
    y_values = []
    for x_cur in x_values:
        result = func(x_cur)
        if result <= 10e+300:
            y_values.append(round(result, 8))
        else:
            y_values.append(float('inf'))

    return y_values


def calculate_euler(step, x_end, func):
    y_values = []
    y_values.append(0.0)
    for x_cur in arange(step, x_end + step / 2, step):
        result = func(x_cur - step, y_values[-1], step)
        if result <= 10e+300:
            y_values.append(result)
        else:
            y_values.append(float('inf'))

    return y_values

def runge_kutte(x, y, alpha, h):
    f = func(x, y)
    tmp =  h / (2 * alpha)
    return y + h * ((1-alpha) * f + alpha * func(x + tmp, y + tmp * f))

def calculate_runge_kutte(step, x_end, alpha):
    y_values = []
    y_values.append(0.0)
    for x_cur in arange(step, x_end + step / 2, step):
        result = runge_kutte(x_cur - step, y_values[-1], alpha, step)
        if result <= 10e+300:
            y_values.append(result)
        else:
            y_values.append(float('inf'))

    return y_values

def plot_graphs(args, values_arrays, labels):
    plt.figure(0)
    for i in range(len(values_arrays)):
        plt.plot(args, values_arrays[i], label=labels[i])

    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend(loc=0)
    plt.show()

def find_step():
    x_end = 1
    euler_step = 1e-4
    runge_step = 1e-4

    while True:
        


if __name__ == "__main__":
    step = 0.00001
    x_end = 2

    x_values = []

    for i in arange(0, x_end + step / 2, step):
        x_values.append(round(i, 5))

    picard_first = calculate_picard(x_values, picard_1)
    picard_second = calculate_picard(x_values, picard_2)
    picard_third = calculate_picard(x_values, picard_3)
    picard_fourth = calculate_picard(x_values, picard_4)
    euler_exp = calculate_euler(step, x_end, explicit_scheme)
    runge_cutte_1 = calculate_runge_kutte(step, x_end, 0.5)
    runge_cutte_2 = calculate_runge_kutte(step, x_end, 1)

    table = PrettyTable()
    table.add_column('X', x_values)
    table.add_column('Пикар (1 приближение)', picard_first)
    table.add_column('Пикар (2 приближение)', picard_second)
    table.add_column('Пикар (3 приближение)', picard_third)
    table.add_column('Пикар (4 приближение)', picard_fourth)
    table.add_column('Эйлер (явная схема)', euler_exp)
    table.add_column('Рунге-Кутта (a = 0.5)', runge_cutte_1)
    table.add_column('Рунге-Кутта (a = 1)', runge_cutte_2)

    print(table)

    values_arr = [picard_first, picard_second, picard_third, picard_fourth, euler_exp, runge_cutte_1, runge_cutte_2]
    for i in range(len(values_arr)):
        neg_arr = [-y for y in values_arr[i][:0:-1]]
        values_arr[i] = neg_arr + values_arr[i]

    neg_x = [-x for x in x_values[:0:-1]]
    x_values = neg_x + x_values

    labels = ["Пикард 1", "Пикард 2", "Пикард 3", "Пикард 4", "Эйлер", "Рунге-Кутт(0.5)", "Рунге-Кутт(1)"]

    plot_graphs(x_values, values_arr, labels)