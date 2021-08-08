/**
 * @author afmika
 */

function makeNode (a) {
    return {
        y : a[0], x : a[1], // pos
        cost : 0, heur : 0, // cost and heuristic
        parent : null // parent
    }
}

function canGo (y, x, graph) {
    if (y < 0 || x < 0 || y >= graph.length || x >= graph[0].length)
        return false;
    return graph[y][x] == 0;
}

function neighborsOf (a, graph) {
    const dir = [
        [-1, 0], [1, 0], [0, 1], [0, -1], // horiz / vert
        [-1, -1], [1, 1], [1, -1], [-1, 1] // diag
    ];
    let list = [];
    for (let d of dir) {
        let [dy, dx] = d;
        let new_p = makeNode([a.y + dy, a.x + dx]);
        if (canGo(new_p.y, new_p.x, graph))
            list.push(new_p);
    }
    return list;
}

function distSq (a, b) {
    return (a.x - b.x)**2 + (a.y - b.y)**2;
}

function heuristic (a, b) {
    return distSq (a, b);
}

function nodeEqual (a, b) {
    return a.x == b.x && a.y == b.y;
}

function findNodeInList (a, list) {
    for (let it of list)
        if (nodeEqual(a, it))
            return true;
    return false;
}

function backtrackPath (end_node) {
    let path = '', started = true;
    while (end_node != null) {
        path = '[' + end_node.y + ', ' + end_node.x + ']'
                + (started ? '' : '=>') + path;
        started = false;
        end_node = end_node.parent;
    }
    return path;
}

function aStar (graph, _start, _end) {
    let closedList = [];
    let openList = [];

    let start = makeNode (_start);
    let end = makeNode (_end);
    openList.push(start);

    while (openList.length > 0) {
		openList = openList.sort((a, b) => a.heur - b.heur);
		console.log(openList.map(a => a.heur));
        let curr = openList.shift();
        if (nodeEqual(curr, end)) {
            console.log(backtrackPath(curr));
            console.log('HELL YEAH');
            return;
        }
        let neighb = neighborsOf (curr, graph);
        for (let nei of neighb) {
            let notInClosedList = !findNodeInList(nei, closedList);
            if (notInClosedList) {
                nei.cost = curr.cost + 1; // 1 dist 
                nei.heur = nei.cost +  heuristic (nei, end); // dist^2
                // --- useful when we want to backtrack the answer
                nei.parent = curr;
                // ---- 
                openList.push(nei);
            }
        }
        closedList.push(curr);
    }
    console.log("Impossible path");
}

const graph = [ 
    [ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 ],
    [ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 ],
    [ 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 ],
    [ 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 ],
    [ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 ],
    [ 0, 1, 0, 0, 0, 0, 1, 0, 1, 1 ],
    [ 0, 1, 1, 1, 1, 0, 1, 1, 1, 0 ],
    [ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 ],
    [ 0, 0, 0, 1, 1, 1, 0, 1, 1, 0 ]
];
const start = [8, 0];
const end = [0, 0];
console.log(aStar(graph, start, end));

// console.log(neighborsOf(makeNode([3, 9]), graph))