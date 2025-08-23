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


function cmp(a, b) {
  const sa = a.x + a.y;
  const sb = b.x + b.y;
  if (sa !== sb) return sb - sa; // x+y 작은 게 우선
  if (a.x !== b.x) return b.x - a.x; // x 작은 게 우선
  return b.y - a.y; // y 작은 게 우선
}
const pq = new Heap(null, null, cmp);

// insert
for (let i = 0; i < n; i++) {
    pq.push(pointPairs[i]);
}

// find answer
for (let i = 0; i < m; i++) {
  const cur = pq.pop();
  pq.push(new Pair(cur.x + 2, cur.y + 2));
}

const bestP = pq.peek();
console.log(bestP.x, bestP.y);
