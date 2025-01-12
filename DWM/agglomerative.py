import math
import numpy as np
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage

def distance(p1, p2):
   """Calculate the Euclidean distance between two points."""
   return math.sqrt(((p1[0] - p2[0]) ** 2) + ((p1[1] - p2[1]) ** 2))

def cal(points):
   """Calculate the distance matrix for the given points."""
   n = len(points)
   distanceMatrix = np.zeros((n, n))

   for i in range(n):
      for j in range(i + 1, n):
         dist = distance(points[i], points[j])
         distanceMatrix[i][j] = dist 
         distanceMatrix[j][i] = dist 

   return distanceMatrix.tolist() 

def minimum(Matrix):

   """Find the minimum distance in the distance matrix."""
   n = len(Matrix)
   least = float('inf')
   coordinates = (-1, -1)
   for i in range(n):
      for j in range(i + 1, n):
         if Matrix[i][j] < least and Matrix[i][j] != 0: 
            least = Matrix[i][j]
            coordinates = (i, j)
   return least, coordinates

def draw(matrix):
   """Print the distance matrix."""
   for rows in matrix:
      print(rows)

def agglomerative(Matrix):
   """Perform agglomerative clustering."""
   clusters = [[i] for i in range(len(Matrix))] 
   while len(Matrix) > 1:  
      draw(Matrix)
      
      least, (c1, c2) = minimum(Matrix)
      print(f"\nMinimum distance is {least} between clusters {c1} and {c2}")
      
      clusters[c1] += clusters[c2]
      clusters.pop(c2)
      print(f"New Clusters are {clusters}")

      for i in range(len(Matrix)):
         if i != c1 and i != c2:
            new_distance = min(Matrix[i][c1], Matrix[i][c2])
            Matrix[i][c1] = new_distance
            Matrix[c1][i] = new_distance
      
      Matrix.pop(c2) 
      for row in Matrix:
         row.pop(c2)

   return clusters 

def plot_dendrogram(points):
   """Plot the dendrogram for the clustering."""
   Z = linkage(points, 'single') 
   linkage
   plt.figure(figsize=(10, 6))
   dendrogram(Z, labels=[str(point) for point in points])
   plt.title("Agglomerative Clustering Dendrogram")
   plt.xlabel("Data Points")
   plt.ylabel("Distance")
   plt.show()

def get_points():
   """Get points from user input."""
   points = []
   n = int(input("Enter the number of data points: "))
   print("Enter the points in the format 'x,y' (e.g., 2,3):")
   for _ in range(n):
      point = input("Point: ")
      x, y = map(float, point.split(',')) 
      
      points.append((x, y)) 
   return points


points = get_points()

distanceMatrix = cal(points)

clusters = agglomerative(distanceMatrix)

print("Final Clusters:")
print(clusters)

plot_dendrogram(points)