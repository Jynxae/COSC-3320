class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root
#Find the target
def find_path(root, target):
    if root is None:
        return []
    if target < root.val:
        return [root.val] + find_path(root.left, target)
    elif target > root.val:
        return [root.val] + find_path(root.right, target)
    else:
        return [root.val]
#Find lowest common ancestor
def find_lca(root, node1, node2):
    if root is None:
        return None
    if root.val > node1 and root.val > node2:
        return find_lca(root.left, node1, node2)
    elif root.val < node1 and root.val < node2:
        return find_lca(root.right, node1, node2)
    else:
        return root

def shortest_path_distance(root, node1, node2):
    lca = find_lca(root, node1, node2)
    path1 = find_path(lca, node1)
    path2 = find_path(lca, node2)
    distance = len(path1) + len(path2) - 2
    return distance

values = list(map(int, input().split()))
root = None
for val in values:
    root = insert(root, val)

node1, node2 = map(int, input().split())

distance = shortest_path_distance(root, node1, node2)
print(distance)