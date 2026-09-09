import numpy as np
import matplotlib.pyplot as plt

X = np.array([
    [0,0],
    [0,1],
    [1,0],
    [1,1]
])

y = np.array([[0],[1],[1],[1]])

np.random.seed(0)
weights = np.random.rand(2,1)
bias = np.random.rand(1)

learning_rate = 0.1
epochs = 1000

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sig_derivative(x):
    return x * (1 - x)

for e in range(epochs):
    linear_output = np.dot(X, weights) + bias
    y_pred = sigmoid(linear_output)

    error = y - y_pred
    d_pred = error * sig_derivative(y_pred)

    weights += learning_rate * np.dot(X.T, d_pred)
    bias += learning_rate * np.sum(d_pred)

    if e % 100 == 0:
        loss = np.mean(error**2)
        print(f"Epoch {e}, Loss: {loss}")

print("Weights: ", weights)
print("Bias: ", bias)

def predict(X):
    linear_output = np.dot(X, weights) + bias
    y_pred = sigmoid(linear_output)

    return (y_pred >= 0.5).astype(int)

y_pred = predict(X)
print("Predictions: ", y_pred.flatten())

def accuracy(y_true, y_pred):
    return np.sum(y_true.flatten() == y_pred.flatten()) / len(y_true)

def confusion_matrix(y_true, y_pred):
    y_true = y_true.flatten()
    y_pred = y_pred.flatten()

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
    if y.flatten()[i] == 0:
        plt.scatter(X[i][0], X[i][1], s=50, marker='o', c='red', label="Output_0" if i==0 else "")
    else:
        plt.scatter(X[i][0], X[i][1], s=50, marker='x', c='blue' ,label="Output_1" if i==3 else "")

x_line = np.linspace(-0.5,1.5,100)
w1,w2,b = weights[0][0], weights[1][0], bias
if w2 != 0:
    y_line = -(w1 * x_line + b) / w2
    plt.plot(x_line, y_line, 'g--', label="Decision Boundary")

plt.title("OR Gate - Continuous Perceptron")
plt.legend()
plt.show()