const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.on('line', (line) => {
  let input = line.split('')
  let centuryInd = input[6]
  input.splice(6, 1)

  const fra = (a, b) => {
    input.unshift(a, b)
  }

  if (parseInt(input[0] + input[1]) < 20){
    if (centuryInd == '+'){
      fra('1', '9')
    } else {
      fra('2', '0')
    }
  } else {
    if (centuryInd == '+'){
      fra('1', '8')
    } else {
      fra('1', '9')
    }
  }
  console.log(input.join(''))
});
