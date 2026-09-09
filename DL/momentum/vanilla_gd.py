import numpy as np
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix, classification_report
import matplotlib.pyplot as plt


# ─────────────────── STEP 1: LOAD DATA ───────────────────────
data = load_breast_cancer()

X = data.data
y = data.target.reshape(-1,1)

# ─────────────────── STEP 2: TRAIN-TEST SPLIT ────────────────
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# ─────────────────── STEP 3: FEATURE SCALING ─────────────────
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# ─────────────────── STEP 4: INIT PARAMETERS ─────────────────
n_features = X_train.shape[1]
np.random.seed(0)

weights = np.random.randn(n_features, 1)
bias = 0

learning_rate = 0.01
beta = 0.9

v_w = np.zeros((n_features, 1))
v_b = 0

epochs = 1000

loss_history = []

# ─────────────────── STEP 5: ACTIVATION FUNCTION ─────────────
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# ─────────────────── STEP 6: TRAINING LOOP ───────────────────
for ep in range(epochs):
    # ── 6a. FORWARD PASS ──────────────────────────────────────
    linear_output = np.dot(X_train, weights) + bias

    y_pred = sigmoid(linear_output)

    # ── 6b. ERROR ────────────────────────────────────────────
    error = y_pred - y_train

    # ── 6c. GRADIENT ─────────────────────────────────────────
    dw = np.dot(X_train.T, error) / len(X_train)
    db = np.sum(error) / len(X_train)

    # ── 6d. MOMENTUM UPDATE (THE KEY DIFFERENCE) ──────────────
    v_w = beta * v_w + (1 - beta) * dw
    v_b = beta * v_b + (1 - beta) * db

    # ── 6e. UPDATE WEIGHTS USING VELOCITY ─────────────────────
    weights -= learning_rate * v_w
    bias -= learning_rate * v_b

    # ── 6f. LOG LOSS EVERY 100 EPOCHS ────────────────────────
    if ep % 100 == 0:
        loss = -np.mean(
            y_train * np.log(y_pred + 1e-8) +
            (1 - y_train) * np.log(1 - y_pred + 1e-8)
        )
        loss_history.append(loss)

        print(f"Epoch {ep}: Loss = {loss}")

# ─────────────────── STEP 7: PREDICTION ──────────────────────
y_test_pred = sigmoid(np.dot(X_test, weights) + bias)
y_test_pred = (y_test_pred >= 0.5).astype(int)

# ─────────────────── STEP 8: METRICS ─────────────────────────
acc = accuracy_score(y_test, y_test_pred)
precision = precision_score(y_test, y_test_pred)
recall = recall_score(y_test, y_test_pred)
f1 = f1_score(y_test, y_test_pred)
cm = confusion_matrix(y_test, y_test_pred)
report = classification_report(y_test, y_test_pred)

print("\nAccuracy:", acc)
print("Precision:", precision)
print("Recall:", recall)
print("F1 Score:", f1)
print("\nConfusion Matrix:\n", cm)
print("\nClassification Report:\n", report)

# ─────────────────── STEP 9: EASY VISUALIZATIONS ────────────
plt.figure(figsize=(12,4))

plt.subplot(1,2,1)
plt.plot(np.arange(len(loss_history)) * 200, loss_history, marker='o')
plt.title("Vanilla GD + Momentum: Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Binary-Cross-Entropy Loss")

plt.subplot(1,2,2)
plt.imshow(cm, cmap="Blues")
plt.title('Vanilla GD + Momentum: Confusion Matrix')
plt.xlabel('Predicted')
plt.ylabel('True')
plt.colorbar()
plt.xticks([0, 1])
plt.yticks([0, 1])

plt.tight_layout()
plt.show()