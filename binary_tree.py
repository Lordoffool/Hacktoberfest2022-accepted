class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def Build_BT(arr):
    if len(arr) == 0 or arr[0] == 'N':
        return None
    
    root = Node(int(arr[0]))
    q = [root]
    ptr = 1
    
    while q and ptr < len(arr):
        node = q.pop(0)
        
        if ptr < len(arr) and arr[ptr] != 'N':
            node.left = Node(int(arr[ptr]))
            q.append(node.left)
        ptr += 1
        
        if ptr < len(arr) and arr[ptr] != 'N':
            node.right = Node(int(arr[ptr]))
            q.append(node.right)
        ptr += 1
    
    return root

def BFS_levelOrder(root):
    if not root:
        return []
    
    q = [root]
    result = []
    
    while q:
        node = q.pop(0)
        result.append(node.data)
        
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
    
    return result

def MaxHeight(root):
    if not root:
        return 0
    return 1 + max(MaxHeight(root.left), MaxHeight(root.right))

array = input().split()
root = Build_BT(array)
ans = BFS_levelOrder(root)
print(*ans)
print("Maximum Height = " + str(MaxHeight(root)))
