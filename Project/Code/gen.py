import networkx

x = networkx.gnp_random_graph(5, 1)
print(x)

networkx.draw_networkx(x)
