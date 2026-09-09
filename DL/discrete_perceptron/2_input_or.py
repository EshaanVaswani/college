import numpy as np
import matplotlib.pyplot as plt

X = np.array([
    [0,0],
    [0,1],
    [1,0],
    [1,1],
])

y = np.array([0,1,1,1])

weights = np.zeros(2)
bias = 0
learning_rate = 0.1
epochs = 10

def step(x):
    return 1 if x>=0 else 0

for e in range(epochs):
    print(f"\nEpoch {e+1}: ")
    for i in range(len(X)):
        linear_output = np.dot(X[i], weights) + bias
        y_pred = step(linear_output)

        error = y[i] - y_pred
        weights += learning_rate * error * X[i]
        bias += learning_rate * error

        print(f"Input: {X[i]}; Target: {y[i]}; Pred: {y_pred}; Error: {error}")

print("Weights: ", weights)
print("Bias: ", bias)

def predict(X):
    predictions = []
    for x in X:
        linear_output = np.dot(x, weights) + bias
        predictions.append(step(linear_output))

    return np.array(predictions)

y_pred = predict(X)
print("Predictions: ", y_pred)

def accuracy(y_true, y_pred):
    return np.sum(y_true == y_pred)/len(y_true)

def confusion_matrix(y_true, y_pred):
    tp = np.sum(((y_true == 1) & (y_pred == 1)))
    tn = np.sum(((y_true == 0) & (y_pred == 0)))
    fp = np.sum(((y_true == 0) & (y_pred == 1)))
    fn = np.sum(((y_true == 1) & (y_pred == 0)))

    return tp, tn, fp, fn

acc = accuracy(y, y_pred)
tp, tn, fp, fn = confusion_matrix(y, y_pred)

print("Accuracy = ", acc)
print(f"Confusion Matrix: TP={tp},TN={tn},FP={fp},FN={fn}")

for i in range(len(X)):
    if y[i] == 0:
        plt.scatter(X[i][0], X[i][1], marker='o', c='red', s=50, label="Output_0" if i==0 else "")
    else:
        plt.scatter(X[i][0], X[i][1], marker='x', c='blue', s=50, label="Output_1" if i==1 else "")

x_line = np.linspace(-0.5, 1.5, 100)
if weights[1] != 0:
    y_line = -(weights[0] * x_line + bias) / weights[1]
    plt.plot(x_line, y_line, 'g--', label="Decision Boundary")

plt.title("OR Gate - Discrete Perceptron")
plt.legend()
plt.show()