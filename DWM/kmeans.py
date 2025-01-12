import matplotlib.pyplot as plt

def EuclDist(a, b):
   return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

n = int(input("Enter number of clusters: "))
i = int(input("Enter number of points: "))

points = []

for k in range(i):
   a = []
   for j in range(2):
      a.append(float(input(f"Enter coordinate {j+1} for point {k+1}: ")))
   points.append(a)

print("Points:", points)

centroids = []
for l in range(n):
   centroids.append(points[l])

print("Initial Centroids:", centroids)

clusters = []
notSame = True

while notSame:
   dist = []
   cluster = []

   for p in range(i):
      b = []
      for q in range(n):
         b.append(EuclDist(points[p], centroids[q]))
      dist.append(b)

   for r in range(i):
      cluster.append(dist[r].index(min(dist[r])))

   if cluster in clusters:
      notSame = False
   else:
      clusters.append(cluster)

   separation = [[] for _ in range(n)]
   for u in range(i):
      separation[cluster[u]].append(points[u])

   for v in range(n):
      if len(separation[v]) > 0: 
         centroid_value = [0, 0] 
         for w in range(len(separation[v])):
            centroid_value[0] += separation[v][w][0]
            centroid_value[1] += separation[v][w][1]
         centroids[v] = [centroid_value[0] / len(separation[v]), centroid_value[1] / len(separation[v])]

   print("Updated Centroids:", centroids)

print("Final Clusters:", clusters)

colors = ['r', 'g', 'b', 'y', 'c', 'm'] 
for index, cluster_points in enumerate(separation):
   cluster_color = colors[index % len(colors)]
   x_vals = [point[0] for point in cluster_points]
   y_vals = [point[1] for point in cluster_points]
   plt.scatter(x_vals, y_vals, color=cluster_color, label=f'Cluster {index + 1}')

for centroid in centroids:
   plt.scatter(centroid[0], centroid[1], color='k', marker='x', s=100, linewidths=3)

plt.title('K-means Clustering')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.legend()
plt.show()