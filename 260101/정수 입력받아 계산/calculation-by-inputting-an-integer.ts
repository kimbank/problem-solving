import * as fs from 'fs';

function getNumber(): number {
    let tmp = fs.readFileSync(0).toString();
    return Number(tmp);
}

let a = getNumber();

console.log(a * 2 + 3);
