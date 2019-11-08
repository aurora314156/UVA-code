# ac on zerojudge but ac on uva(?)
import os, queue

EndMark = "()"

class Node(object):
    def __init__(self, left = None, right = None, data = None):
        self.Left = left
        self.Right = right
        self.Data = data

def newNode():
    return Node()

def addNode(root, data, path):
    tree = root
    for p in path:
        if p == "L":
                if tree.Left is None:
                    tree.Left = newNode()
                tree = tree.Left
        elif p == "R":
                if tree.Right is None:
                    tree.Right = newNode()
                tree = tree.Right
    # final travesel position
    tree.Data = data

def BFS(root):
    ans = ""
    q = queue.Queue()
    q.put(root)
    while q.empty() is False:
        currentNode = q.get()
        if currentNode.Left is not None:
            if currentNode.Left.Data is None:
                return False
            q.put(currentNode.Left)

        if currentNode.Right is not None:
            if currentNode.Right.Data is None:
                return False
            q.put(currentNode.Right)
        
        ans += currentNode.Data + " "

    return ans.strip()

def readInput():
    SInput = ""
    while True:
        for Input in input().strip().split(" "):
            if Input == EndMark:
                return SInput.strip()
            else:
                SInput += Input + " "
    return SInput.strip()

def main():
    try:
        while True:
            status, TreeNodes, DataList, PathSet = True, [], [], set()
            SInput = readInput()
            # split Input
            for node in SInput.split(" "):
                # print(node)
                nodeParse = node[1:-1].split(",")
                if nodeParse[0] is "":
                    status = False
                    break
                Data, Path = nodeParse[0], nodeParse[1]
                # data or path repeat, cannot build a tree
                if Path in PathSet:
                    status = False
                else:
                    if Path is not "":
                        PathSet.add(Path)
                    DataList.append(Data)
                    TreeNodes.append([Data, Path])
            # path amount > node amount, cant build a tree
            if status is False or len(DataList) - len(PathSet) !=1 :
                print("not complete")
                continue
            # build up a tree
            root = newNode()
            for data, path in TreeNodes:
                addNode(root, data, path)
            # traversal tree
            ans = BFS(root)
            if ans is False:
                print("not complete")
            else:
                print(ans)
    except:
        pass
if __name__ == "__main__":
    main()
