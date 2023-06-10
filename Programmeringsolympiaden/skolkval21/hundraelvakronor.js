const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.on('line', (line) => {
  let count = 0
  const amount = (a) => {
    if (a >= 111111111){
      count++
      amount(a - 111111111)
    } else if (a >= 11111111){
      count++
      amount(a - 11111111)
    } else if (a >= 1111111){
      count++
      amount(a - 1111111)
    } else if (a >= 111111){
      count++
      amount(a - 111111)
    } else if (a >= 11111){
      count++
      amount(a - 11111)
    } else if (a >= 1111){
      count++
      amount(a - 1111)
    } else if (a >= 111){
      count++
      amount(a - 111)
    } else if (a >= 11){
      count++
      amount(a - 11)
    } else if (a >= 1){
      count++
      amount(a - 1)
    } else if (a == 0){
      console.log(count)
    }
    
  }
  amount(line)
});
