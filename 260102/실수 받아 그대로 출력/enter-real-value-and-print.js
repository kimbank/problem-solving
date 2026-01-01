const fs = require('fs');

let a = fs.readFileSync(0).toString();

a = Number(a) * 100;

a = Math.round(a) / 100;

console.log(a.toFixed(2));
