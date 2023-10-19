function solution(n, wires) {
    var answer = -1;
    
    var minSum = 10000
    var min
    for(var i = 0;i<wires.length;i++){
        const graph = buildGraph(wires);
        const [node1, node2] = wires[i]
    graph[node1] = graph[node1].filter(neighbor => neighbor !== node2);
    graph[node2] = graph[node2].filter(neighbor => neighbor !== node1);

    const visited = {};

    const size1 = dfs(graph, node1, visited);
    const size2 = dfs(graph, node2, visited);

    
    if(Math.abs(size1-size2)<minSum){
        minSum=Math.abs(size1-size2)
        answer = minSum
        if(size1 === size2)
            return 0
        console.log(minSum, answer)
    }
    console.log(`Size of the first subtree: ${size1}`);
    console.log(`Size of the second subtree: ${size2}`);
    }
    console.log(answer)
    return answer;
}

function dfs(graph, node, visited) {
    visited[node] = true;
    let count = 1;

    for (const neighbor of graph[node]) {
        if (!visited[neighbor]) {
            count += dfs(graph, neighbor, visited);
        }
    }

    return count;
}



function buildGraph(edges) {
    const graph = {};

    edges.forEach(edge => {
        const [node1, node2] = edge;

        if (!graph[node1]) {
            graph[node1] = [];
        }
        if (!graph[node2]) {
            graph[node2] = [];
        }

        graph[node1].push(node2);
        graph[node2].push(node1);  // 양방향 그래프를 가정
    });

    return graph;
}