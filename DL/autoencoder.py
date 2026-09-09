import tensorflow as tf
from tensorflow.keras.datasets import mnist
from tensorflow.keras import models, layers
from sklearn.metrics import mean_squared_error, mean_absolute_error
import numpy as np
import matplotlib.pyplot as plt

# ─────────────────── STEP 1: LOAD DATASET ────────────────────
(X_train, _), (X_test, _) = mnist.load_data()

X_train = X_train / 255.0
X_test = X_test / 255.0

X_train = X_train.reshape(-1, 784)
X_test = X_test.reshape(-1, 784)

# ─────────────────── STEP 2: BUILD MODEL ─────────────────────
input_dim = 784
encoding_dim = 32

input_layer = layers.Input(shape=(input_dim,))
encoded = layers.Dense(128, activation='relu')(input_layer)
encoded = layers.Dense(encoding_dim, activation='relu')(encoded)
decoded = layers.Dense(128, activation='relu')(encoded)
decoded = layers.Dense(input_dim, activation='sigmoid')(encoded)

autoencoder = models.Model(input_layer, decoded)

# ─────────────────── STEP 3: COMPILE ─────────────────────────
autoencoder.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)

# ─────────────────── STEP 4: TRAIN ───────────────────────────
history = autoencoder.fit(
    X_train, X_train,
    epochs=5,
    batch_size=256,
    validation_data=(X_test, X_test)
)

# ─────────────────── STEP 5: PREDICT (RECONSTRUCT) ───────────
reconstructed = autoencoder.predict(X_test)

# ─────────────────── STEP 6: METRICS ─────────────────────────
mse = mean_squared_error(X_test, reconstructed)
mae = mean_absolute_error(X_test, reconstructed)

# ── RESHAPE FOR IMAGE QUALITY METRICS ─────────────────────────
x_true = X_test.reshape(-1,28,28,1).astype(np.float32)
x_pred = reconstructed.reshape(-1,28,28,1).astype(np.float32)

# ── PSNR: PEAK SIGNAL-TO-NOISE RATIO ─────────────────────────
psnr = tf.image.psnr(x_true, x_pred, max_val=1.0)
psnr = np.mean(psnr)

# ── SSIM: STRUCTURAL SIMILARITY INDEX ────────────────────────
ssim = tf.image.ssim(x_true, x_pred, max_val=1.0)
ssim = np.mean(ssim)

print("\nMSE:", mse)
print("MAE:", mae)
print("PSNR:", psnr)
print("SSIM:", ssim)

# ─────────────────── STEP 7: EASY VISUALIZATIONS ────────────
plt.figure(figsize=(8,4))
plt.plot(history.history['loss'], label='Train Loss (MSE)')
plt.plot(history.history['val_loss'], label='Validation Loss (MSE)')
plt.title("Autoencoder Reconstruction Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("MSE Loss")
plt.legend()
plt.tight_layout()
plt.show()

n = 10
plt.figure(figsize=(14,3))
for i in range(n):
    ax = plt.subplot(2,n,i+1)
    plt.imshow(X_test[i].reshape(28,28), cmap='gray')
    plt.axis('off')
    plt.title("Original")

    ax = plt.subplot(2, n, i + 1 + n)
    plt.imshow(reconstructed[i].reshape(28, 28), cmap='gray')
    plt.axis('off')
    plt.title("Reconstructed")

plt.suptitle("Original vs Reconstructed: MNIST Digits")
plt.tight_layout()
plt.show()