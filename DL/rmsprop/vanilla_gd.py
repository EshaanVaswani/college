import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix, classification_report

data = load_breast_cancer()
X,y = data.data, data.target.reshape(-1,1)

X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=42)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

n_features = X_train.shape[1]
np.random.seed(0)
weights = np.random.randn(n_features,1)
bias = 0

epochs = 1000
learning_rate = 0.01
beta = 0.9

epsilon = 1e-7

S_w = np.zeros((n_features,1))
S_b = 0

loss_history = []

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

for ep in range(epochs):
    linear_output = np.dot(X_train, weights) + bias
    y_pred = sigmoid(linear_output)

    error = y_pred - y_train

    dw = np.dot(X_train.T, error) / len(X_train)
    db = np.sum(error) / len(X_train)

    S_w += beta * S_w + (1 - beta) * (dw ** 2)
    S_b += beta * S_b + (1 - beta) * (db ** 2)

    weights -= (learning_rate / (np.sqrt(S_w) + epsilon)) * dw
    bias -= (learning_rate / (np.sqrt(S_b) + epsilon)) * db

    if ep % 100 == 0:
        loss = -np.mean(
            y_train * np.log(y_pred + 1e-8) +
            (1 - y_train) * np.log(1 - y_pred + 1e-8)
        )

        loss_history.append(loss)
        print(f"Epoch {ep}: Loss = {loss}")

y_test_pred = sigmoid(np.dot(X_test, weights) + bias)
y_test_pred = (y_test_pred >= 0.5).astype(int)

acc = accuracy_score(y_test, y_test_pred)
precision = precision_score(y_test, y_test_pred)
recall = recall_score(y_test, y_test_pred)
f1 = f1_score(y_test, y_test_pred)
cm = confusion_matrix(y_test, y_test_pred)
report = classification_report(y_test, y_test_pred)

print("Accuracy: ", acc)
print("Precision: ", precision)
print("Recall: ", recall)
print("F1-Score: ", f1)
print("Confusion Matrix: \n", cm)
print("\nClassification Report: \n", report)

plt.figure(figsize=(12,4))

plt.subplot(1,2,1)
plt.plot(np.arange(len(loss_history)) * 200, loss_history, marker='o')
plt.title("Vanilla GD + RMSProp: Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Loss")

plt.subplot(1,2,2)
plt.imshow(cm, cmap="Blues")
plt.title("Vanilla GD + RMSProp: Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("True")
plt.colorbar()
plt.xticks([0,1])
plt.yticks([0,1])

plt.tight_layout()
plt.show()