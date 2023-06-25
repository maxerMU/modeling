from math import fabs

EPS = 1e-5

def get_system_times(matrix):
    print(matrix)

    pArray = list()
    pArray.append(1)
    for i in range(1, len(matrix[0])):
        pArray.append(0)
    
    step = 0.01
    t = 0
    times = [0 for _ in pArray]
    
    while (True):
        pd = [0 for _ in pArray]

        allZeros = True

        for i in range(len(matrix[0])):
            for j in range(len(matrix[0])):
                pd[i] += matrix[j][i] * pArray[j] - matrix[i][j] * pArray[i]
            
            pArray[i] += step * pd[i]

            if fabs(pd[i]) < EPS:
                if fabs(times[i]) < EPS:
                    times[i] = t
            else:
                allZeros = False
        
        if allZeros:
            break

        t += step
    
    return times, pArray