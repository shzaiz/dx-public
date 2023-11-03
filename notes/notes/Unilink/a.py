import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('305kmh.csv')

# Initialize the 'speed' column with zeros
data['speed'] = 0

data['gFy'] *= 10
data['gFy'] *= 3.6
data['gFy'] -= data['gFy'].median()


# Calculate speed using numerical integration
for i in range(1, len(data)):
    dt = data['time'].iloc[i] - data['time'].iloc[i - 1]
    data.at[i, 'speed'] = data['speed'].iloc[i - 1] + data['gFy'].iloc[i] * dt

# Plot the speed vs. time
plt.figure(figsize=(10, 6))
plt.plot(data['time'], data['speed'], label='Speed')
plt.xlabel('Time')
plt.ylabel('Speed')
plt.legend()
plt.title('Speed vs. Time')
plt.grid(True)
plt.show()
