from itertools import combinations

def get_frequent_itemsets(transactions, min_support):
   """Find frequent itemsets in transactions using a simplified Apriori algorithm."""
   item_count = {}
   
   for transaction in transactions:
      for item in transaction:
         if item not in item_count:
            item_count[item] = 0
         item_count[item] += 1

   frequent_itemsets = {frozenset([item]) for item, count in item_count.items() if count >= min_support}

   k = 2
   while True:
      candidate_itemsets = {}
      frequent_items = list(frequent_itemsets)
      # Create candidate itemsets from the current frequent itemsets

      for i in range(len(frequent_items)):
         for j in range(i + 1, len(frequent_items)):
            candidate = frequent_items[i] | frequent_items[j]
            if len(candidate) == k: # Ensure candidate has the correct size
               candidate_itemsets[candidate] = 0

      for transaction in transactions:
         transaction_set = frozenset(transaction)
         for candidate in candidate_itemsets.keys():
            if candidate.issubset(transaction_set):
               candidate_itemsets[candidate] += 1
      
      frequent_candidates = {itemset for itemset, count in candidate_itemsets.items() if count >= min_support}
      
      if not frequent_candidates:
         break
      
      frequent_itemsets.update(frequent_candidates)
      k += 1
   
   return frequent_itemsets

def get_association_rules(frequent_itemsets, transactions, min_confidence):
   """Generate association rules and their confidence."""
   rules = []
   total_transactions = len(transactions)

   for itemset in frequent_itemsets:
      for i in range(1, len(itemset)):
         subsets = combinations(itemset, i)
         for subset in subsets:
            subset = frozenset(subset)
            support_count = sum(1 for transaction in transactions if itemset.issubset(transaction))
            subset_count = sum(1 for transaction in transactions if subset.issubset(transaction))

            if subset_count > 0:
               confidence = support_count / subset_count
               if confidence >= min_confidence:
                  rules.append((subset, itemset - subset, confidence))
   return rules


def main():
   transactions = [
   ['milk', 'bread', 'diaper'],
   ['bread', 'diaper', 'beer'],
   ['milk', 'bread', 'diaper', 'beer'],
   ['milk', 'diaper'],
   ['bread', 'milk', 'beer'],
   ['milk', 'diaper', 'bread'],
   ['diaper', 'beer'],
   ['milk', 'bread', 'diaper', 'beer'],
   ['bread', 'milk'],
   ['beer', 'diaper']
   ]

   min_support = 2 
   min_confidence = 0.7 
   
   frequent_itemsets = get_frequent_itemsets(transactions, min_support)
   
   print("Frequent Itemsets:")
   for itemset in frequent_itemsets:
      print(set(itemset))
   
   rules = get_association_rules(frequent_itemsets, transactions, min_confidence)
   
   print("\nAssociation Rules and Confidence:")
   for antecedent, consequent, confidence in rules:
      print(f"{set(antecedent)} -> {set(consequent)} (Confidence: {confidence:.2f})")
   
   
if __name__ == "__main__":
   main()
