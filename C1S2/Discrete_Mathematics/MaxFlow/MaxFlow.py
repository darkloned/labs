from sys import stdin

import networkx as nx

try:
    import matplotlib.pyplot as plt
except:
    raise

# suppress (matplotlib) warnings #

import warnings
warnings.filterwarnings("ignore")

################################

G = nx.DiGraph()

source = input("Enter source: ")
sink = input("Enter sink: ")

print("Enter list of edges with their flow capacity:")

for edge in stdin:
    edgeParams = edge.split(' ')
    G.add_edge(edgeParams[0], edgeParams[1], capacity=int(edgeParams[2]))

flowDict = nx.maximum_flow(G, source, sink)

plt.text(-0.2, -0.2, "Flow = " + str(flowDict[0]), fontsize=12, color="red")

for key, value in flowDict[1].items():
    for _key, _value in value.items():
        capacity = G.get_edge_data(key, _key).get("capacity")
        color = "red" if _value == capacity else "black"
        newEdgeLabel = str(_value) + '/' + str(capacity)
        G.add_edge(key, _key, color=color, capacity=newEdgeLabel)

pos = nx.spectral_layout(G)
colors = [G[u][v]['color'] for u, v in G.edges()]

nx.draw(G, pos, edge_color=colors, with_labels=True)
nx.draw_networkx_edge_labels(G, pos, edge_labels=nx.get_edge_attributes(G, "capacity"))

plt.show()
