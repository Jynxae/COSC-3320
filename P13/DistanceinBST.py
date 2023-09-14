class node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return node(val)
    if val < root.val: #all values less than root go to the left side while all greater values go towards the right side
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root


def lookForPath(root, finish):
    if root is None:
        return []
    if finish < root.val: #almost just like inserting, go left if < root and right if > than root
        return [root.val] + lookForPath(root.left, finish)
    elif finish > root.val:
        return [root.val] + lookForPath(root.right, finish)
    else:
        return [root.val]
    

def lowestCommonAncestor(root, node1, node2):
    if root is None:
        return None
    if root.val > node1 and root.val > node2:
        return lowestCommonAncestor(root.left, node1, node2)
    elif root.val < node1 and root.val < node2:
        return lowestCommonAncestor(root.right, node1, node2)
    else:
        return root

def shortestPath(root, node1, node2):
    ancestor = lowestCommonAncestor(root, node1, node2) #finds a common ancestor they have
    distance = len(lookForPath(ancestor,node1)) + len(lookForPath(ancestor,node2)) - 2 #Starting from the ancestor to the left node,we get the length of the path. we od the same thing with the ancestor and the right node
    return distance

values = list(map(int, input().split()))
root = None
for val in values:
    root = insert(root, val)

node1, node2 = map(int, input().split())

print(shortestPath(root, node1, node2))