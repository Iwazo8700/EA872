import matplotlib.pyplot as plt
import pandas as pd


df = pd.read_csv('data.csv', names=['x', 't'])
print(df)
plt.stem(df['x'])
plt.show()
