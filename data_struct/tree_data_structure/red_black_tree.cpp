/*A red-black tree is a binary search tree with one extra attribute for each node: 
the colour, which is either red or black.

A red-black tree is a binary search tree which has the following red-black properties:
	-->Every node is either red or black.
	-->Every leaf (NULL) is black.
	-->If a node is red, then both its children are black.
	-->Every simple path from a node to a descendant leaf contains the same number of black nodes.