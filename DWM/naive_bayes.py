import pandas as pd
import numpy as np

df = pd.read_csv('dataset.csv')

def calculate_priors(df, target_column):
    priors = df[target_column].value_counts(normalize=True)
    return priors.to_dict() 

def calculate_likelihoods(df, feature_column, target_column):
    likelihoods = {}
    for feature_value in df[feature_column].unique():
        likelihoods[feature_value] = {}
        for target_value in df[target_column].unique():
            count = len(df[(df[feature_column] == feature_value) & (df[target_column] == target_value)])
            likelihood = (count + 1) / (len(df[df[target_column] == target_value]) + len(df[feature_column].unique()))
            likelihoods[feature_value][target_value] = likelihood
    return likelihoods

def calculate_posteriors(priors, likelihoods, new_data):
    posteriors = {}
    for target_value in priors:
        posterior = np.log(priors[target_value])
        for feature in new_data:
            posterior += np.log(likelihoods[feature][new_data[feature]][target_value])
        posteriors[target_value] = posterior
    return posteriors

def predict(posteriors):
    return max(posteriors, key=posteriors.get)

priors = calculate_priors(df, "buys electronic item")

print("Prior Probabilities:")
for class_label, prob in priors.items():
    print(f"{class_label}: {prob:.4f}")

likelihoods = {}
for feature in df.columns[:-1]:  
    likelihoods[feature] = calculate_likelihoods(df, feature, "buys electronic item")

print("\nLikelihoods:")
for feature in likelihoods:
    print(f"Feature: {feature}")
    for feature_value, targets in likelihoods[feature].items():
        print(f"  {feature_value}:")
        for target_value, likelihood in targets.items():
            print(f"    {target_value}: {likelihood:.4f}")

new_data_no = {"age": "senior", "income": "low", "gender": "female"}

posteriors_no = calculate_posteriors(priors, likelihoods, new_data_no)

print("\nPosterior Probabilities:")
for class_label, posterior in posteriors_no.items():
    print(f"{class_label}: {np.exp(posterior):.4f}")

predicted_class_no = predict(posteriors_no)
print(f"\nPredicted Class: {predicted_class_no}")