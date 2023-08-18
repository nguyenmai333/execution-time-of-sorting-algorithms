import matplotlib.pyplot as plt
import pandas as pd
import os

df = pd.read_csv('D:\\Data_Code\\Vs\\.vscode\\python\\project_thctdl\\Runtime.csv')
col_name = []
step = 5
size_capability = df["Input Size"][0:step]
Title = ["Randomized", "Sorted", "Reversed"]


for name in df.columns:
    if name != 'Input State' and name != 'Input Size':
        col_name.append(name)

for i in range(0, 3):
    fifig = plt.figure()
    for name in col_name:
        plt.plot(size_capability, df[name][i*step:i*step+step] , 'o-', label = name)
        pass
    plt.title(Title[i] + " Input")
    plt.xlabel('Input size')
    plt.ylabel('Run time in seconds')
    plt.legend(loc = 'best')
    plt.savefig('D:\\Data_Code\\Vs\\.vscode\\python\\project_thctdl\\'+'Chart_' Title[i] + '.pdf')
    plt.figure().clear()
    plt.close()
    plt.cla()
    plt.clf()
    pass
#plt.show()