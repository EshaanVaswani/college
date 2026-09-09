import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
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

epochs = 50
t = 0
learning_rate = 0.01
epsilon = 1e-7
beta1 = 0.9
beta2 = 0.999

batch_size = 32

m_w = np.zeros((n_features,1))
v_w = np.zeros((n_features,1))
m_b = 0
v_b = 0

loss_history = []

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

for ep in range(epochs):
    indices = np.random.permutation(len(X_train))
    X_shuffled = X_train[indices]
    y_shuffled = y_train[indices]

    for i in range(0, len(X_train), batch_size):
        X_batch = X_shuffled[i: i+batch_size]
        y_batch = y_shuffled[i: i+batch_size]

        linear_output = np.dot(X_batch, weights) + bias
        y_pred = sigmoid(linear_output)

        error = y_pred - y_batch

        dw = np.dot(X_batch.T, error) / len(X_batch)
        db = np.sum(error) / len(X_batch)

        t += 1

        m_w = beta1 * m_w + (1 - beta1) * dw
        m_b = beta1 * m_b + (1 - beta1) * db
        v_w = beta2 * v_w + (1 - beta2) * (dw ** 2)
        v_b = beta2 * v_b + (1 - beta2) * (db ** 2)

        m_w_corrected = m_w / (1 - beta1 ** t)
        m_b_corrected = m_b / (1 - beta1 ** t)
        v_w_corrected = v_w / (1 - beta2 ** t)
        v_b_corrected = v_b / (1 - beta2 ** t)

        weights -= (learning_rate * m_w_corrected) / (np.sqrt(v_w_corrected) + epsilon)
        bias -= (learning_rate * m_b_corrected) / (np.sqrt(v_b_corrected) + epsilon)

    y_pred_full = sigmoid(np.dot(X_train, weights) + bias)
    loss = -np.mean(
        y_train * np.log(y_pred_full + 1e-8) +
        (1 - y_train) * np.log(1 - y_pred_full + 1e-8)
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
plt.plot(np.arange(len(loss_history)) * 100, loss_history, marker='o')
plt.title("MiniBatch GD + Adam: Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Loss")

plt.subplot(1,2,2)
plt.imshow(cm, cmap="Blues")
plt.title("MiniBatch GD + Adam: Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("True")
plt.colorbar()
plt.xticks([0,1])
plt.yticks([0,1])

plt.tight_layout()
plt.show()