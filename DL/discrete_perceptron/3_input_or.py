import numpy as np

X = np.array([
    [0,0,0],
    [0,0,1],
    [0,1,0],
    [0,1,1],
    [1,0,0],
    [1,0,1],
    [1,1,0],
    [1,1,1],
])

y = np.array([0,1,1,1,1,1,1,1])

weights = np.zeros(3)
bias = 0
learning_rate = 0.1
epochs = 15

def step(x):
    return 1 if x>=0 else 0

for ep in range(epochs):
    print("\nEpoch ", ep+1)
    for i in range(len(X)):
        linear_output = np.dot(X[i],weights) + bias

        y_pred = step(linear_output)

        error = y[i] - y_pred

        weights += learning_rate * error * X[i]
        bias += learning_rate * error

        print(f"Input: {X[i]}, Target: {y[i]}, Pred: {y_pred}, Error: {error}")

print("Weights: ", weights)
print("Bias: ", bias)

def predict(X):
    preditions = []

    for i in X:
        linear_output = np.dot(i, weights) + bias

        preditions.append(step(linear_output))

    return np.array(preditions)

y_pred = predict(X)
print("Predictions: ", y_pred)

def accuracy(y_true, y_pred):
    return np.sum(y_true == y_pred) / len(y_true)

def confusion_matrix(y_true, y_pred):
    tp = np.sum(((y_true == 1) & (y_pred == 1)))
    tn = np.sum(((y_true == 0) & (y_pred == 0)))
    fp = np.sum(((y_true == 0) & (y_pred == 1)))
    fn = np.sum(((y_true == 1) & (y_pred == 0)))

    return tp,tn,fp,fn

acc = accuracy(y, y_pred)
tp, tn, fp, fn = confusion_matrix(y, y_pred)

print("Accuracy = ", acc)
print("Confusion Matrix: ")
print(f"TP = {tp}; TN = {tn}; FP = {fp}; FN = {fn}")

import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

for i in range(len(X)):
    color = 'red' if y[i] == 0 else 'blue'
    marker = 'o' if y[i] == 0 else 'x'
    label = ('Output_0' if y[i] == 0 else 'Output_1') if i in [0,1] else ""

    ax.scatter(X[i][0], X[i][1], X[i][2], c=color, marker=marker, label=label, s=50)

ax.set_title("3 INPUT OR Gate - Discrete Perceptron")
ax.legend()
plt.show()