import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score, confusion_matrix, classification_report
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

data = load_breast_cancer()
X,y = data.data, data.target.reshape(-1,1)

X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=42)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

epochs = 20
learning_rate = 0.01

n_features = X_train.shape[1]

np.random.seed(0)
weights = np.random.randn(n_features, 1)
bias = 0

beta = 0.9

v_w = np.zeros((n_features,1))
v_b = 0

loss_history = []

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

for ep in range(epochs):
    indices = np.random.permutation(len(X_train))
    X_shuffled = X_train[indices]
    y_shuffled = y_train[indices]

    for i in range(len(X_train)):
        x_i = X_shuffled[i].reshape(1,-1)
        y_i = y_shuffled[i]

        w_look = weights - learning_rate * beta * v_w
        linear_output = np.dot(x_i, w_look) + bias
        y_pred = sigmoid(linear_output)

        error = y_pred - y_i

        dw = np.dot(x_i.T, error)
        db = np.sum(error)

        v_w = beta * v_w + (1 - beta) * dw
        v_b = beta * v_b + (1 - beta) * db

        weights -= learning_rate * v_w
        bias -= learning_rate * v_b

    y_pred_full = sigmoid(np.dot(X_train, weights) + bias)
    loss = -np.mean(
        y_train * np.log(y_pred_full + 1e-8) +
        (1 - y_train) * np.log(1 - y_pred_full + 1e-8)
    )

    loss_history.append(loss)

    print(f"Epoch {ep+1}: Loss = {loss}")

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
plt.plot(loss_history)
plt.title("Stochastic GD + NAG: Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Loss")

plt.subplot(1,2,2)
plt.imshow(cm, cmap="Blues")
plt.title("Stochastic GD + NAG: Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("True")
plt.colorbar()
plt.xticks([0,1])
plt.yticks([0,1])

plt.tight_layout()
plt.show()