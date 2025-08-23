const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split("\n");

const [n, m] = input[0].split(" ").map(Number);
const points = input.slice(1, 1 + n).map(line => line.split(" ").map(Number));

class Pair {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
}

const Heap = require("collections/heap");

const pointPairs = points.map(item => new Pair(item[0], item[1]));

const pq = new Heap(
    null,
    null,
    (a, b) => ((b.x ** 2) + (b.y ** 2)) - ((a.x ** 2) + (a.y ** 2))
);

// insert
for (let i = 0; i < n; i++) {
    pq.push(pointPairs[i]);
}

// find answer
for (let i = 0; i < n; i++) {
    // calc new X, Y
    const newX = pq.peek().x + 2;
    const newY = pq.peek().y + 2;

    // change peek
    pq.pop();
    pq.push(new Pair(newX, newY));
}

const bestP = pq.peek();
console.log(bestP.x, bestP.y);
