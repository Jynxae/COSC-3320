import sys

def buildTree(preorder,inorder):
    if not preorder:
        return []
    root_val = preorder[0] #To get the root val
    root_idx = inorder.index(root_val) #To get the index of the root val from in order

    left_subtree = buildTree(preorder[1:1+root_idx], inorder[:root_idx])

    right_subtree = buildTree(preorder[1+root_idx:], inorder[root_idx+1:])

    return left_subtree + right_subtree + [root_val]


  
# Open the input file
for line in sys.stdin:
    n = int(line)  # Read the number of nodes
    preorder = list(map(int, sys.stdin.readline().split()))  # Read the pre-order traversal
    inorder = list(map(int, sys.stdin.readline().split()))   # Read the in-order traversal

    postorder = buildTree(preorder, inorder)

    # Print the post-order traversal result for this test case
    print(" ".join(map(str, postorder)))
