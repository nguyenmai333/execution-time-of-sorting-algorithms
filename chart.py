import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('Runtime.csv')
col_name = []
step = 5
size_capability = df["Input Size"][0:step]
Title = ["Randomized", "Sorted", "Reversed"]

for name in df.columns:
    if name != 'Input State' and name != 'Input Size':
        col_name.append(name)

for i in range(0, 3):
    fig = plt.figure(figsize=(30, 15))  # Tăng kích thước đồ thị
    plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)  # Điều chỉnh khoảng cách
    for name in col_name:
        plt.plot(size_capability, df[name][i*step:i*step+step], 'o-', label=name)
    plt.title(Title[i] + " Input")
    plt.xlabel('Input size')
    plt.ylabel('Run time in seconds')
    plt.legend(loc='best')
    plt.savefig('chart\\Chart_' + Title[i] + '.png')
    plt.close()
