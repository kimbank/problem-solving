const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split('\n');

const [n, m] = input[0].split(' ').map(Number);
const numbers = input[1].split(' ').map(Number);
const queries = input.slice(2, 2 + m).map(Number);

function findNum(target) {
    let low = 0;
    let high = n - 1;

    while (low <= high) {
        const mid = Math.floor((low + high) / 2);

        if (numbers[mid] === target) {
            return mid + 1; // 문제에서 1-based index를 요구한다고 가정
        }

        if (numbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

for (let i = 0; i < m; i++) {
    console.log(findNum(queries[i]));
}
