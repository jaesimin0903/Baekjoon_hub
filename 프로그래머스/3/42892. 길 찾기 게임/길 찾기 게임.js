function solution(nodeinfo) {
    var answer = [];
    var copy = [...nodeinfo]
    nodeinfo.sort((a,b)=>b[1]-a[1])
    console.log(nodeinfo)
    var tree = new BinaryTree()
    for(var i = 0;i<nodeinfo.length;i++){
        tree.insert(nodeinfo[i][0])
    }
    console.log(copy)
    answer.push(tree.preorderTraversal(tree.root))
    answer.push(tree.postorderTraversal(tree.root))
    
    for(var i =0;i<answer[0].length;i++){
        for(var j =0;j<copy.length;j++){
            if(answer[0][i] === copy[j][0]){
                
                answer[0][i] = j+1

                break
            }
        }
    }
    for(var i =0;i<answer[0].length;i++){
        for(var j =0;j<copy.length;j++){
            if(answer[1][i] === copy[j][0]){
                
                answer[1][i] = j+1
            
                break
            }
        }
    }
    return answer;
}

class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    constructor() {
        this.root = null;
    }

    insert(value) {
        const newNode = new TreeNode(value);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this._insertNode(this.root, newNode);
        }
    }

    _insertNode(node, newNode) {
        if (newNode.value < node.value) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this._insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this._insertNode(node.right, newNode);
            }
        }
    }

    inorderTraversal(node, result = []) {
        if (node !== null) {
            this.inorderTraversal(node.left, result);
            result.push(node.value);
            this.inorderTraversal(node.right, result);
        }
        return result;
    }

    preorderTraversal(node, result = []) {
        if (node !== null) {
            result.push(node.value);
            this.preorderTraversal(node.left, result);
            this.preorderTraversal(node.right, result);
        }
        return result;
    }

    postorderTraversal(node, result = []) {
        if (node !== null) {
            this.postorderTraversal(node.left, result);
            this.postorderTraversal(node.right, result);
            result.push(node.value);
        }
        return result;
    }
}