const fs = require("fs");
const Heap = require("collections/heap");
const input = fs.readFileSync(0).toString().trim().split('\n');

const n = Number(input[0]);
const arr = input.slice(1, 1 + n).map(Number);

// priority queue
const pq = new Heap(
    null,
    null,
    (a, b) => a - b
);

arr.forEach(k => {
    if (k == 0) { // remove best value
        pq.length == 0 ?
            console.log(0) :
            console.log(pq.pop());
    } else { // insert
        pq.push(k);
    }
});
