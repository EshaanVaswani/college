from tensorflow.keras.datasets import mnist
from tensorflow.keras import layers, models
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, classification_report

# ─────────────────── STEP 1: LOAD DATASET ────────────────────
(X_train, y_train), (X_test, y_test) = mnist.load_data()

# ─────────────────── STEP 2: PREPROCESS ──────────────────────
X_train = X_train / 255.0
X_test = X_test / 255.0

X_train = X_train.reshape(-1, 28, 28, 1)
X_test = X_test.reshape(-1, 28, 28, 1)

# ─────────────────── STEP 3: BUILD CNN MODEL ─────────────────
model = models.Sequential()

model.add(layers.Conv2D(32,(3,3), activation='relu', input_shape=(28,28,1)))
model.add(layers.MaxPooling2D((2,2)))
model.add(layers.Conv2D(64, (3,3), activation='relu'))
model.add(layers.MaxPooling2D((2,2)))
model.add(layers.Flatten())
model.add(layers.Dense(64, activation='relu'))
model.add(layers.Dense(10, activation='softmax'))

# ─────────────────── STEP 4: COMPILE ─────────────────────────
model.compile(
    optimizer='adam',
    loss='sparse_categorical_crossentropy',
    metrics=['accuracy']
)

# ─────────────────── STEP 5: TRAIN ───────────────────────────
history = model.fit(
    X_train, y_train,
    epochs=5,
    batch_size=32,
    validation_split=0.1
)

# ─────────────────── STEP 6: EVALUATE ────────────────────────
test_loss, test_acc = model.evaluate(X_test, y_test)
print("Test Accuracy: ", test_acc)

# ─────────────────── STEP 7: PREDICTIONS ─────────────────────
y_pred_probs = model.predict(X_test)
y_pred = np.argmax(y_pred_probs, axis=1)

# ─────────────────── STEP 8: CONFUSION MATRIX ────────────────
cm = confusion_matrix(y_test, y_pred)
print("\nConfusion Matrix: \n", cm)

# ─────────────────── STEP 9: CLASSIFICATION REPORT ───────────
report = classification_report(y_test, y_pred)
print("\nClassification Report: \n", report)

# ─────────────────── STEP 10: EASY VISUALIZATIONS ───────────
plt.figure(figsize=(12,4))

plt.subplot(1,2,1)
plt.plot(history.history['loss'], label='Train loss')
plt.plot(history.history['val_loss'], label='Val loss')
plt.title("CNN Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Loss")
plt.legend()

plt.subplot(1,2,2)
plt.plot(history.history['accuracy'], label='Train accuracy')
plt.plot(history.history['val_accuracy'], label='Val accuracy')
plt.title("CNN Accuracy Curve")
plt.xlabel("Epoch")
plt.ylabel("Accuracy")
plt.legend()

plt.tight_layout()
plt.show()

plt.figure(figsize=(7, 6))
plt.imshow(cm, cmap='Blues')
plt.title('CNN Confusion Matrix (MNIST)')
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.colorbar()
plt.xticks(np.arange(10))
plt.yticks(np.arange(10))
plt.tight_layout()
plt.show()