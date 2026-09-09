import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.preprocessing import MinMaxScaler
from sklearn.metrics import mean_squared_error, mean_absolute_error, mean_absolute_percentage_error

from tensorflow.keras import Input
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense
from tensorflow.keras.callbacks import EarlyStopping

# STEP 1: LOAD DATASET
df = sns.load_dataset('dowjones')
df = df.sort_values('Date').set_index('Date')

prices = df['Price'].values.reshape(-1,1)
print(f"Total data points: {len(prices)}")
print(f"Price Range: {prices.min():.2f} to {prices.max():.2f}")

# STEP 2: TRAIN / TEST SPLIT
split = int(len(prices) * 0.80)
train_prices = prices[:split]
test_prices = prices[split:]

print(f"Train size: {len(train_prices)}, Test size: {len(test_prices)}")

# STEP 3: NORMALIZE PRICES TO [0, 1]
scaler = MinMaxScaler()
train_scaled = scaler.fit_transform(train_prices)
test_scaled = scaler.transform(test_prices)

# STEP 4: CREATE SLIDING-WINDOW SEQUENCES
WINDOW = 15

def create_sequence(series_2d, window_size):
    inputs, targets = [], []
    last_start = len(series_2d) - window_size

    for start in range(last_start):
        end = start + window_size
        window_values = series_2d[start:end, 0]
        next_value = series_2d[end, 0]

        inputs.append(window_values)
        targets.append(next_value)

    return np.array(inputs), np.array(targets)

test_with_context = np.concatenate([train_scaled[-WINDOW:], test_scaled], axis=0)

X_train, y_train = create_sequence(train_scaled, WINDOW)
X_test, y_test = create_sequence(test_with_context, WINDOW)

X_train = X_train.reshape(X_train.shape[0], WINDOW, 1)
X_test = X_test.reshape(X_test.shape[0], WINDOW, 1)

print(f"X_train: {X_train.shape}  (samples, timesteps, features)")
print(f"X_test : {X_test.shape}")

# STEP 5: BUILD MODEL
model = Sequential([
    Input(shape=(WINDOW,1)),
    LSTM(100),
    Dense(16, activation='relu'),
    Dense(1)
])

model.compile(optimizer='adam', loss='mse')
model.summary()

# STEP 6: CALLBACKS (TRAINING CONTROL)
early_stop = EarlyStopping(
    monitor='val_loss',
    patience=20,
    restore_best_weights=True,
    verbose=1
)

# STEP 7: TRAIN MODEL
history = model.fit(
    X_train, y_train,
    validation_data=(X_test, y_test),
    epochs=150,
    batch_size=16,
    callbacks=[early_stop],
    verbose=1
)

# STEP 8: PREDICT + INVERSE SCALE
pred_scaled = model.predict(X_test, verbose=0)

y_pred = scaler.inverse_transform(pred_scaled).flatten()
y_true = scaler.inverse_transform(y_test.reshape(-1,1)).flatten()

# STEP 9: EVALUATE
rmse = np.sqrt(mean_squared_error(y_true, y_pred))
mae  = mean_absolute_error(y_true, y_pred)
mape = mean_absolute_percentage_error(y_true, y_pred)

print("\n========== MODEL RESULTS ==========")
print(f"  RMSE : {rmse:.2f}  (avg error in price units)")
print(f"  MAE  : {mae:.2f}  (avg absolute error)")
print(f"  MAPE : {mape:.2f}% (avg % error -- lower is better)")
print("====================================")

# STEP 10: VISUALIZE RESULTS
test_dates = df.index[split: split+len(y_true)]
plt.plot(test_dates, y_true, label="Actual", color="blue")
plt.plot(test_dates, y_pred, label="Predicted", color="red")
plt.title("Dow Jones Prediction")
plt.xlabel("Date")
plt.ylabel("Price")
plt.legend()
plt.grid(True)
plt.show()

plt.plot(history.history["loss"], label="Train")
plt.plot(history.history["val_loss"], label="Validation")
plt.title("Model Loss")
plt.xlabel("Epoch")
plt.ylabel("MSE")
plt.legend()
plt.grid(True)
plt.show()